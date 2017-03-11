/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TUser.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 18:54
 */

#ifndef TUSER_H
#define TUSER_H

#include <QString>
#include <QDateTime>
#include <QDebug>
#include <QHash>
#include <QJsonArray>
#include <QJsonObject>

#include "Data/texercice.h"
#include "tstats.h"
#include "Util/factory.h"
#include "tprogression.h"
#include "tresult.h"
#include "tjsonserializable.h"


class TUser : public QObject, public TJsonSerializable {

    Q_OBJECT
public:
    TUser(QString pseudo = "", QObject *parent = 0) :
		QObject(parent),
		TJsonSerializable(),
        id_(factory::nexUId()),
        pseudo_(pseudo),
        progress_(new TProgression()),
        practiceHistory_(),
        statistics_(TStats()){
    }

    TUser(const TUser &orig) :
	QObject(orig.parent()),
	TJsonSerializable(),
    id_(orig.id()),
    pseudo_(orig.pseudo_),
    progress_(orig.progress_),
    statistics_(orig.statistics_),
    practiceHistory_(orig.practiceHistory_){
    }

    virtual ~TUser();

    QString getPseudo() const {
        return pseudo_;
    }

    void setPseudo(QString pseudo) {
        this->pseudo_ = pseudo;
    }

	QList<TExercice> *getPracticeHistory() {
        return &practiceHistory_;
    }

    TProgression* getProgression() const {
        return progress_;
    }

    const TStats &getStatistics() const {
        return statistics_;
    }

    void setSettings(const TUser &user){
        pseudo_ = user.getPseudo();
        emit settingsChanged(this);
    }

    void setProgression(TProgression *nwProgression) {
        progress_ = nwProgression;
    }

    void setStatistics(const TStats& stats) {
        statistics_ = stats;
        emit statsChanged(this);
    }

	void setPracticeHistory(QList<TExercice> history) {
        practiceHistory_ = history;
    }

	virtual void read(const QJsonObject &json) override;

	virtual void write(QJsonObject &json) const override;

	void readHistory(const QJsonObject &json);

	void writeHistory(QJsonObject &json) const;

    void oneMoreMistake(const QChar &mistaken);

    void setId(int id){
        id_ = id;
    }



    int id() const{
        return id_;
    }

    /**
     * Add result to the history of user practice.
     * Save the date, and the type of the exercice as a key, 
     * then add the result as value
     * 
     * @param exTyp the  exercice done by the user
     * @param exRes the result of the exercice
     * @return the time when this result was saved
     */
	QDateTime addResult(TExercice *exo);

    void operator=(const TUser &orig) {
        setParent(orig.parent());
        id_ = orig.id_;
        pseudo_ = orig.pseudo_;
        progress_ = orig.progress_;
        statistics_ = orig.statistics_;
        practiceHistory_ = orig.practiceHistory_;
    }

    operator QString() const{
        return QString("id : %1, pseudo : %2")
                .arg(id_)
                .arg(pseudo_);
    }

signals:
    void statsChanged(TUser *);

    void settingsChanged(TUser *);

private:
    int id_;
    QString pseudo_;
    TProgression *progress_;
    TStats statistics_;
	QList<TExercice> practiceHistory_;
};



inline bool operator==(const TUser& user1, const TUser& user2) {
    return user1.id() == user2.id();
}

#endif /* TUSER_H */

