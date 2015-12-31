


#include "tline.h"

tln::TLine::TLine(QString model, QWidget *parent) : QWidget(parent),
tLineLayout_(new QVBoxLayout(this)),
toCopy_(new TLabel(model, this)),
globalAnswer_(model),
lastAnswer_(QString()),
lineRes_(new TResult()) {
    this->setLayout(this->tLineLayout_);
    this->connectEvents();
}

tln::TLine::TLine(QString model) : QWidget(),
tLineLayout_(new QVBoxLayout(this)),
toCopy_(new TLabel(model)),
globalAnswer_(model),
lastAnswer_(QString()),
lineRes_(new TResult()) {
    // Style just to make it clear that the widget is 
    // being resized to fit the parent, it doesn't "overflow"
    //    edition->setFrameShape(QFrame::Box);
    //    edition->setFrameShadow(QFrame::Raised);
    //    edition->setAlignment(Qt::AlignHCenter);
    this->tLineLayout_->addWidget(this->toCopy_);
    this->setLayout(this->tLineLayout_);
    this->connectEvents();
}

void tln::TLine::connectEvents() {
    //No event for now
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void tln::TLine::typingAnswer(QString answer) {
    if (!started_) {
        started_ = true;
        emit startedLine();
    }

    lastAnswer_ += answer;

    bool nextChar = toCopy_->nextChar(answer[answer.size() - 1] == globalAnswer_[lastAnswer_.size() - 1]);

    if (!nextChar) {
        emit endedLine(this->lineRes_);
    }

}

void tln::TLine::eraseAnswer() {
    if (toCopy_->previousChar())
        lastAnswer_ = lastAnswer_.mid(0, lastAnswer_.size() - 1);
}

bool tln::TLine::isValidKey(QKeyEvent* ev) {

    return !ev->text().isEmpty() && !ev->text().isNull() &&
            TKeys::isValidLetter(ev->key());
}

void tln::TLine::setFocus() {

}

void tln::TLine::update(QKeyEvent* ev) {
    if (isValidKey(ev)) {
        typingAnswer(ev->text());
    } else if (ev->key() == Key_Backspace) {
        eraseAnswer();
    }
}
