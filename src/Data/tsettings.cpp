/*
 * QTypingTest by Pierre and Azarias
 * Licence : GPL2
 */

/* 
 * File:   TSettings.cpp
 * Author: boutina
 * 
 * Created on 13 février 2016, 15:09
 */

#include "tsettings.h"

TSettings::TSettings() {
    //TLayouts::get
}

TSettings::TSettings(const TSettings& orig):
currentlang_(orig.currentlang_),
layout_(orig.layout_){
}

TSettings::~TSettings() {
}

