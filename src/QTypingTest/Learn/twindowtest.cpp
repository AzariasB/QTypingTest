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

TWindowTest::TWindowTest(QString model, QWidget *parent) :
QDialog(parent),
results_(QList<TResult*>()),
timer_(new QTimer()),
stackWidget_(new QStackedWidget()),
centralLayout_(new QVBoxLayout()) {
    setupWidget(model);
}

TWindowTest::TWindowTest(TExercice *exercice, QWidget *parent) :
QDialog(parent),
results_(QList<TResult*>()),
timer_(new QTimer()),
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

    //Hack for testing => shortucut to end the exercice
    QShortcut *sh = new QShortcut(this);
    sh->setKey(CTRL + Key_F);

    connect(sh, &QShortcut::activated, [ = ](){
        if (results_.isEmpty()) {
            tln::TPage *curPage = static_cast<tln::TPage*> (stackWidget_->currentWidget());
                    this->results_.push_back(curPage->getResult());
        }
        emit endOfExercice(exerciceResult());
    });
    //end of hack


    QStringList models = factory::splitText(words, this->numberOfPages_);


    createToolBar();
    createPages(models);

    //    connect(pages_[0], SIGNAL(startedLine()), this, SLOT(beginExercice()));    
    this->setLayout(centralLayout_);

}

void TWindowTest::createToolBar() {
    QHBoxLayout *toolbarLayout = new QHBoxLayout();


    pageProgression_ = new QLabel(getPageProgression());
    pauseButton_ = new QPushButton(); //Change with an icon
    pauseButton_->setIcon(QIcon("etc/pause.png"));
    pauseButton_->setAutoDefault(false);
    pauseButton_->setFocusPolicy(FocusPolicy::NoFocus);
    LCDtimer_ = new QLCDNumber();

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
    tln::TPage *page = static_cast<tln::TPage*> (stackWidget_->currentWidget());
    page->update(ev);
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
    LCDtimer_->display(LCDtimer_->value() + 1);
}

TResult* TWindowTest::exerciceResult() {
    //Sum the results
    TResult *res = new TResult();
    for (auto it = results_.begin(); it != results_.end(); ++it) {
        *res += **it;
    }
    int elapsedMS = this->timeStart_.elapsed();
    float mnElapsed = (float) elapsedMS / 60000.f; //Ms to minutes

    res->updateWPM(mnElapsed);

    return res;
}


//Private

QString TWindowTest::getPageProgression() {
    return QString("%1/%2").arg(currentPage_ + 1).arg(numberOfPages_);
}

void TWindowTest::exerciceFinished(bool forced) {
    timer_->stop();
    if (!forced) {
        TResult *tot = exerciceResult();
        emit endOfExercice(tot);
    } else {
        emit closed();
    }
}


//Destructor

TWindowTest::~TWindowTest() {
}

