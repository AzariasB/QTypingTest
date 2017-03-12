/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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
TWindowTest(TExercice::generateExercice(TExercice::IMPROVING), parent){
	QList<QChar> chars =  um_.getCurrentUser().getStatistics().keys();
    QString training = listToString(chars);
    
    QString page1 = factory::generatePractice(training,false);
    pages_.setNumberOfPages(2);
    QString page2 = factory::generatePractice(training, true);
    pages_.setupPages(page1 + page2);
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

