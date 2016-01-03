#ifndef TLINE_H
#define TLINE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>
#include <QValidator>
#include <QList>

#include "../../Data/tresult.h"
#include "../../Data/tkeys.h"
#include "../../Util/factory.h"
#include "tlabel.h"


namespace tln {

    class TPage : public QWidget {
        Q_OBJECT
    public:
        explicit TPage(QWidget *parent = 0);
        TPage(QString model, QWidget *parent);
        TPage(QString model);

        /**
         * Called by the parent dialog/Window whenever a key is pressed to
         * update the view and show the user where he is in the answer
         * 
         * @param ev the key event that the user triggerred
         */
        void update(QKeyEvent* ev);

        inline void updateAsFirst() {
            //            this->toCopy_->setFirst();
        }
    signals:
        /**
         * A Signal trigerred when the user typed the first character of the line
         */
        void startedPage();
    
    /**
     *  Signale trigerred when there is no more text to copy on the page
     */
    void endedPage(TResult*);

    public slots:
        void typingAnswer(QString answer);
        void eraseAnswer();

    private:
        /**
         * Put the elements on the widget
         */
        void setupPage();

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

        /**
         * Function to update the necessary models (staistics)
         * so that the user knows what's his worst key
         * 
         * If the previous key was wrong, the current key will not counted as mistype
         * since it can be because of the speed
         * 
         * @param userAnswer the character typed by the user wich is the wrong answer
         */
        void handleMistype(QChar userAnswer);


        //Attributes
        QVBoxLayout *tLineLayout_;
        //        QLineEdit *edition_;

        QList<TLabel*> toCopy_;

        QString globalAnswer_;
        QString lastAnswer_;
        TResult *lineRes_;

        bool started_ = false;

        //The number of lines/label
        const int numberOfLines_ = 4;

        int currentTLabel_ = 0;
    };
}

#endif // TLINE_H
