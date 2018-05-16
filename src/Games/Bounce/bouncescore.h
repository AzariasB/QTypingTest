/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bouncescore.h
 * Author: azarias
 *
 */

#ifndef BOUNCESCORE_H
#define BOUNCESCORE_H

#include <QWidget>
#include <QTime>
#include <QFile>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QInputDialog>
#include <QVBoxLayout>

struct PlayerScore{
	QString pseudo;
	int score;
	QTime time;

    bool operator<(const PlayerScore &other) const;

    bool operator>(const PlayerScore &other) const;

    bool operator==(const PlayerScore &other) const;

	QHBoxLayout *toLayout();

	static QHBoxLayout *headLayout();
};

QJsonObject &operator<<(QJsonObject &target, const PlayerScore &score);

PlayerScore &operator>>(const QJsonObject &target, PlayerScore &score);


class BounceScore : public QWidget
{
	Q_OBJECT
public:
	explicit BounceScore(QWidget *parent = nullptr);

	/**
	 * @brief addPlayerScore
	 * Shows a dialog and asks
	 * for the user pseudo, and save the new score
	 *
	 * @param socre the player's score
	 * @param time the time for the player's game
	 */
	void addPlayerScore(int score, const QTime &time);

signals:
	void showMenu();

	void play();

public slots:

private:
	static const QString saveFileName;

	void readScores();

	void writeScores();

	void resetScoreBoard();

	QList<PlayerScore> scores_;

	QFile saveFile_;

	QVBoxLayout *subLayout_;
};

#endif // BOUNCESCORE_H
