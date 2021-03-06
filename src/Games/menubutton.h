/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   menubutton.h
 * Author: azarias
 *
 */

#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>

class MenuButton : public QPushButton
{
	Q_OBJECT
public:
	MenuButton();

	MenuButton(const QString &text);

	void setIsSelected(bool isSelected);

	bool isSelected();

signals:
	void hovered();

protected:
	void enterEvent(QEvent *event) override;

	void paintEvent(QPaintEvent *event) override;

private:

	bool isSelected_ = false;
};

#endif // MENUBUTTON_H
