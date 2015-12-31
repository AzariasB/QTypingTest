#ifndef TLINE_H
#define TLINE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>
#include <QValidator>

#include "../../Data/tresult.h"
#include "../../Data/tkeys.h"
#include "tlabel.h"
#include "tlineedit.h"


namespace tln {

    class TLine : public QWidget {
        Q_OBJECT
    public:
        explicit TLine(QWidget *parent = 0);
        TLine(QString model, QWidget *parent);
        TLine(QString model);
        void setFocus();
        
        void update(QKeyEvent* ev);


    signals:
        void endedLine(TResult *lineResult);
        void startedLine();


    public slots:
        void typingAnswer(QString answer);
        void eraseAnswer();

    private:
        //Functions
        void connectEvents();
        
        /**
         * Function to determine if the keypress event is valid (usable)
         * if it produces whatever letter (and is not a special char such as '\n'
         * 
         * @return if the key event can be seen as a 'valid' key event 
         */
        bool isValidKey(QKeyEvent *ev);

        //Attributes
        QVBoxLayout *tLineLayout_;
        //        QLineEdit *edition_;
        TLabel *toCopy_;
        
        QString globalAnswer_;
        QString lastAnswer_;
        TResult *lineRes_;

        bool started_ = false;
    };
}

#endif // TLINE_H
