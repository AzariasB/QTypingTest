/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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

#include "Data/tresult.h"
#include "Data/texercise.h"
#include "Util/factory.h"

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

    mainWidget->setLayout(centralLayout);
    mainLayout_->insertWidget(0,mainWidget);
    setLayout(mainLayout_);
    setupShortcuts();
    connectEvents();
    setupTimer();

    //Center on screen
    QRect src = QApplication::desktop()->screenGeometry();
    move(src.center() - rect().center());

    //Prevent size changes
    setAttribute(Qt::WA_DontShowOnScreen);
    show();
    setFixedSize(size());
    hide();
    setAttribute(Qt::WA_DontShowOnScreen,false);
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
        exerciseFinished(true);
}

void TWindowTest::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() != Qt::Key_Escape){
        QDialog::keyPressEvent(ev);
    }else{
        ev->setAccepted(false);
        this->pauseContinueExercise();
    }
}

void TWindowTest::setupTimer() {
	updateTimer_.setSingleShot(false);
	updateTimer_.setInterval(1000);
	connect(&updateTimer_, SIGNAL(timeout()), this, SLOT(updateClock()));
}


//Slots

void TWindowTest::saveResult(const TResult &previousScore)
{
    results_.append(previousScore);
}

void TWindowTest::beginExercise() {
    started_ = true;
    timeStart_.start();
	updateTimer_.start();
}

TResult TWindowTest::exerciseResult() {
    elapsedMS_ += this->timeStart_.elapsed();
    timeStart_ = QTime(0, 0).addMSecs(elapsedMS_);

    //Sum the results
	TResult res;
    for(const TResult &it : results_)res += it;

    float mnElapsed = (float) timeStart_.msecsSinceStartOfDay() / (60.f * 1000.f);

	res.updateWPM(mnElapsed);

    return res;
}

void TWindowTest::pauseContinueExercise() {
    paused_ = !paused_;
    edit_.setEnabled(!paused_);
    if (paused_) {
		updateTimer_.stop();
        timeStart_.restart();
    } else  {
        edit_.setFocus();
        if(started_){
			updateTimer_.start();
            elapsedMS_ += timeStart_.elapsed();
        }
    }
}


//Private

void TWindowTest::exerciseFinished(bool forced) {
    if (!forced) {
		TResult tot = exerciseResult();
		exercise_.completed(tot);
		if(um_.isUserConnected()){
			um_.getCurrentUser().addResult(exercise_);
        }
		emit endOfExercise(exercise_.getResult(), timeStart_);
    } else {
        emit closed();
    }
}

void TWindowTest::setupShortcuts() {
    //Hacks

//#ifdef QDEBUG_H
//    //Hack for testing => shortucut to end the exercise
//	QShortcut endShortcut(this);
//	endShortcut.setKey(Qt::CTRL + Qt::Key_F);

//	connect(&endShortcut, &QShortcut::activated, [ = ](){
//        if (results_.isEmpty()) {
//            //TPage *curPage = static_cast<TPage*> (pages_.currentWidget());
//            this->results_.push_back(pages_.currentPage()->getResult());
//        }
//        exerciseFinished();
//    });
//    //end of hacks

//	QShortcut allShortcut(this);
//	allShortcut.setKey(Qt::CTRL + Qt::Key_A);

//	connect(&allShortcut, &QShortcut::activated, [=] (){
//        qWarning() << "Unlocking the learning";
//		if(um_.isUserConnected()){
//			um_.getCurrentUser().getProgression()->avdvanceExIndex();
//		}
//    });
//#endif

	QShortcut pauseSh(this);
	pauseSh.setKey(Qt::CTRL + Qt::Key_P);
	connect(&pauseSh, SIGNAL(activated()), this, SLOT(pauseContinueExercise()));
}

void TWindowTest::connectEvents() {
    auto thePages = pages_.objectName();
    connect(&pages_, &TStackPages::textFinished, this, [thePages, this] {
        this->exerciseFinished(false);
    });
    connect(&pages_, &TStackPages::pageEnded, this, &TWindowTest::saveResult);
    connect(&pages_, &TStackPages::currentChanged, this, &TWindowTest::updateToolbarProgression);
    connect(&pages_, SIGNAL(exerciseStarted()), this, SLOT(beginExercise()));
    connect(&topToolbar_, SIGNAL(pauseClicked()), this, SLOT(pauseContinueExercise()));
    connect(&edit_,SIGNAL(textEdited(QString)),this,SLOT(answerTyped(QString)));
}

void TWindowTest::answerTyped(const QString &nwAnswer)
{
    if(pages_.answerTyped(nwAnswer))
    {
        edit_.setText("");
    }
}

//Destructor

TWindowTest::~TWindowTest() {

}

