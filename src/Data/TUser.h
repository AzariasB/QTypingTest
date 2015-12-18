/* 
 * File:   TUser.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 18:54
 */

#ifndef TUSER_H
#define TUSER_H

#include <QString>
#include <QDebug>

class TUser {
public:
    TUser(QString pseudo);
    virtual ~TUser();
    
    QString getPseudo() const{
        return pseudo;
    };
    
    void setPseudo(QString pseudo){
        this->pseudo = pseudo;
    }
private:
    QString pseudo;
};


QDataStream &operator<<(QDataStream& out,const TUser& user);

QDataStream &operator>>(QDataStream& in,TUser &user);

#endif /* TUSER_H */

