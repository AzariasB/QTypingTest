#ifndef TLINE_H
#define TLINE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>
#include <QValidator>

#include "TResult.h"
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
    TResult *lineRes;
    
    bool started = false;

signals:
void endedLine(TResult *lineResult); 
void startedLine();


public slots:
    void typingAnswer(QString answer);
    void preventBadSelection();
};

#endif // TLINE_H
