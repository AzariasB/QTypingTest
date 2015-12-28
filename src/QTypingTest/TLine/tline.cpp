


#include "tline.h"

tln::TLine::TLine(QString model, QWidget *parent) : QWidget(parent),
tLineLayout_(new QVBoxLayout(this)),
edition_(new QLineEdit(this)),
toCopy_(new TLabel(model, this)),
globalAnswer_(model),
lineRes_(new TResult()) {
    this->setLayout(this->tLineLayout_);
    this->connectEvents();
}

tln::TLine::TLine(QString model) : QWidget(),
tLineLayout_(new QVBoxLayout(this)),
edition_(new QLineEdit(this)),
toCopy_(new TLabel(model)),
globalAnswer_(model),
lineRes_(new TResult()) {
    edition_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    // Style just to make it clear that the widget is 
    // being resized to fit the parent, it doesn't "overflow"
    //    edition->setFrameShape(QFrame::Box);
    //    edition->setFrameShadow(QFrame::Raised);
    //    edition->setAlignment(Qt::AlignHCenter);
    this->edition_->setContentsMargins(7, 0, 7, 0);
    this->tLineLayout_->setSpacing(0);
    this->tLineLayout_->addWidget(this->toCopy_);
    this->tLineLayout_->addWidget(this->edition_);
    this->setLayout(this->tLineLayout_);
    this->connectEvents();
}

void tln::TLine::connectEvents() {
    connect(this->edition_, SIGNAL(textEdited(QString)), this, SLOT(typingAnswer(QString)));
    connect(this->edition_, SIGNAL(selectionChanged()), this, SLOT(preventBadSelection()));
}

void tln::TLine::typingAnswer(QString answer) {
    if (!started_) {
        started_ = true;
        emit startedLine();
    }

    if (!answer.isEmpty() && answer != "\r") {
        bool isTheSame = toCopy_->updateLabelColor(answer);

        if (answer.size() > lastAnswer_.size() && answer.at(answer.length() - 1) == ' ') {
            if (answer.length() >= 2 && answer.at(answer.length() - 2) == ' ') {
                edition_->setText(answer.left(answer.length() - 1));
                return; //Avoid 'double space'
            }

            QString lastWord = toCopy_->getCurrentWord();
            if (isTheSame) {
                lineRes_->incrCorrectKeystrokes(lastWord.size() + 1);
            } else {
                lineRes_->incrWrongKeyStrokes(lastWord.size() + 1);
            }
            if (!this->toCopy_->nextWord()) {
                emit endedLine(this->lineRes_);
            }
        }

    }

    if (answer.size() < lastAnswer_.size() - 1) {
        answer = lastAnswer_;
        edition_->setText(lastAnswer_);
    } else {
        lastAnswer_ = answer;
    }

}

void tln::TLine::preventBadSelection() {
    int last = this->edition_->text().size();
    if (edition_->selectionStart() >= 0 && edition_->selectionStart() < last - 1) {
        this->edition_->setSelection(last, 0);
    }
}

void tln::TLine::setFocus() {
    this->edition_->setFocus();
}