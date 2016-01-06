/* 
 * File:   TWindowTest.cpp
 * Author: boutina
 * 
 * Created on 10 novembre 2015, 12:03
 */


/*
 * Options :
 *  * From file (give filename)
 *  * From letter-list ... (jf + kd + ...) => random words
 *  * From possible letters => 
 *  * From String
 */

#include "twindowtest.h"

TWindowTest::TWindowTest(QString model, QWidget *parent ) :
QDialog(parent),
results_(QList<TResult*>()),
timer_(new QTimer()),
timeStart_(QTime(0, 0)),
stackWidget_(new QStackedWidget()),
centralLayout_(new QVBoxLayout()) {
    setupWidget(model);
}

TWindowTest::TWindowTest(TExercice *exercice, QWidget *parent) :
QDialog(parent),
results_(QList<TResult*>()),
timer_(new QTimer()),
timeStart_(QTime(0, 0)),
stackWidget_(new QStackedWidget()),
centralLayout_(new QVBoxLayout()) {
    QStringList exLetters = exercice->buildExercice();
    setupWidget(exLetters.join(""));
}

void TWindowTest::setupWidget(QString words) {
    timer_->setSingleShot(false);
    //Setup window
    this->setModal(true);
    this->setFocusPolicy(StrongFocus);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->move(0, 0);

    QStringList models = factory::splitText(words, this->numberOfPages_);


    createToolBar();
    createPages(models);
    setupShortcuts();

    this->setLayout(centralLayout_);

}

void TWindowTest::createToolBar() {
    QHBoxLayout *toolbarLayout = new QHBoxLayout();


    pageProgression_ = new QLabel(getPageProgression());

    pauseButton_ = new QPushButton(); //Change with an icon
    pauseButton_->setIcon(QIcon("etc/pause.png"));
    pauseButton_->setAutoDefault(false);
    pauseButton_->setFocusPolicy(FocusPolicy::NoFocus);
    //    pauseButton_->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    connect(pauseButton_, SIGNAL(clicked()), this, SLOT(pauseContinueExercice()));

    LCDtimer_ = new QLCDNumber();
    LCDtimer_->setSegmentStyle(QLCDNumber::Filled);

    QSpacerItem *space = new QSpacerItem(300, 0);


    toolbarLayout->addWidget(pageProgression_);
    toolbarLayout->addWidget(pauseButton_);
    toolbarLayout->addWidget(LCDtimer_);
    toolbarLayout->addItem(space);


    QWidget *w = new QWidget();


    w->setLayout(toolbarLayout);
    centralLayout_->addWidget(w);
}

QList<tln::TPage*> TWindowTest::createPages(QStringList model) {

    QList<tln::TPage*> lines;

    for (int i = 0; i < model.size(); i++) {
        tln::TPage *sLine = new tln::TPage(model[i]);
        connect(sLine, SIGNAL(endedPage(TResult*)), this, SLOT(nextPage(TResult*)));
        stackWidget_->addWidget(sLine);
        if (i > 0) {
            sLine->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
        } else if (i == 0) {
            connect(sLine, SIGNAL(startedPage()), this, SLOT(beginExercice()));
            sLine->updateAsFirst();
        }
        lines << sLine;
    }


    centralLayout_->addWidget(stackWidget_);
    return lines;
}




//Protected

void TWindowTest::keyPressEvent(QKeyEvent* ev) {
    if (!isInPause) {
        tln::TPage *page = static_cast<tln::TPage*> (stackWidget_->currentWidget());
        page->update(ev);
    }
}

/**
 * Please dialog, stop moving
 * when the text is changing !
 */
void TWindowTest::moveEvent(QMoveEvent *ev) {
    //    qDebug() << "moving !";
    ev->ignore();
    ev->setAccepted(false);
}

void TWindowTest::closeEvent(QCloseEvent* ev) {
    if (ev->isAccepted())
        exerciceFinished(true);
}


//Slots

void TWindowTest::nextPage(TResult* previousScore) {
    this->results_ << previousScore;

    stackWidget_->currentWidget()->setEnabled(false);
    this->currentPage_++;
    if (this->currentPage_ < stackWidget_->count()) {
        stackWidget_->setCurrentIndex(currentPage_);
        tln::TPage *nwPage = static_cast<tln::TPage*> (stackWidget_->currentWidget());

        nwPage->setEnabled(true);
        nwPage->setFocus();
        nwPage->updateAsFirst();
        pageProgression_->setText(getPageProgression());
    } else {//No more pages
        exerciceFinished();
    }
}

void TWindowTest::beginExercice() {
    this->timeStart_.start();
    timer_->start(1000);
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

void TWindowTest::updateTimer() {
    int incrVal = decrementTime_ ? -1 : 1;
    LCDtimer_->display(LCDtimer_->value() + incrVal);
    if(LCDtimer_->value() < 0.f){
        LCDtimer_->setPalette(red);
    }
}

TResult* TWindowTest::exerciceResult() {
    elapsedMS_ += this->timeStart_.elapsed();
    timeStart_ = QTime(0, 0).addMSecs(elapsedMS_);

    //Sum the results
    TResult *res = new TResult();
    for (auto it = results_.begin(); it != results_.end(); ++it) {
        *res += **it;
    }

    float mnElapsed = (float) timeStart_.msecsSinceStartOfDay() / (60.f * 1000.f);

    res->updateWPM(mnElapsed);

    return res;
}

void TWindowTest::pauseContinueExercice() {
    if (isInPause) {
        timeStart_.restart();
        timer_->start();
        pauseButton_->setIcon(QIcon("etc/pause.png"));
    } else {
        pauseButton_->setIcon(QIcon("etc/play.png"));
        timer_->stop();
        elapsedMS_ += timeStart_.elapsed();
    }
    isInPause = !isInPause;
}


//Private

void TWindowTest::exerciceFinished(bool forced) {
    timer_->stop();

    if (!forced) {
        TResult *tot = exerciceResult();
        emit endOfExercice(tot, timeStart_);
    } else {
        emit closed();
    }
}

void TWindowTest::setupShortcuts() {
    //Hacks

    //Hack for testing => shortucut to end the exercice
    QShortcut *endShortcut = new QShortcut(this);
    endShortcut->setKey(CTRL + Key_F);

    connect(endShortcut, &QShortcut::activated, [ = ](){
        if (results_.isEmpty()) {
            tln::TPage *curPage = static_cast<tln::TPage*> (stackWidget_->currentWidget());
                    this->results_.push_back(curPage->getResult());
        }
        exerciceFinished();
    });
    //end of hacks

    QShortcut *pauseSh = new QShortcut(this);
    pauseSh->setKey(CTRL + Key_P);
    connect(pauseSh, SIGNAL(activated()), this, SLOT(pauseContinueExercice()));
}

void TWindowTest::setTimers(int timeLimit) {
    if (timeLimit != -1) {
        decrementTime_ = true;
        timeLimit_ = timeLimit;
        LCDtimer_->display(timeLimit);
    }
}


//Destructor

TWindowTest::~TWindowTest() {
}

