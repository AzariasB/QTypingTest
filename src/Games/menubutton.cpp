
#include "menubutton.h"
#include <QPaintEvent>
#include <QPainter>

MenuButton::MenuButton()
{
}


MenuButton::MenuButton(const QString &text)
	:QPushButton(text)
{

}

void MenuButton::enterEvent(QEvent *event)
{
	Q_UNUSED(event);
	isSelected_ = true;
	emit hovered();
}


void MenuButton::paintEvent(QPaintEvent *event)
{
	QPushButton::paintEvent(event);

	if(isSelected_){
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setBrush(QBrush(QColor(Qt::black)));
		painter.drawText(0,0,50,height() - 5,Qt::AlignVCenter | Qt::AlignHCenter, "▶");
		painter.drawText(width() - 50,0,50,height() - 5,Qt::AlignVCenter | Qt::AlignHCenter, "◀");
	}
}

void MenuButton::setIsSelected(bool isSelected)
{
	isSelected_ = isSelected;
	update();
}

bool MenuButton::isSelected()
{
	return isSelected_;
}
