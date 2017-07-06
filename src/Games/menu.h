#ifndef MENU_H
#define MENU_H

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsView>
#include "recttext.h"
#include <QObject>

/**
 * @brief The GameMenuItem struct
 * data about a single item of the menu, holds the title
 * of this item, with the slot to call when the item
 * is selected
 */
struct GameMenuItem{
    QString title;
    const char* clickSlot;
};


class Menu : public QGraphicsItemGroup
{
public:
	/**
	 * @brief Menu
	 * Init the menu, add the items, sets the listeners
	 *
	 * @param parent parent to call when trigerring a slot
	 * @param header title of the menu
	 * @param actions list of all items to select in the menu
	 */
	Menu(QWidget *parent, QString header, QList<GameMenuItem> actions);

private:
	// Pointer to the parent to use when triggering the slot
	QWidget *parent_;

};

#endif // MENU_H
