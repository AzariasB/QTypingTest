

#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>

#include "menu.h"
#include "recttext.h"

Menu::Menu(QWidget *parent, QString header, QMap<QString, const char *> actions):
parent_(parent){
        int startY = parent->height()/3;
        int leftX = parent->width()/10;

	setHandlesChildEvents(false);
        qDebug() <<  parent->rect().width();
        RectText *hRect = new RectText(QRectF(leftX, startY,parent->width(), 50), header);
	hRect->setFontSize(40);
	addToGroup(hRect);

	int i = 1;
	for(auto it = actions.begin(); it != actions.end();++it){
                RectText *nwText = new RectText(QRectF(leftX, startY + 50.f*i, parent->width(), 50), it.key());
                nwText->setChangeColorOnHover(true);
                nwText->setHoverColor(QColor(Qt::red));
		QObject::connect(nwText, SIGNAL(mousePressed()), parent, it.value(), Qt::DirectConnection );
		addToGroup(nwText);
		i++;
	}
}
