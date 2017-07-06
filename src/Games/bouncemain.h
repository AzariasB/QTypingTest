#ifndef BOUNCEMAIN_H
#define BOUNCEMAIN_H

#include <QWidget>
#include <QStackedLayout>

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

private:
	QStackedLayout *mainLayout_;

	BounceMenu *menu_;

	BounceHelp *help_;

	BounceData *bData_;

	BounceGame *bGame_;
};

#endif // BOUNCEMAIN_H
