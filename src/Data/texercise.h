/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercise.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 11:42
 */

#ifndef TEXERCICE_H
#define TEXERCICE_H

#include <QStringList>
#include <QDebug>
#include <QDateTime>

#include "tjsonserializable.h"
#include "tresult.h"

class TLayout;
class TResult;

/**
 * A model class to define the type of exercise the user is about to do
 * There are differents types of exercises and depending on these, differents parameters
 * This class is a factory : it generates the exercise depending on the given parameter
 */
class TExercise : public TJsonSerializable{
public:

	enum EXERCISE_TYPE {
		LEARNING, PRACTICING, PRACTICING_RACE, PRACTICING_TEXT, IMPROVING, UNKNOWN
	};

	//No difficulty because : why would it be necessary ?
	static TExercise generateExercise(EXERCISE_TYPE type, QString mainLetters = "", QString availableLetters = "");

	TExercise();

	QString buildExercise();

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

	virtual ~TExercise() {}

	const QString &getLearningLetters() const {
		return learningLetters_;
	}

	const QString &getAvailableLetters() const {
		return availableLetters_;
	}

	const QDateTime &getDateComplete() const {
		return dateComplete_;
	}

	EXERCISE_TYPE getExerciseType() const {
		return exerciseType_;
	}

	int getNumberOfWords() const{
		return numberOfWords_;
	}

	TResult &getResult(){
		return result_;
	}


private:
	TExercise(EXERCISE_TYPE exType, QString mainLetter, QString availableLetters);

	QString learningLetters_;
	QString availableLetters_;
	EXERCISE_TYPE exerciseType_;
	QHash<QString, QString> attributes_;
	QDateTime dateComplete_;
	TResult result_;

	int numberOfWords_;
};

inline bool operator==(const TExercise& exo1, const TExercise& exo2) {
	return exo1.getAvailableLetters() == exo2.getAvailableLetters() &&
			exo1.getExerciseType() == exo2.getExerciseType() &&
			exo1.getLearningLetters() == exo2.getLearningLetters();
}

#endif /* TEXERCICE_H */

