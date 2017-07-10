


#include "competitionmain.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonArray>

CompetitionMain::CompetitionMain(QWidget *parent) : QWidget(parent),
	mainLayout_(new QGridLayout),
	userList_(new UserList)
{
	connect(&socket_, &QWebSocket::connected, this, &CompetitionMain::socketConnected);
	connect(&socket_, &QWebSocket::textMessageReceived, this, &CompetitionMain::socketReceiveMessage);
	connect(&socket_, SIGNAL(error(QAbstractSocket::SocketError)), this ,  SLOT(socketError(QAbstractSocket::SocketError)));
	socket_.open(QUrl("ws://localhost:5000"));
	setLayout(mainLayout_);

	mainLayout_->addWidget(userList_,0 , 0);
}


void CompetitionMain::socketConnected()
{
	qDebug() << "Socket is connected";
	socket_.sendTextMessage("PSEUDO:" + QString::number(qrand()));
}

void CompetitionMain::socketReceiveMessage(QString message)
{
	if(message.startsWith("ROOMS:")){//To implement later, for the rooms part
		QString roomsString = message.mid(6);
		QJsonDocument doc = QJsonDocument::fromJson(roomsString.toUtf8());
		displayRooms(doc);
	}else if(message.startsWith("ERROR:")){
		QString errorString = message.mid(6);
		qWarning() << "An error occured : " << errorString;
	}else if(message.startsWith(("PLAYERS:"))){
		QString players = message.mid(8);
		qDebug() << players;
		userList_->setUsers(QJsonDocument::fromJson(players.toUtf8()));
	}
}


void CompetitionMain::displayRooms(QJsonDocument &jsonData)
{
	QWidget *roomsWdiget = new QWidget;
	QVBoxLayout *roomsLayout = new QVBoxLayout;
	QJsonArray arr = jsonData.array();
	foreach (QJsonValue val, arr) {
		roomsLayout->addWidget(roomDisplay(val.toObject()));
	}

	roomsWdiget->setLayout(roomsLayout);
	mainLayout_->addWidget(roomsWdiget);
}

void CompetitionMain::socketError(QAbstractSocket::SocketError error)
{
	qDebug() << socket_.errorString();
}


QWidget *CompetitionMain::roomDisplay(const QJsonObject &roomData)
{
	QWidget *widget = new QWidget;
	QVBoxLayout *layout = new QVBoxLayout;

	QLabel *roomState = new QLabel(roomData["state"].toString());
	layout->addWidget(roomState);

	bool canConnect = roomData["state"] == WAITING;

	if(roomData.contains("players") && roomData["players"].isArray()){
		const QJsonArray &arr = roomData["players"].toArray();
		foreach (QJsonValue pseudoValue, arr) {
			QLabel *pseudoLabel = new QLabel(pseudoValue.toString());
			layout->addWidget(pseudoLabel);
		}
	}


	QPushButton *button = new QPushButton("Connect");
	button->setEnabled(canConnect);

	layout->addWidget(button);

	widget->setLayout(layout);
	return widget;
}
