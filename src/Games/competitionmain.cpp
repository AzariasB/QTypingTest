


#include "competitionmain.h"
#include <QDebug>

CompetitionMain::CompetitionMain(QWidget *parent) : QWidget(parent)
{
	connect(&socket_, &QWebSocket::connected, this, &CompetitionMain::socketConnected);
	connect(&socket_, &QWebSocket::textMessageReceived, this, &CompetitionMain::socketReceiveMessage);
	socket_.open(QUrl("ws://localhost:5000"));
}


void CompetitionMain::socketConnected()
{
	qDebug() << "Socket is connected";
	socket_.sendTextMessage("PSEUDO:" + QString::number(qrand()));
}

void CompetitionMain::socketReceiveMessage(QString message)
{
	qDebug() << message;
}
