/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercise.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 11:42
 */


#include "texercise.h"

#include "tresult.h"
#include "Util/factory.h"
#include "Data/tlayout.h"
#include "tapplication.h"


TExercise::TExercise() :
learningLetters_(""),
availableLetters_(tApp.getLayout().getAllAvailableLetters()),
exerciseType_(PRACTICING){
}

TExercise::TExercise(EXERCISE_TYPE exType, QString mainLetter, QString availableLetters) :
learningLetters_(mainLetter),
availableLetters_(availableLetters),
exerciseType_(exType)
{
}

TExercise TExercise::generateExercise(EXERCISE_TYPE type, QString mainLetters, QString availableLetters)
{

	if(type == LEARNING){
		return TExercise(type, mainLetters, availableLetters);;
	}else{
		return TExercise(type, "", tApp.getLayout().getAllAvailableLetters());
	}
}

void TExercise::addAttribute(QString key, QString value)
{
    attributes_[key] = value;
}

const QDateTime &TExercise::completed(TResult exRes)
{
	result_ = exRes;
	dateComplete_ = QDateTime::currentDateTime();
	return dateComplete_;
}

void TExercise::read(const QJsonObject &json)
{
	exerciseType_ =  static_cast<EXERCISE_TYPE>(json["exerciseType"].toInt());
	dateComplete_ = QDateTime::fromMSecsSinceEpoch(json["dateComplete"].toInt());
	result_.read(json["result"].toObject());
	numberOfWords_ = json["numberOfWords"].toInt();
}

void TExercise::write(QJsonObject &json) const
{
	json["exerciseType"] = exerciseType_;
	json["dateComplete"] = dateComplete_.toMSecsSinceEpoch();
	QJsonObject resultJson;
	result_.write(resultJson);
	json["result"] = resultJson;
	json["numberOfWords"] = numberOfWords_;
}

QString TExercise::findAttribute(QString key)
{
    return attributes_[key];
}

bool TExercise::hasAttribute(const QString &key)
{
    return attributes_.contains(key);
}

QString TExercise::buildExercise() {
    QString exo;
	switch (exerciseType_) {
        case LEARNING:
            exo = factory::generateLearning(learningLetters_, availableLetters_);
            addAttribute("learning",learningLetters_);
            break;
        case PRACTICING:
        case PRACTICING_RACE:
            //For practicing race : add time attribute
            exo = factory::generatePractice(availableLetters_);
            break;
        case PRACTICING_TEXT:
            {
                TText text(factory::getRandomText());
                addAttribute("author",text.author());
                addAttribute("title",text.title());
                exo = text.text();
            }
            break;
        default:
            exo =  factory::generateLearning(availableLetters_, availableLetters_);
            break;
    }
    numberOfWords_ = exo.split(" ").size();
    return exo;
}
