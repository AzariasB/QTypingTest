/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   vector2f.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */


#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <qglobal.h>

enum DIRECTION{
	UP, RIGHT, DOWN, LEFT, NO_DIRECTION, ALL_DIRECTIONS
};
/**
 * @brief The Vector2f class
 * Simplified vector for the game
 */
class Vector2f
{
public:
	static const Vector2f zero;

	Vector2f();

	Vector2f(qreal x, qreal y);

	qreal x() const {
			return x_;
	}

	qreal y() const {
		return y_;
	}

	bool isNull() const{
		return x_ == 0 && y_ == 0;
	}

	qreal length() const;

	void normalize();

	Vector2f normalized() const;

	void setX(qreal x){x_ = x;}

	void setY(qreal y){y_ = y;}


private:
	qreal x_ = 0;
	qreal y_ = 0;
};


Vector2f &operator+=(Vector2f &left, const Vector2f &right);

Vector2f &operator-=(Vector2f &left, const Vector2f &right);

Vector2f operator+(const Vector2f &left, const Vector2f &right);

Vector2f operator-(const Vector2f &left, const Vector2f &right);

Vector2f operator*(const Vector2f &left, qreal right);

Vector2f operator*(qreal left, const Vector2f &right);

Vector2f &operator*=(Vector2f &left, qreal right);

Vector2f operator/(const Vector2f &left, qreal right);

Vector2f &operator/=(Vector2f &left, qreal right);

#endif // VECTOR2F_H
