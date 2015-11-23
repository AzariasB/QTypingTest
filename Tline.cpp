
#include "Tline.h"

TLine::TLine(QString model, QWidget *parent) : QWidget(parent),
tLineLayout(new QVBoxLayout(this)),
edition(new QLineEdit(this)),
toCopy(new TLabel(model, this)),
globalAnswer(model) {
    this->setLayout(this->tLineLayout);
    this->connectEvents();
}

TLine::TLine(QString model) : QWidget(),
tLineLayout(new QVBoxLayout(this)),
edition(new QLineEdit(this)),
toCopy(new TLabel(model)),
globalAnswer(model) {
    edition->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    // Style just to make it clear that the widget is 
    // being resized to fit the parent, it doesn't "overflow"
    //    edition->setFrameShape(QFrame::Box);
    //    edition->setFrameShadow(QFrame::Raised);
    //    edition->setAlignment(Qt::AlignHCenter);
    this->edition->setContentsMargins(7, 0,7, 0);
    this->tLineLayout->setSpacing(0);
    this->tLineLayout->addWidget(this->toCopy);
    this->tLineLayout->addWidget(this->edition);
    this->setLayout(this->tLineLayout);
    this->connectEvents();
}

void TLine::connectEvents() {
    connect(this->edition, SIGNAL(textEdited(QString)), this, SLOT(typingAnswer(QString)));
    connect(this->edition, SIGNAL(selectionChanged()), this, SLOT(preventBadSelection()));
}

void TLine::typingAnswer(QString answer) {

    if (!answer.isEmpty() && answer != "\r") {
        this->toCopy->correctAnswer(answer);

        if (answer.size() > lastAnswer.size() && answer.at(answer.length() - 1) == ' ' && !this->toCopy->nextWord()) {
            emit endedLine(this->toCopy->getNbrErrors());
        }

    }
    if (answer.size() < lastAnswer.size() - 1) {
        answer = lastAnswer;
        edition->setText(lastAnswer);
    } else {
        lastAnswer = answer;
    }

}

void TLine::preventBadSelection() {
    int last = this->edition->text().size();
    if (edition->selectionStart() >= 0 && edition->selectionStart() < last - 1) {
        this->edition->setSelection(last, 0);
    }
}

void TLine::setFocus() {
    this->edition->setFocus();
}
