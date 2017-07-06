

#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>

#include "menu.h"
#include "recttext.h"

Menu::Menu(QWidget *parent, QString header, QList<GameMenuItem> actions):
parent_(parent){
        int startY = parent->height()/3;
        int leftX = parent->width()/10;

	setHandlesChildEvents(false);
	qDebug() <<  parent->rect().width();
	RectText *hRect = new RectText(QRectF(leftX, startY,parent->width(), 50), header);
	hRect->getProperty(RectTextState::Default).font.setPixelSize(40);
	hRect->getProperty(RectTextState::Hovered).font.setPixelSize(40);
	addToGroup(hRect);

	int i = 1;
	foreach(GameMenuItem git, actions){
		RectText *nwText = new RectText(QRectF(leftX, startY + 50.f*i, parent->width(), 50), git.title);
		nwText->getProperty(RectTextState::Hovered).bgColor = QColor(Qt::red);
		QObject::connect(nwText, SIGNAL(mousePressed()), parent, git.clickSlot, Qt::DirectConnection );
		addToGroup(nwText);
		i++;
	}
}
