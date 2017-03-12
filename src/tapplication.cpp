#include "tapplication.h"

TApplication::TApplication(QObject *parent) : QObject(parent),
	userManager("save.json")
{

}
