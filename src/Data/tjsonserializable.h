#ifndef TJSONOBJECT_H
#define TJSONOBJECT_H

class QJsonObject;

class TJsonSerializable {
public:

	virtual void read(const QJsonObject &json) = 0;

    virtual void write(QJsonObject &json) const = 0;
};


#endif // TJSONOBJECT_H
