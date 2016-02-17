/*
 * QTypingTest by Pierre and Azarias
 * Licence : GPL2
 */

/* 
 * File:   TSettings.h
 * Author: boutina
 *
 * Created on 13 février 2016, 15:09
 */

#ifndef TSETTINGS_H
#define TSETTINGS_H

#include "Data/tlayouts.h"

class TSettings {
public:
    TSettings();
    TSettings(const TSettings& orig);
    virtual ~TSettings();

    QString getCurrentLang() const{
        return currentlang_;
    }

    QString getLayout() const{
        return layout_;
    }

    void setCurrentLang(const QString &nwLang){
        currentlang_ = nwLang;
    }

    void setCurrentLayout(const QString &nwLayout){
        layout_ = nwLayout;
    }

private:
    /**
     * \todo : where to put THE list of available languages ?
     */
    QString currentlang_;
    QString layout_;
};

#endif /* TSETTINGS_H */

