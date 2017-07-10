
#include "userlist.h"
#include <QLabel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHBoxLayout>

#include <QDebug>


//--------------------------------
// Userdata functions
//--------------------------------

UserData UserData::fromJson(const QJsonObject &obj)
{
	UserData res;
	res.pseudo = obj["pseudo"].toString();
	res.isOp = obj["isLeader"].isUndefined() ? false : obj["isLeader"].toBool();
	return res;
}

//--------------------------------
// UserLine functions
//--------------------------------

UserLine::UserLine(const UserData &data):data(data)
{
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	QLabel *pseudoLabel = new QLabel(data.pseudo);

	mainLayout->addWidget(pseudoLabel);
	if(data.isOp){
		QLabel *isOpLabel = new QLabel("<img src=':/icons/crown.png' width='12' height='12' />");
		isOpLabel->setToolTip("This player is the leader");
		mainLayout->addWidget(isOpLabel);
	}

}


//--------------------------------
// UserList functions
//--------------------------------

UserList::UserList(QWidget *parent) : QWidget(parent),
	mainLayout_(new QVBoxLayout(this))
{
	QLabel *label = new QLabel("Connected users");
	label->setStyleSheet(("font-size : 30px;"));

	mainLayout_->addWidget(label);
}


void UserList::setUsers(QJsonDocument nwUsers)
{
	users_.clear();
	for(auto it : users_.values()){
		mainLayout_->removeWidget(it);
	}

	foreach(const QJsonValue &it, nwUsers.array()){
		UserData data = UserData::fromJson(it.toObject());
		UserLine *nwLine = new UserLine(data);
		mainLayout_->addWidget(nwLine);
		users_.insert(data.pseudo, nwLine);
	}
}


void UserList::removeUser(const QString &pseudo)
{
	mainLayout_->removeWidget(users_["pseudo"]);
	delete users_["pseudo"];
	users_.remove(pseudo);
}
