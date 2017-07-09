/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bouncemain.h
 * Author: azarias
 *
 */

#ifndef BOUNCEMAIN_H
#define BOUNCEMAIN_H

#include <QWidget>
#include <QStackedLayout>
#include <QHBoxLayout>

#include "bouncemenu.h"
#include "bouncegame.h"
#include "bouncedata.h"
#include "bouncehelp.h"
#include "bouncescore.h"

class BounceMain : public QWidget
{
	Q_OBJECT
public:
	explicit BounceMain(QWidget *parent = 0);

signals:

public slots:
	void showGame();

	void showHelp();

	void showMenu();

	void showLeaderboard();

	void saveGameScore(int score, QTime time);

private:
	void initGameWidget();

	QStackedLayout *mainLayout_;

	BounceMenu *menu_;

	BounceHelp *help_;

	BounceData *bData_;

	BounceGame *bGame_;

	BounceScore *bScore_;

	QWidget *gameWidget_;
};

#endif // BOUNCEMAIN_H
