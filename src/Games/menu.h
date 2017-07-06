#ifndef MENU_H
#define MENU_H

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsView>
#include "recttext.h"
#include <QObject>

struct GameMenuItem{
    QString title;
    const char* clickSlot;
};


class Menu : public QGraphicsItemGroup
{
public:
	Menu(QWidget *parent, QString header, QList<GameMenuItem> actions);

private:
	QWidget *parent_;

};

#endif // MENU_H
