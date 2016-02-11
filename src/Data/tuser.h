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

#include "tprogression.h"
#include "texercice.h"
#include "tresult.h"
#include "tstats.h"

struct date_exercice_ {
    QDateTime dateResult;
    TExercice *exercice;
};

class TUser {
public:
    TUser(QString pseudo = "");
    TUser(const TUser &origin);
    virtual ~TUser();

    QString getPseudo() const {
        return pseudo_;
    };

    void setPseudo(QString pseudo) {
        this->pseudo_ = pseudo;
    }

    inline QHash<date_exercice_*, TResult*> getPracticeHistory() const {
        return practiceHistory_;
    }

    inline TProgression* getProgression() const {
        return progress_;
    }

    inline const TStats &getStatistics() const {
        return statistics_;
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


signals:
    void userChanged(TUser *nwUser);

private:
    QString pseudo_;
    TProgression *progress_;
    TStats statistics_;

    QHash<date_exercice_*, TResult*> practiceHistory_;

};


QDataStream &operator<<(QDataStream& out, const TUser& user);

QDataStream &operator>>(QDataStream& in, TUser &user);

inline bool operator==(const TUser& user1, const TUser& user2) {
    // This means pseuo are UNIQUES !
    return user1.getPseudo() == user2.getPseudo();
}


#endif /* TUSER_H */

