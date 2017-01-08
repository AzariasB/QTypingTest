#ifndef TJSONOBJECT_H
#define TJSONOBJECT_H

#include <QObject>
#include <QJsonObject>

class TJsonObject : public QObject
{
    Q_OBJECT
public:
    explicit TJsonObject(QObject *parent = 0);

    virtual void read(const QJsonObject &json) = 0;

    virtual void write(QJsonObject &json) = 0;

signals:

public slots:
};

#endif // TJSONOBJECT_H
