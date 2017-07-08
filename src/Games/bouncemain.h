#ifndef BOUNCEMAIN_H
#define BOUNCEMAIN_H

#include <QWidget>
#include <QStackedLayout>
#include <QHBoxLayout>

#include "bouncemenu.h"
#include "bouncegame.h"
#include "bouncedata.h"
#include "bouncehelp.h"

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

private:
	void initGameWidget();

	QStackedLayout *mainLayout_;

	BounceMenu *menu_;

	BounceHelp *help_;

	BounceData *bData_;

	BounceGame *bGame_;

	QWidget *gameWidget_;
};

#endif // BOUNCEMAIN_H
