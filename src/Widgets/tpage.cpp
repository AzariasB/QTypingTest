
/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */

#include "tpage.h"

TPage::TPage(QString model, QWidget *parent) : QWidget(parent),
tLineLayout_(new QVBoxLayout(this)),
toCopy_(QList<TLabel*>()),
globalAnswer_(model),
lastAnswer_(QString()),
lineRes_(new TResult()) {
    this->setupPage();
}

TPage::TPage(QString model) : QWidget(),
tLineLayout_(new QVBoxLayout(this)),
toCopy_(QList<TLabel*>()),
globalAnswer_(model),
lastAnswer_(QString()),
lineRes_(new TResult()) {
    this->setLayout(this->tLineLayout_);
    this->setupPage();
}

void TPage::setupPage() {
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    //Devide the model into equals parts and create n Tlabels
    QStringList lines = factory::splitText(globalAnswer_, numberOfLines_);

    for (int i = 0; i < lines.size(); i++) {;
        QString endSpace = (i == lines.size() -1 ? "" : " ");
        TLabel *label = new TLabel(lines[i]+ endSpace);
        tLineLayout_->addWidget(label);
        if (i > 0) {
            label->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
        } else if (i == 0) {
            //Connect start
            label->setFirst();
        }
        toCopy_ << label;
    }

}

bool TPage::typingAnswer(QString answer)
{
    if (!started_) {
        started_ = true;
        emit startedPage();
    }

    bool nextChar = true;

    TLabel *curLabel = toCopy_[currentTLabel_];

    bool sameChar = answer.size() == 1 && answer[0] == globalAnswer_[lastAnswer_.size()];
    if (!sameChar)
    {
        if(answer.size() == 1)
        {
            handleMistype(answer[answer.size() - 1]);
            lineRes_->incrWrongKeyStrokes();
        }
    }
    else
    {
        lastAnswer_ += answer;
        cursorPosition_++;
        lineRes_->incrCorrectKeystrokes();
    }

    if(answer.size() == 1) //When a single char is typed
    {//Try to move the cursor
        nextChar = curLabel->nextChar(sameChar);
    }

     if (cursorPosition_ == curLabel->text().size() ) {//Next line
         cursorPosition_ = 0;
        if (currentTLabel_ == toCopy_.size() - 1) {
            emit endedPage(this->lineRes_);
        } else {
            curLabel->setEnabled(false);
            currentTLabel_++;
            toCopy_[currentTLabel_]->setEnabled(true);
            toCopy_[currentTLabel_]->setFirst();
        }
    }
    return sameChar;
}

void TPage::handleMistype(QChar userAns, bool previousWasRight) {
    if (lastAnswer_.size() > 1) {
        previousWasRight = globalAnswer_[lastAnswer_.size() - 2] == lastAnswer_[lastAnswer_.size() - 2];
    }

    if (previousWasRight && TUserManager::getInstance().getCurrentUser()) {
        TUserManager::getInstance().getCurrentUser()->oneMoreMistake(userAns);
    }
}

void TPage::eraseAnswer() {
    bool prevChar = label()->previousChar();
    if (prevChar || currentTLabel_ > 0) {
        lastAnswer_ = lastAnswer_.mid(0, lastAnswer_.size() - 1);
        if (!prevChar) {
            label()->setEnabled(false);
            currentTLabel_--;
            label()->setEnabled(true);
            label()->previousChar();
        }
    } else {
        emit eraseOverflow();
    }
}

bool TPage::isValidKey(QKeyEvent* ev)
{
    return !ev->text().isEmpty() && !ev->text().isNull() && ev->key() != Qt::Key_Backspace ;
}

void TPage::updateLine(QString answer)
{
    if(!answer.isEmpty()){
        typingAnswer(answer);
    }
}

TPage::~TPage()
{
    delete lineRes_;
}