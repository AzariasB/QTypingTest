#ifndef TLINE_H
#define TLINE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>
#include <QValidator>
#include "TLabel.h"
#include "TLineEdit.h"

class TLine : public QWidget {
    Q_OBJECT
public:
    explicit TLine(QWidget *parent = 0);
    TLine(QString model, QWidget *parent);
    TLine(QString model);
    void setFocus();

private:
    //Functions
    void connectEvents();

    //Attributes
    QVBoxLayout *tLineLayout;
    QLineEdit *edition;
    TLabel *toCopy;
    QString globalAnswer;
    QString lastAnswer;

signals:
void endedLine(int nbrErrors); //TODO : replace nbrErrors by 'precision' object


public slots:
    void typingAnswer(QString answer);
    void preventBadSelection();
};

#endif // TLINE_H
