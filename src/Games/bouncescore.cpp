
#include "bouncescore.h"

#include <QJsonDocument>
#include <qdebug.h>
#include <QPushButton>
#include <QLabel>

const QString BounceScore::saveFileName = "bounce.json";

void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
	while (QLayoutItem* item = layout->takeAt(0))
	{
		if (deleteWidgets)
		{
			if (QWidget* widget = item->widget())
				widget->deleteLater();
		}
		if (QLayout* childLayout = item->layout())
			clearLayout(childLayout, deleteWidgets);
		delete item;
	}
}

BounceScore::BounceScore(QWidget *parent) : QWidget(parent),
	saveFile_(saveFileName),
	subLayout_(new QVBoxLayout)
{
	QVBoxLayout *mainLayout = new QVBoxLayout;

	readScores();
	std::sort(scores_.begin(), scores_.end(), PlayerScore::customSort);

	QLabel *titleLabel = new QLabel("Scoreboard");
	titleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	titleLabel->setStyleSheet("font-size : 32px;");
	mainLayout->addWidget(titleLabel);

	mainLayout->addLayout(subLayout_, 1);

	QPushButton *menuButton = new QPushButton("Menu");
	connect(menuButton, &QPushButton::clicked, this, &BounceScore::showMenu);

	QPushButton *playButton = new QPushButton("Play");
	connect(playButton, &QPushButton::clicked, this, &BounceScore::play);


	mainLayout->addStretch(1);
	mainLayout->addWidget(playButton);
	mainLayout->addWidget(menuButton);

	subLayout_->setAlignment(Qt::AlignTop);
	resetScoreBoard();

	setLayout(mainLayout);
}

void BounceScore::resetScoreBoard()
{
	clearLayout(subLayout_);

	subLayout_->addLayout(PlayerScore::headLayout());

	foreach (PlayerScore s, scores_) {
		subLayout_->addLayout(s.toLayout());
	}
}

void BounceScore::addPlayerScore(int score, const QTime &time)
{
	QString pseudo = QInputDialog::getText(this, "Pseudo","Enter your pseudo");
	if(pseudo.isEmpty())
		return;

	PlayerScore nwPS = PlayerScore{pseudo,  score, time};
	scores_ << nwPS;
	std::sort(scores_.begin(), scores_.end(), PlayerScore::customSort);
	resetScoreBoard();

	writeScores();
}

void BounceScore::readScores()
{
	if(!saveFile_.exists())
		return;

	saveFile_.open(QIODevice::ReadOnly | QIODevice::Text);
	QJsonDocument doc = QJsonDocument::fromJson(saveFile_.readAll());
	if(!doc.isObject()){
		qDebug() << "Failed to parse json file, root is not an object";
		return;
	}
	QJsonObject root = doc.object();
	QJsonValue v = root["scores"];
	if(v.isArray()){
		QJsonArray arr = v.toArray();
		foreach (QJsonValue v, arr) {
			if(v.isObject()){
				PlayerScore s;
				scores_ << ( v.toObject() >> s );
			}

		}
	}
	saveFile_.close();

}

void BounceScore::writeScores()
{
	QJsonObject root;

	QJsonArray content;
	foreach (PlayerScore s, scores_) {
		QJsonObject obj;
		content << (obj << s);
	}
	root["scores"] = content;

	QJsonDocument doc(root);
	saveFile_.open(QIODevice::WriteOnly | QIODevice::Text);
	saveFile_.write(doc.toJson());
	saveFile_.close();

}

QJsonObject &operator<<(QJsonObject &target, const PlayerScore &score)
{
	target["pseudo"] = score.pseudo;
	target["time"] = score.time.msecsSinceStartOfDay();
	target["score"] = score.score;
	return target;
}

PlayerScore &operator>>(const QJsonObject &target, PlayerScore &score)
{
	score.score = target["score"].toInt();
	score.pseudo = target["pseudo"].toString();
	score.time = QTime::fromMSecsSinceStartOfDay(target["time"].toInt());
	return score;
}

bool operator==(const PlayerScore &score1, const PlayerScore &score2)
{
	return score1.score == score2.score && score1.time == score2.time && score1.pseudo == score2.pseudo;
}

bool PlayerScore::customSort(const PlayerScore &score1, const PlayerScore &score2)
{
	if(score1.score != score2.score)return score1.score > score2.score;
	if(score1.time.msecsSinceStartOfDay() != score2.time.msecsSinceStartOfDay()) return score1.time.msecsSinceStartOfDay() > score2.time.msecsSinceStartOfDay();
	return score1.pseudo > score2.pseudo;
}

QHBoxLayout *PlayerScore::toLayout()
{
	QHBoxLayout *layout = new QHBoxLayout;

	layout->addWidget(new QLabel(pseudo));
	layout->addWidget(new QLabel(QString::number(score)));
	layout->addWidget(new QLabel(time.toString(("mm:ss"))));

	return layout;
}

QHBoxLayout *PlayerScore::headLayout()
{
	QHBoxLayout *head = new QHBoxLayout;
	head->addWidget(new QLabel("Pseudo"));
	head->addWidget(new QLabel("Score"));
	head->addWidget(new QLabel("Time"));

	return head;
}
