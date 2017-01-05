/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
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


void TWindowTest::setupWidget() {
    QWidget *mainWidget = new QWidget();
    QVBoxLayout *centralLayout = new QVBoxLayout();

    topToolbar_.setProgression(getPageProgression());

    QFont lineEditFont = edit_.font();
    lineEditFont.setPointSize(16);
    lineEditFont.setFamily("Monospace");
    edit_.setFont(lineEditFont);
    centralLayout->addWidget(&topToolbar_);
    centralLayout->addWidget(&pages_);
    centralLayout->addWidget(&edit_);

    //Setup window
    this->setModal(true);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mainWidget->setLayout(centralLayout);
    mainLayout_->insertWidget(0,mainWidget);
    setLayout(mainLayout_);
    setupShortcuts();
    connectEvents();
    setupTimer();

    //Center on screen
    QRect src = QApplication::desktop()->screenGeometry();
    move(src.center() - rect().center());
}

//Protected
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

void TWindowTest::setupTimer() {
    updateTimer_->setSingleShot(false);
    updateTimer_->setInterval(1000);
    connect(updateTimer_, SIGNAL(timeout()), this, SLOT(updateClock()));
}


//Slots

void TWindowTest::saveResult(TResult* previousScore)
{
    this->results_ << previousScore;

}

void TWindowTest::beginExercice() {
    timeStart_.start();
    updateTimer_->start();
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
    paused_ = !paused_;
    if (paused_) {
        updateTimer_->stop();
        timeStart_.restart();
    } else {
        updateTimer_->start();
        elapsedMS_ += timeStart_.elapsed();
    }
}


//Private

void TWindowTest::exerciceFinished(bool forced) {
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
    endShortcut->setKey(Qt::CTRL + Qt::Key_F);

    connect(endShortcut, &QShortcut::activated, [ = ](){
        if (results_.isEmpty()) {
            //TPage *curPage = static_cast<TPage*> (pages_.currentWidget());
            this->results_.push_back(pages_.currentPage()->getResult());
        }
        exerciceFinished();
    });
    //end of hacks

    QShortcut *pauseSh = new QShortcut(this);
    pauseSh->setKey(Qt::CTRL + Qt::Key_P);
    connect(pauseSh, SIGNAL(activated()), this, SLOT(pauseContinueExercice()));
}

void TWindowTest::connectEvents() {
    auto thePages = pages_.objectName();
    connect(&pages_, &TStackPages::textFinished, this, [thePages, this] {
        this->exerciceFinished(false);
    });
    connect(&pages_, &TStackPages::pageEnded, this, &TWindowTest::saveResult);
    connect(&pages_, &TStackPages::currentChanged, this, &TWindowTest::updateToolbarProgression);
    connect(&pages_, SIGNAL(exerciceStarted()), this, SLOT(beginExercice()));
    connect(&topToolbar_, SIGNAL(pauseClicked()), this, SLOT(pauseContinueExercice()));
    connect(&edit_,SIGNAL(textEdited(QString)),this,SLOT(answerTyped(QString)));
}

void TWindowTest::answerTyped(QString nwAnswer)
{
    if(pages_.answerTyped(nwAnswer))
    {
        edit_.setText("");
    }
}

//Destructor

TWindowTest::~TWindowTest() {
}

