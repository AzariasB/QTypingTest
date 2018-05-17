/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 18:54
 */

#include "tuser.h"
#include "tjsonserializable.h"
#include "Util/factory.h"
#include <QJsonObject>
#include <QJsonArray>

TUser::TUser(const QString &pseudo, QObject *parent) :
    QObject(parent),
    TJsonSerializable(),
    id_(factory::nexUId()),
    pseudo_(pseudo){
}

TUser::TUser(const TUser &other):
    QObject(other.parent()),
    id_(other.id_),
    pseudo_(other.pseudo_),
    progress_(other.progress_),
    statistics_(other.statistics_),
    practiceHistory_(other.practiceHistory_)
{

}

QDateTime TUser::addResult(const TExercise &exo) {
	practiceHistory_ << exo;
	emit statsChanged(*this);
	return exo.getDateComplete();
}

void TUser::oneMoreMistake(const QChar& mistaken) {
    this->statistics_[mistaken]++;
    //emit statsChanged(this);
}

void TUser::read(const QJsonObject &json)
{
	id_ = json["id"].toInt();
	pseudo_ = json["pseudo"].toString();
	progress_.read(json["progression"].toObject());
	statistics_.read(json["statistics"].toObject());
	for(QJsonValue v : json["exercises"].toArray()){
		TExercise ex;
		ex.read(v.toObject());
		practiceHistory_ << ex;
	}
}



void TUser::write(QJsonObject &json) const
{
	json["id"] = id_;
	json["pseudo"] = pseudo_;
	QJsonObject progression;
	progress_.write(progression);
	json["progression"] = progression;
	QJsonObject statsJson;
	statistics_.write(statsJson);
	json["statistics"] = statsJson;

	QJsonArray exercises;
	foreach(TExercise ex, practiceHistory_){
		QJsonObject exo;
		ex.write(exo);
		exercises << exo;
	}
	json["exercises"] = exercises;
}


TUser::~TUser() {
}

