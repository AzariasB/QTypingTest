#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QWidget>



class BounceMenu : public QWidget
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
	BounceMenu(QWidget *parent = 0);

signals:
	void playSelected();

	void helpSelected();

	void quitSelected();

private:

};

#endif // MENU_H
