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
stackWidget_(new QStackedWidget()) {
    setupWidget(model);
}

TWindowTest::TWindowTest(TExercice *exercice, QWidget *parent) :
QDialog(parent),
results_(QList<TResult*>()),
stackWidget_(new QStackedWidget()) {
    QStringList exLetters = exercice->buildExercice();
    setupWidget(exLetters.join(""));
}

void TWindowTest::setupWidget(QString words) {
    qDebug() << words << endl;
    //Setup window
    this->setModal(true);
    this->setFocusPolicy(StrongFocus);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->move(0, 0);

    //Hack for testing => shortucut to end the exercice
    QShortcut *sh = new QShortcut(this);
    sh->setKey(CTRL + Key_F);

    connect(sh, &QShortcut::activated, [ = ](){
        emit endOfExercice(resultsSum());
    });
    //end of hack


    QStringList models = factory::splitText(words, this->numberOfPages_);

    createPages(models);

    //    connect(pages_[0], SIGNAL(startedLine()), this, SLOT(beginExercice()));
}

QList<tln::TPage*> TWindowTest::createPages(QStringList model) {
    QVBoxLayout *centralLayout = new QVBoxLayout();

    QList<tln::TPage*> lines;

    for (int i = 0; i < model.size(); i++) {
        tln::TPage *sLine = new tln::TPage(model[i]);
        connect(sLine, SIGNAL(endedPage(TResult*)), this, SLOT(nextPage(TResult*)));
        stackWidget_->addWidget(sLine);
        if (i > 0) {
            sLine->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
        } else if (i == 0) {
            connect(sLine,SIGNAL(startedPage()),this,SLOT(beginExercice()));
            sLine->updateAsFirst();
        }
        lines << sLine;
    }

    centralLayout->addWidget(stackWidget_);
    this->setLayout(centralLayout);
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
        emit closed();
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
    } else {//No more pages
        int elapsedMS = this->timeStart_.elapsed();
        float mnElapsed = (float) elapsedMS / 60000.f; //Ms to minutes
        TResult *tot = resultsSum();
        tot->updateWPM(mnElapsed);
        emit endOfExercice(tot);
    }
}

void TWindowTest::beginExercice() {
    this->timeStart_.start();
}

TResult* TWindowTest::resultsSum() {
    TResult *res = new TResult();
    for (auto it = results_.begin(); it != results_.end(); ++it) {
        *res += **it;
    }
    return res;
}


//Destructor

TWindowTest::~TWindowTest() {
}

