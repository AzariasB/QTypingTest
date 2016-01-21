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
    QVBoxLayout *centralLayout = new QVBoxLayout();

    centralLayout->addWidget(&topToolbar_);
    centralLayout->addWidget(&pages_);
    setLayout(centralLayout);
    //Setup window
    this->setModal(true);
    this->setFocusPolicy(StrongFocus);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->move(0, 0);

    setupShortcuts();

}

//Protected

void TWindowTest::keyPressEvent(QKeyEvent* ev) {
    TPage *page = pages_.currentPage();
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

}

void TWindowTest::beginExercice() {
    this->timeStart_.start();
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

void TWindowTest::pauseContinueExercice(bool pause) {
    if (pause) {
        timeStart_.restart();
    } else {
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
    endShortcut->setKey(CTRL + Key_F);

    connect(endShortcut, &QShortcut::activated, [ = ](){
        if (results_.isEmpty()) {
            //TPage *curPage = static_cast<TPage*> (pages_.currentWidget());
            this->results_.push_back(pages_.currentPage()->getResult());
        }
        exerciceFinished();
    });
    //end of hacks

    QShortcut *pauseSh = new QShortcut(this);
    pauseSh->setKey(CTRL + Key_P);
    connect(pauseSh, SIGNAL(activated()), this, SLOT(pauseContinueExercice()));
}


//Destructor

TWindowTest::~TWindowTest() {
}

