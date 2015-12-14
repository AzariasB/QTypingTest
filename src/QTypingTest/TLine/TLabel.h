/* 
 * File:   TLabel.h
 * Author: boutina
 *
 * Created on 4 novembre 2015, 18:21
 */

#ifndef TLABEL_H
#define	TLABEL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QSizePolicy>
#include <QHBoxLayout>

class TLabel : public QWidget {
    Q_OBJECT
public:
    TLabel(QString text);
    TLabel(QString text, QWidget *parent);
    virtual ~TLabel();
    bool nextWord();
    bool updateLabelColor(QString wordTyped);
    int getNbrErrors();
    QString getCurrentWord();
    
private:
    void setLabels(QString labelLine);
    void initStyleSheet();
    
    QVector<QLabel*> labels;
    int currentWord = 0;
    int nbrErrors = 0;
    bool exactSame = false;

};

#endif	/* TLABEL_H */

