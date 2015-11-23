/* 
 * File:   TLineEdit.cpp
 * Author: boutina
 * 
 * Created on 9 novembre 2015, 19:10
 */

#include "TLineEdit.h"

TLineEdit::TLineEdit(QWidget *parent): QLineEdit(parent) {
    this->setText(" ");
    this->setSelection(0,1);
}

TLineEdit::TLineEdit(const TLineEdit& orig) : QLineEdit(orig.text(),orig.parentWidget()){
    
}

TLineEdit::~TLineEdit() {}

