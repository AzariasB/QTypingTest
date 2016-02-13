/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TImprove.cpp
 * Author: boutina
 * 
 * Created on 12 février 2016, 17:45
 */


#include "timprove.h"

TImprove::TImprove(QWidget* parent):
TWindowTest(parent){
    QList<QChar> chars =  TUserManager::getInstance().getCurrentUser()->getStatistics().keys();
    QString training = listToString(chars);
    
    // \todo : create a longer string and split up in two parts for the two pages
    QString page1 = factory::generatePractice(training,false);
    pages_.setNumberOfPages(2);
    pages_.setupPages(page1);
    updateToolbarProgression();
}

QString TImprove::listToString(const QList<QChar>& chars) {
    QString str = "";
    for (auto it = chars.begin(); it != chars.end();++it){
        str += *it;
    }
    return str;
}


TImprove::~TImprove() {
}

