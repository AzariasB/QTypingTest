/* 
 * File:   TLineEdit.h
 * Author: boutina
 *
 * Created on 9 novembre 2015, 19:10
 */

#ifndef TLINEEDIT_H
#define	TLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class TLineEdit : public QLineEdit {
    Q_OBJECT
public:
    TLineEdit(QWidget *parent);
    TLineEdit(const TLineEdit& orig);
    virtual ~TLineEdit();
private:

};

#endif	/* TLINEEDIT_H */

