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

#include "Util/htmlhelper.h"

class TLabel : public QLabel {
    Q_OBJECT
public:
    TLabel(QString text, QWidget *parent = 0);
    virtual ~TLabel();


    /**
     * Update the current char color depending on the answer given by the user
     * the boolean is here to say wether the answer was right or not
     * 
     * @param currendIsCorrect answer given by the user for the current char is correct
     * @return if there is another char after the current one
     */
    bool nextChar(bool currendIsCorrect);

    /**
     * Rollback the display and set the current label to the previous one
     * in case of rollback from the user
     * 
     * @return if there are some chars before the current one 
     */
    bool previousChar();

    /**
     * Function to update the display and show that the line is ready
     * for use
     */
    inline void setFirst() {
        html::addTags(splitedChars_[0], "b,u");
        this->setText(splitedChars_.join(""));
    }

signals:
    /**
     * A signale trigerred when the user tries to erase whenever he's at the
     * start of the line
     */
    void eraseOverflow();

private:
    void setLabels();

    const QFont labelFont_ = QFont("Monospace", 20, QFont::Monospace);
    QString stringToCopy_;
    QStringList splitedChars_;
    int currentChar_ = 0;

};

#endif /* TLABEL_H */

