/*
 * QTypingTest by Pierre and Azarias - //website//
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
#include <QDataStream>

#include "tprogression.h"
#include "texercice.h"
#include "tresult.h"
#include "tstats.h"

struct date_exercice_ {
    QDateTime dateResult;
    TExercice exercice;
};

class TUser : public QObject {

    Q_OBJECT
public:
    TUser(QString pseudo = "", QObject *parent = 0) :
    QObject(parent),
    pseudo_(pseudo),
    progress_(new TProgression()),
    statistics_(TStats()){
        detectLang();
    }

    TUser(const TUser &orig) :
    QObject(orig.parent()),
    pseudo_(orig.pseudo_),
    progress_(orig.progress_),
    statistics_(orig.statistics_),
    lang_(orig.lang_),
    layout_(orig.layout_){
    }

    virtual ~TUser();

    QString getPseudo() const {
        return pseudo_;
    }

    void setPseudo(QString pseudo) {
        this->pseudo_ = pseudo;
    }

    QHash<date_exercice_, TResult> getPracticeHistory() const {
        return practiceHistory_;
    }

    TProgression* getProgression() const {
        return progress_;
    }

    QString getLayout() const{
        return layout_;
    }

    void setLayout(const QString &nwLayou){
        layout_ = nwLayou;
    }

    QString getLang() const{
        return lang_;
    }

    void setLang(const QString &lang){
        lang_ = lang;
    }

    const TStats &getStatistics() const {
        return statistics_;
    }

    void setSettings(const TUser &user){
        pseudo_ = user.getPseudo();
        lang_ = user.getLang();
        layout_ = user.getLayout();
    }

    void setProgression(TProgression *nwProgression) {
        progress_ = nwProgression;
    }

    void setStatistics(const TStats& stats) {
        statistics_ = stats;
        emit statsChanged(this);
    }

    void setPracticeHistory(QHash<date_exercice_, TResult> history) {
        practiceHistory_ = history;
    }

    void oneMoreMistake(const QChar &mistaken);

    /**
     * Add result to the history of user practice.
     * Save the date, and the type of the exercice as a key, 
     * then add the result as value
     * 
     * @param exTyp the  exercice done by the user
     * @param exRes the result of the exercice
     * @return the time when this result was saved
     */
    QDateTime addResult(TExercice *exTyp, TResult *exRes);

    void operator=(const TUser &orig) {
        setParent(orig.parent());
        pseudo_ = orig.pseudo_;
        progress_ = orig.progress_;
        statistics_ = orig.statistics_;
        practiceHistory_ = orig.practiceHistory_;
    }

signals:
    void statsChanged(TUser *);

private:
    QString pseudo_;
    TProgression *progress_;
    TStats statistics_;
    QString lang_;
    QString layout_;

    QHash<date_exercice_, TResult> practiceHistory_;

    /**
     * @brief setLang detect the computer language setting and apply it to the user's lang
     */
    void detectLang();

};


QDataStream &operator>>(QDataStream& in, const date_exercice_& dateEx);

/**
 * Save the date_exercice_ structure
 * 
 * @param out the dataStream targer (where to write the data)
 * @param dateEx the structur to be written in the dataStream
 * @return teh modified datastream
 */
QDataStream &operator<<(QDataStream& out, const date_exercice_& dateEx);


/**
 * Write a user in the DataStream
 * 
 * @param out the dataStream target (where to write the data)
 * @param user the user that is to be written in the dataStream
 * @return the modified dataStream
 */
QDataStream &operator<<(QDataStream& out, const TUser& user);


/**
 * Takes back all the user's informations
 * from the DataStream
 * 
 * @param in the dataStream containing the user
 * @param user the user to initialize from the datastream
 * @return the datastream
 */
QDataStream &operator>>(QDataStream& in, TUser &user);

inline bool operator==(const TUser& user1, const TUser& user2) {
    // This means pseuo are UNIQUES !
    return user1.getPseudo() == user2.getPseudo() &&
            user1.getProgression() == user1.getProgression();
}

inline bool operator==(const date_exercice_& date1, const date_exercice_& date2) {
    return date1.dateResult == date2.dateResult &&
            date1.exercice == date2.exercice;
}

inline uint qHash(const date_exercice_ & key) {
    return qHash(static_cast<qint64> (key.dateResult.currentMSecsSinceEpoch()));
}

#endif /* TUSER_H */

