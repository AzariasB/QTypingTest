/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercice.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 11:42
 */


#include "texercice.h"

#include "tresult.h"
#include "Util/factory.h"
#include "Data/tlayout.h"


TExercice::TExercice() :
learningLetters_(""),
availableLetters_(TLayout::getInstance().getAllAvailableLetters()),
exerciceType_(PRACTICING){
}

TExercice::TExercice(EXERCICE_TYPE exType, QString mainLetter, QString availableLetters) :
learningLetters_(mainLetter),
availableLetters_(availableLetters),
exerciceType_(exType)
{
}

TExercice::TExercice(const TExercice& orig) :
learningLetters_(orig.learningLetters_),
availableLetters_(orig.availableLetters_),
exerciceType_(orig.exerciceType_){
}

TExercice* TExercice::generateExercice(EXERCICE_TYPE type, QString mainLetters, QString availableLetters)
{
    switch(type){
        case LEARNING:
            return new TExercice(type, mainLetters, availableLetters);
        default:
            return new TExercice(type, "", TLayout::getInstance().getAllAvailableLetters() );
    }
}

void TExercice::addAttribute(QString key, QString value)
{
    attributes_[key] = value;
}

const QDateTime &TExercice::completed(TResult &exRes)
{
	result_ = exRes;
	dateComplete_ = QDateTime::currentDateTime();
	return dateComplete_;
}

void TExercice::read(const QJsonObject &json)
{
	exerciceType_ = (EXERCICE_TYPE)json["exerciseType"].toInt();
	dateComplete_ = QDateTime::fromMSecsSinceEpoch(json["dateComplete"].toInt());
	result_.read(json["result"].toObject());
	numberOfWords_ = json["numberOfWords"].toInt();
}

void TExercice::write(QJsonObject &json) const
{
	json["exerciseType"] = exerciceType_;
	json["dateComplete"] = dateComplete_.toMSecsSinceEpoch();
	QJsonObject resultJson;
	result_.write(resultJson);
	json["result"] = resultJson;
	json["numberOfWords"] = numberOfWords_;
}

QString TExercice::findAttribute(QString key)
{
    return attributes_[key];
}

bool TExercice::hasAttribute(const QString &key)
{
    return attributes_.contains(key);
}

QString TExercice::buildExercice() {
    QString exo;
    switch (exerciceType_) {
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
