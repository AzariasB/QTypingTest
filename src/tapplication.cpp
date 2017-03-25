/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   tapplication.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */

#include "tapplication.h"

TApplication::TApplication(QObject *parent) : QObject(parent),
	userManager("save.json")
{

}
