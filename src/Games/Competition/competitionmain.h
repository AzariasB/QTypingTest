#ifndef COMPETITIONMAIN_H
#define COMPETITIONMAIN_H

#include <QWidget>
#include <QWebSocket>
#include <QJsonObject>
#include <QStackedLayout>

#include "userlist.h"

#define WAITING "WAITING"
#define PLAYING "PLAYING"

class CompetitionMain : public QWidget
{
	Q_OBJECT
public:
	explicit CompetitionMain(QWidget *parent = nullptr);

signals:

public slots:

	void socketConnected();

	void socketError(QAbstractSocket::SocketError error);

	void socketReceiveMessage(QString message);

private:
	void displayRooms(QJsonDocument &jsonData);

	QWidget *roomDisplay(const QJsonObject &roomData);

	QGridLayout *mainLayout_;

	QWebSocket socket_;

	UserList *userList_;
};

#endif // COMPETITIONMAIN_H
