#ifndef TGRAPHICSVIEW_H
#define TGRAPHICSVIEW_H

#include <QGraphicsView>

class TGraphicsView : public QGraphicsView
{
	Q_OBJECT
public:
	TGraphicsView(QGraphicsScene *scene, QWidget *parent = NULL)
		: QGraphicsView(scene, parent)
	{
	}

protected:
	virtual void resizeEvent(QResizeEvent *event) override
	{
		fitInView(scene()->sceneRect());
		QGraphicsView::resizeEvent(event);
	}
};


#endif // TGRAPHICSVIEW_H
