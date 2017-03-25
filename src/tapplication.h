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

#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QObject>
#include "Data/tusermanager.h"
#include "Data/tlayout.h"

#define tApp (TApplication::instance())

/**
 * @brief The TApplication class
 *
 * Must be the only (custom) singleton of the whole app
 * all the other objects that "must" be a singleton,
 * must be stored in this class and then accessed from it
 */
class TApplication : public QObject
{
	Q_OBJECT
public:
	static TApplication &instance(){
		static TApplication instance;

		return instance;
	}

        TUserManager &getUserManager(){
            return userManager;
        }

		TLayout &getLayout(){
			return layout;
		}

	TApplication(const TApplication&) = delete;
	void operator=(const TApplication&) = delete;

signals:

public slots:

private:
	explicit TApplication(QObject *parent = 0);

	TUserManager userManager;

	TLayout layout;

};

#endif // TAPPLICATION_H
