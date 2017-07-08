#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QLabel>
#include <QWidget>

#include "menubutton.h"

class BounceMenu : public QWidget
{
	Q_OBJECT
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
	/**
	 * @brief playSelected
	 * When the "play" button is
	 * clicked/selected
	 */
	void playSelected();

	/**
	 * @brief helpSelected
	 * When the "help" button is
	 * clicked/selected
	 */
	void helpSelected();

	/**
	 * @brief quitSelected
	 * When the "quit" button is
	 * clicked/selected
	 */
	void quitSelected();

public slots:
	void selectionChanged(int nwSelection);


protected:
	void keyPressEvent(QKeyEvent *event) override;

private:

	int selectedButton_ = 0;

	QList<MenuButton*> buttons_;

};

#endif // MENU_H
