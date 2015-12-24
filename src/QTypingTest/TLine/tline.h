#ifndef TLINE_H
#define TLINE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>
#include <QValidator>

#include "../../Data/tresult.h"
#include "tlabel.h"
#include "tlineedit.h"

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
    QVBoxLayout *tLineLayout_;
    QLineEdit *edition_;
    TLabel *toCopy_;
    QString globalAnswer_;
    QString lastAnswer_;
    TResult *lineRes_;
    
    bool started_ = false;

signals:
void endedLine(TResult *lineResult); 
void startedLine();


public slots:
    void typingAnswer(QString answer);
    void preventBadSelection();
};

#endif // TLINE_H
