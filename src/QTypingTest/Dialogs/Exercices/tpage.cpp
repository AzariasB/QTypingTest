


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


    for (int i = 0; i < lines.size(); i++) {
        TLabel *label = new TLabel(lines[i] + " ");
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

void TPage::typingAnswer(QString answer) {
    if (!started_) {
        started_ = true;
        emit startedPage();
    }

    TLabel *curLabel = toCopy_[currentTLabel_];
    lastAnswer_ += answer;

    bool sameChar = answer[answer.size() - 1] == globalAnswer_[lastAnswer_.size() - 1];

    if (!sameChar) {
        handleMistype(answer[answer.size() - 1]);
    }

    bool nextChar = curLabel->nextChar(sameChar);

    if (!nextChar) {//Next line
        if (currentTLabel_ == toCopy_.size() - 1) {
            this->updateResult();
            emit endedPage(this->lineRes_);
        } else {
            curLabel->setEnabled(false);
            currentTLabel_++;
            toCopy_[currentTLabel_]->setEnabled(true);
            toCopy_[currentTLabel_]->setFirst();
        }
    }

}

void TPage::handleMistype(QChar userAns) {
    bool previousWasRight = true;
    if (lastAnswer_.size() > 1) {
        previousWasRight = globalAnswer_[lastAnswer_.size() - 2] == lastAnswer_[lastAnswer_.size() - 2];
    }

    if (previousWasRight) {
       // THomePage::currentUser_->oneMoreMistake(userAns);
        //here, update user informations
    }
}

void TPage::eraseAnswer() {
    //TODO : find a better way to write that down ... 
    if (toCopy_[currentTLabel_]->previousChar())
        lastAnswer_ = lastAnswer_.mid(0, lastAnswer_.size() - 1);
    else if (currentTLabel_ > 0) {
        lastAnswer_ = lastAnswer_.mid(0, lastAnswer_.size() - 1);
        toCopy_[currentTLabel_]->setEnabled(false);
        currentTLabel_--;
        toCopy_[currentTLabel_]->setEnabled(true);
        toCopy_[currentTLabel_]->previousChar();
    }
    //Else : could emit 'eraseOverflow'
}

bool TPage::isValidKey(QKeyEvent* ev) {

    return !ev->text().isEmpty() && !ev->text().isNull() &&
            TKeys::isValidLetter(ev->key());
}

void TPage::update(QKeyEvent* ev) {
    if (isValidKey(ev)) {
        typingAnswer(ev->text());
    } else if (ev->key() == Key_Backspace) {
        eraseAnswer();
    }
}

void TPage::updateResult() {
    int correctKeyStrokes = 0;
    int wrongKeyStrokes = 0;
    for (int i = 0; i < lastAnswer_.size() && i < globalAnswer_.size(); i++) {
        if (lastAnswer_[i] != globalAnswer_[i])
            wrongKeyStrokes++;
        else
            correctKeyStrokes++;
    }
    lineRes_->setCorrectKeysStrokes(correctKeyStrokes);
    lineRes_->setWrongKeysStrokes(wrongKeyStrokes);
}
