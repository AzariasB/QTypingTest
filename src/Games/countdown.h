#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QLabel>
#include <QTimer>

class Countdown : public QLabel
{
	Q_OBJECT
public:
	Countdown();

	void reset();

signals:
	void timeout();

public slots:
	void start();


private:
	void tick();

	int value_ = 3;

	QTimer timer_;
};

#endif // COUNTDOWN_H
