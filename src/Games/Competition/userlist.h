#ifndef USERLIST_H
#define USERLIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMap>
#include <QJsonObject>

/**
 * @brief The UserLine struct
 * Class to handle the display of a single
 * line of a user, displays wether the user
 * is op, his pseudo etc ....
 */

struct UserData{
	QString pseudo;
	bool isOp;

	static UserData fromJson(const QJsonObject &obj);
};

struct UserLine : QWidget{

	UserData data;

	UserLine(const UserData &data);
};

/**
 * @brief The UserList class
 * Class holding all the data about
 * all the connected user to a room
 * and handling the display of it
 */
class UserList : public QWidget
{
	Q_OBJECT
public:
	explicit UserList(QWidget *parent = nullptr);

	void setUsers(QJsonDocument nwUsers);

	void removeUser(const QString &pseudo);

signals:

public slots:

private:
	QVBoxLayout *mainLayout_;

	QMap<QString, UserLine*> users_;

};

#endif // USERLIST_H
