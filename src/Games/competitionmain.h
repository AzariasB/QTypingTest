#ifndef COMPETITIONMAIN_H
#define COMPETITIONMAIN_H

#include <QWidget>
#include <QWebSocket>

class CompetitionMain : public QWidget
{
	Q_OBJECT
public:
	explicit CompetitionMain(QWidget *parent = nullptr);

signals:

public slots:

	void socketConnected();

	void socketReceiveMessage(QString message);

private:
	QWebSocket socket_;
};

#endif // COMPETITIONMAIN_H
