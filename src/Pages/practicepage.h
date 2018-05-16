/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   PracticePage.h
 * Author: boutina
 *
 * Created on 6 janvier 2016, 10:15
 */

#ifndef PRACTICEPAGE_H
#define PRACTICEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QTime>


class TWindowTest;
class TPracticeBase;
class TPracticeRace;
class TPracticeText;
class TImprove;
class TResult;
class TUser;
class TUserManager;

class PracticePage : public QWidget {
    Q_OBJECT
public:
    PracticePage(QWidget *parent = 0);
    PracticePage(const PracticePage& orig);

    virtual ~PracticePage() {
    };

public slots:
    /* Start a practice against time */
    void startExercise(TWindowTest *exercise);

    /* Save the result and the time at the end of each exercise */
    void saveExerciseResult(TResult &res, const QTime &time);

    /* Reset the dialog (disconnect and set to null) */
    void resetExercise();
    
    /**
     * Called whenever the user changes, or
     * when the user finished an exercise (and has some new errors)
     * to update the button 'improve'
     */    
	void updateImproveButton(TUser &nwUser);
    
    /**
     */
	void userChanges(TUser &nwUser);

	/**
	 * @brief userDisconnects
	 * Called when user disconnects
	 */
	void userDisconnects();

private:
    /* Setup the widget on the page */
    void setupLayout();

    /* Connect the events of each button */
    void connectEvents();

    /*Button to acces an exercise against the time*/
    QPushButton practiceAgainstTime_;

    /* To access the 'default' exercise */
    QPushButton practiceDefault_;

    /* Improve the keys where the user makes the most mistakes */
    QPushButton practiceImprove_;

    /* Practice on a text */
    QPushButton practiceText_;

    /* Dialog of the exercise */
    QDialog *currentDialog_ = nullptr;

	/* Reference to the user manager */
	TUserManager &um;
};

#endif /* PRACTICEPAGE_H */

