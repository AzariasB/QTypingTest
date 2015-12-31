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

        /**
         * Called by the parent dialog/Window whenever a key is pressed to
         * update the view and show the user where he is in the answer
         * 
         * @param ev the key event that the user triggerred
         */
        void update(QKeyEvent* ev);


    signals:

        /**
         * A signal trigerred when the user typed the last letter of the line
         * 
         * @param lineResult restul realised by the user at the end of the line
         */
        void endedLine(TResult *lineResult);

        /**
         * A Signal trigerred when the user typed the first character of the line
         */
        void startedLine();
        
        /**
         * A signale trigerred when the user tries to erase whenever he's at the
         * start of the line
         */
        void eraseOverflow();


    public slots:
        void typingAnswer(QString answer);
        void eraseAnswer();

    private:
        /**
         * Connect all the needed events of the line
         */
        void connectEvents();

        /**
         * Function to determine if the keypress event is valid (usable)
         * if it produces whatever letter (and is not a special char such as '\n'
         * 
         * @return if the key event can be seen as a 'valid' key event 
         */
        bool isValidKey(QKeyEvent *ev);
            
        /**
         * Function to calculate the total score realised by the user at the end of his line
         * It is calculated from the differences between the solution and 
         * the user given by the user
         * 
         * Both the answer and the solution must have the same length
         */
        void updateResult();


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
