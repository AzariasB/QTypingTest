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
#include <QLineEdit>
#include <QDebug>
#include <QVector>
#include <QHBoxLayout>
#include <QRegExp>
#include <QFont>

#include "../../Util/htmlhelper.h"
#include "../../Data/tkeys.h"

class TLabel : public QWidget {
    Q_OBJECT
public:
    TLabel(QString text);
    TLabel(QString text, QWidget *parent);
    virtual ~TLabel();
    
    /**
     * Set the current word to the next one
     * exept if the current one is the last word to copy
     * 
     * @return if the next word exists
     */
    bool nextWord();

    /**
     * Check if the answer the user is entering is correct
     * and update the label in consequence
     * 
     * @param wordTyped the whole word the user typed
     * @return if the answer exactly the same as the text to copy
     */
    bool updateLabelColor(QString wordTyped);
    
    /**
     * Get the number of errors the user made 
     * 
     * @return the number of errors the user made while copying the text
     */
    int getNbrErrors();
    QString getCurrentWord();

private:
    void setLabels(QString labelLine);

    /**
     * 
     * @param word the word that will be surronded by html tags
     */

    const QFont labelFont_ = QFont("Helvetica", 16, QFont::SansSerif);
    QVector<QLabel*> labels_;
    int currentWord_ = 0;
    int nbrErrors_ = 0;
    bool exactSame_ = false;

};

#endif /* TLABEL_H */

