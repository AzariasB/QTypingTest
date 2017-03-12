/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercice.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 11:42
 */

#ifndef TEXERCICE_H
#define TEXERCICE_H

#include <QStringList>
#include <QDebug>
#include <QDataStream>
#include <QDateTime>

#include "tjsonserializable.h"
#include "tresult.h"

class TLayout;
class TResult;

/**
 * A model class to define the type of exercice the user is about to do
 * There are differents types of exercices and depending on these, differents parameters
 * This class is a factory : it generates the exercice depending on the given parameter
 */
class TExercice : public TJsonSerializable{
public:

	enum EXERCICE_TYPE {
		LEARNING, PRACTICING, PRACTICING_RACE, PRACTICING_TEXT, IMPROVING, UNKNOWN
	};

	//No difficulty because : why would it be necessary ?
	static TExercice generateExercice(EXERCICE_TYPE type, QString mainLetters = "", QString availableLetters = "");

	TExercice();

	QString buildExercice();

	void addAttribute(QString key, QString value);

	/**
	 * @brief completed
	 * Sets the result of the exercise,
	 * and sets the 'completed' time
	 *
	 * @param exRes
	 * @return the datetime at which the exercise ended
	 */
	const QDateTime &completed(TResult exRes);

	virtual void read(const QJsonObject &json) override;

	virtual void write(QJsonObject &json) const override;

	QString findAttribute(QString key);

	bool hasAttribute(const QString &key);

	virtual ~TExercice() {}

	const QString &getLearningLetters() const {
		return learningLetters_;
	}

	const QString &getAvailableLetters() const {
		return availableLetters_;
	}

	const QDateTime &getDateComplete() const {
		return dateComplete_;
	}

	EXERCICE_TYPE getExerciceType() const {
		return exerciceType_;
	}

	int getNumberOfWords() const{
		return numberOfWords_;
	}

	TResult &getResult(){
		return result_;
	}


private:
	TExercice(EXERCICE_TYPE exType, QString mainLetter, QString availableLetters);

	QString learningLetters_;
	QString availableLetters_;
	EXERCICE_TYPE exerciceType_;
	QHash<QString, QString> attributes_;
	QDateTime dateComplete_;
	TResult result_;

	int numberOfWords_;

	friend QDataStream &operator>>(QDataStream &in, TExercice &ex){
		qint16 type;
		in >> ex.availableLetters_ >> type >> ex.learningLetters_  >> ex.attributes_ >> ex.numberOfWords_;
		ex.exerciceType_ = static_cast<EXERCICE_TYPE>(type);
		return in;
	}

	friend QDataStream &operator<<(QDataStream &out, const TExercice &ex){
		out << ex.availableLetters_ << static_cast<qint16>(ex.exerciceType_) <<
			   ex.learningLetters_ << ex.attributes_ << ex.numberOfWords_;
		return out;
	}
};

QDataStream &operator>>(QDataStream &in, TExercice &ex);

QDataStream &operator<<(QDataStream &out, const TExercice &ex);

inline bool operator==(const TExercice& exo1, const TExercice& exo2) {
	return exo1.getAvailableLetters() == exo2.getAvailableLetters() &&
			exo1.getExerciceType() == exo2.getExerciceType() &&
			exo1.getLearningLetters() == exo2.getLearningLetters();
}

#endif /* TEXERCICE_H */

