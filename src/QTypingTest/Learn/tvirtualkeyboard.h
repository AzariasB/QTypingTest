/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TVirtualKeyboard.h
 * Author: boutina
 *
 * Created on 27 janvier 2016, 10:32
 */

#ifndef TVIRTUALKEYBOARD_H
#define TVIRTUALKEYBOARD_H


#include <QWidget>

#include <QHash>
#include <QRegExp>
#include <QDebug>
#include <QList>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "tvirtualkey.h"
#include "Util/filehelper.h"

class TVirtualKeyboard : public QWidget {
    Q_OBJECT
public:
    TVirtualKeyboard(QString lang = "en", QWidget *parent = 0);
    TVirtualKeyboard(const TVirtualKeyboard& orig);
    virtual ~TVirtualKeyboard(){
        
    }
private:
    QList<TVirtualKey*> *keys_;
    
    QList<QStringList> *decomposeLayout(QString layout);
    
    QString findCorrespondingLayout(QString config,QString lang);
    
    void createKeys(QList<QStringList> *keyChars);
    
    QWidget *numberLine(QStringList keys);
    
    QWidget *upperLine(QStringList keys);
    
    QWidget *middleLine(QStringList keys);
    
    QWidget *bottomLine(QStringList keys);
    
    TVirtualKey *createKey(QString attributes);
};

#endif /* TVIRTUALKEYBOARD_H */

