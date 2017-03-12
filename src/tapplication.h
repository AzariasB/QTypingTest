#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QObject>
#include "Data/tusermanager.h"

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

	TApplication(const TApplication&) = delete;
	void operator=(const TApplication&) = delete;

signals:

public slots:

private:
	explicit TApplication(QObject *parent = 0);

	TUserManager userManager;

};

#endif // TAPPLICATION_H
