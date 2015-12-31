/* 
 * File:   TLabel.h
 * Author: boutina
 *
 * Created on 4 novembre 2015, 18:21
 */

#ifndef TLABEL_H
#define TLABEL_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QFont>

#include "../../Util/htmlhelper.h"

class TLabel : public QLabel {
    Q_OBJECT
public:
    TLabel(QString text);
    TLabel(QString text, QWidget *parent);
    virtual ~TLabel();
    

   /**
    * Update the current char color depending on the answer given by the user
    * the boolean is here to say wether the answer was right or not
    * 
    * @param currendIsCorrect answer given by the user for the current char is correct
    * @return if there is another char after the current one
    */
    bool nextChar(bool currendIsCorrect);
    

private:
    void setLabels();

    const QFont labelFont_ = QFont("Helvetica", 16, QFont::SansSerif);
    QString stringToCopy_;
    int currentChar_ = 0;

};

#endif /* TLABEL_H */

