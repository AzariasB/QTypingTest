


#include "tline.h"

tln::TLine::TLine(QString model, QWidget *parent) : QWidget(parent),
tLineLayout_(new QVBoxLayout(this)),
toCopy_(new TLabel(model, this)),
globalAnswer_(model),
lineRes_(new TResult()) {
    this->setLayout(this->tLineLayout_);
    this->setFocusPolicy(StrongFocus);
    this->connectEvents();
}

tln::TLine::TLine(QString model) : QWidget(),
tLineLayout_(new QVBoxLayout(this)),
toCopy_(new TLabel(model)),
globalAnswer_(model),
lineRes_(new TResult()) {
    // Style just to make it clear that the widget is 
    // being resized to fit the parent, it doesn't "overflow"
    //    edition->setFrameShape(QFrame::Box);
    //    edition->setFrameShadow(QFrame::Raised);
    //    edition->setAlignment(Qt::AlignHCenter);
    this->tLineLayout_->setSpacing(0);
    this->tLineLayout_->addWidget(this->toCopy_);
    this->setFocusPolicy(StrongFocus);
    this->setLayout(this->tLineLayout_);
    this->connectEvents();
}

void tln::TLine::connectEvents() {
    //No event for now
}

void tln::TLine::typingAnswer(QString answer) {
    if (!started_) {
        started_ = true;
        emit startedLine();
    }

    lastAnswer_ += answer;

    bool isTheSame = toCopy_->updateLabelColor(lastAnswer_);

    QString lastWord = toCopy_->getCurrentWord();
    if (isTheSame) {
        lineRes_->incrCorrectKeystrokes(lastWord.size() + 1);
    } else {
        lineRes_->incrWrongKeyStrokes(lastWord.size() + 1);
    }

    if (answer[answer.size()-1] == ' ' && !this->toCopy_->nextWord()) {
        emit endedLine(this->lineRes_);
    }

}

void tln::TLine::eraseAnswer() {
    lastAnswer_ = lastAnswer_.mid(0,lastAnswer_.size()-1);
    toCopy_->updateLabelColor(lastAnswer_);
}

void tln::TLine::keyPressEvent(QKeyEvent *ev) {
    if (isValidKey(ev)) {
        typingAnswer(ev->text());
    } else if (ev->key() == Key_Backspace) {
        eraseAnswer();
    }else{
        qDebug() << ev->key() << " - " << Key_Backspace;
    }
}

bool tln::TLine::isValidKey(QKeyEvent* ev) {

    return !ev->text().isEmpty() && !ev->text().isNull() &&
            TKeys::isValidLetter(ev->key());
}

void tln::TLine::setFocus() {

}