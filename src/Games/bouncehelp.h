#ifndef BOUNCEHELP_H
#define BOUNCEHELP_H

#include <QWidget>

class BounceHelp : public QWidget
{
	Q_OBJECT
public:
	explicit BounceHelp(QWidget *parent = 0);

protected:
	void keyPressEvent(QKeyEvent *event) override;

signals:
	void backToMenu();

public slots:
};

#endif // BOUNCEHELP_H
