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

class TVirtualKey : public QWidget {
    Q_OBJECT
public:
    //No predefined letters
    TVirtualKey(QWidget *parent = 0);

    //Define only main letter
    TVirtualKey(QChar def, QWidget *parent = 0);

    //Define main letter and shift
    TVirtualKey(QChar def, QChar shift, QWidget *parent = 0);

    //Define main letter, shift letter an altgre letter
    TVirtualKey(QChar def, QChar shift, QChar alt, QWidget *parent = 0);

    //Create an 'empty' widget with the given width and the default height
    TVirtualKey(int w, QString text, QWidget *parent = 0);


    TVirtualKey(const TVirtualKey& orig);

    virtual ~TVirtualKey() {

    }

    QChar getAlt() const {
        return altgred_;
    };

    QChar getDefault() const {
        return default_;
    }

    QChar getShift() const {
        return shifted_;
    };

public slots:

    /**
     * Change the color of the key
     * to red (when the user does not type
     * the good letter)
     */
    void wrong() {
        auto p = palette();
        p.setColor(backgroundRole(), Qt::red);
        setPalette(p);
    }

    /**
     * Change the color of the key
     * to green (when the user type
     * the good letter)
     */
    void right() {
        auto p = palette();
        p.setColor(backgroundRole(), Qt::green);
        setPalette(p);
    }

    /**
     * Reset the background color
     */
    void reset() {
        auto p = palette();
        p.setColor(backgroundRole(), Qt::transparent);
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
    void constructLetters(QChar def = '\0', QChar shift = '\0', QChar altg = '\0');

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

