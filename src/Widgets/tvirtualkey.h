/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TVirtualKey.h
 * Author: boutina
 *
 * Created on 27 janvier 2016, 10:32
 */

#ifndef TVIRTUALKEY_H
#define TVIRTUALKEY_H


#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

#include "tfingerposition.h"

class TVirtualKey : public QWidget {
    Q_OBJECT
public:
    /**
     * Create the 'default' key.
     * The string must contains at leas two chars 
     * the first one must be and int
     * then the key is reated like so :
     *   - 1st char => default char
     *   - 2nd char => shift char
     *   - 3rd char => alt-gr char
     * 
     * @param content the content of the key
     * @param parent the parent widget
     */
    TVirtualKey(QString content, QWidget *parent = 0);

    //Create an 'empty' widget with the given width and the default height
    TVirtualKey(int w, QString text, TFingerPosition::FINGER associatedFinger = TFingerPosition::NO_FINGER, QWidget *parent = 0);


    TVirtualKey(const TVirtualKey& orig);

    virtual ~TVirtualKey() {

    }

    QChar getAlt() const {
        return altgred_;
    }

    QChar getDefault() const {
        return default_;
    }

    QChar getShift() const {
        return shifted_;
    }
    
    TFingerPosition::FINGER associatedFinger() const{
        return associateFinger_;
    }

    bool possibleToType(QChar chr){
        return  !chr.isNull() && (chr  == default_ || chr == shifted_ || chr == altgred_);
    }

public slots:

    /**
     * Change the color of the key
     * to red (when the user does not type
     * the good letter)
     */
    void wrong() {
        paintBackground(Qt::red);
    }

    /**
     * Change the color of the key
     * to green (when the user type
     * the good letter)
     */
    void right() {
        paintBackground(Qt::green);
    }
    
    /**
     * Prompt the user to press the key,
     * painting in darkCyan
     * (used when learning new letters)
     */
    void example(){
        paintBackground(Qt::darkCyan);
    }
    
    /**
     * Reset the background color
     */
    void reset() {
        paintBackground(Qt::transparent);
    }

    /**
     * Change the color of the key
     * to blue, to show that the
     * key is 'active'
     */
    void active(){
        paintBackground(Qt::blue);
    }
    
    /**
     * Change the background color of the widget
     * 
     * @param color the color (from Qt namespace)
     */
    void paintBackground(Qt::GlobalColor color) {
        auto p = palette();
        p.setColor(backgroundRole(),color);
        setPalette(p);
    }

    /**
     * Remove all the existing layouts
     * and wigets, then add a single
     * lable with the given text
     * 
     * @param text the new text
     */
    void setText(QString text);

protected:

    void paintEvent(QPaintEvent *e) {
        QPainter painter(this);
        painter.drawRect(0, 0, width() - 1, height() - 1);
        QWidget::paintEvent(e);
    }


private:
    void constructLetters(QString letters);
    
    TFingerPosition::FINGER associateFinger_ = TFingerPosition::NO_FINGER;

    /* The letter when the user simply press the key */
    QChar default_;

    /* The letter when the user press the key + shift */
    QChar shifted_;

    /* The letter when the user press the key + altGr */
    QChar altgred_;

    /* Render the layout depending on the available keys */
    void setupKey();
};

#endif /* TVIRTUALKEY_H */

