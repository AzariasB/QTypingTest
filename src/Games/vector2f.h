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
#include <QPointF>

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

	Vector2f(const QPointF &copy);

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

	QPointF toPoint();

private:
	qreal x_ = 0;
	qreal y_ = 0;
};


//////////////////////////////////
//								//
//		Operator overloading	//
//								//
//////////////////////////////////


inline Vector2f operator+(const Vector2f &left, const QPointF& right)
{
	return Vector2f(left.x() + right.x(), left.y() + right.y());
}

inline Vector2f operator+(const QPointF& left, const Vector2f  &right)
{
	return Vector2f(left.x() + right.x(), left.y() + right.y());
}

inline Vector2f &operator+=(Vector2f &left, const Vector2f &right)
{
	left.setX(left.x() + right.x());
	left.setY(left.y() + right.y());
	return left;
}

inline Vector2f &operator-=(Vector2f &left, const Vector2f &right)
{
	left.setX(left.x() - right.x());
	left.setY(left.y() - right.y());
	return left;
}


inline Vector2f operator+(const Vector2f &left, const Vector2f &right)
{
	return Vector2f(left.x() + right.x(), left.y() + right.y());
}


inline Vector2f operator-(const Vector2f &left, const Vector2f &right)
{
	return Vector2f(left.x() - right.x(), left.y() - right.y());
}

inline Vector2f operator*(const Vector2f &left, qreal right)
{
	return Vector2f(left.x() * right, left.y() * right);
}

inline Vector2f operator*(qreal left, const Vector2f &right)
{
	return Vector2f(right.x() * left, right.y() * left);
}

inline Vector2f &operator*=(Vector2f &left, qreal right)
{
	left.setX(left.x() * right);
	left.setY(left.y() * right);
	return left;
}

inline Vector2f operator/(const Vector2f &left, qreal right)
{
	return Vector2f(left.x()/right, left.y()/right);
}


inline Vector2f &operator/=(Vector2f &left, qreal right)
{
	left.setX(left.x()/right);
	left.setY(left.y()/right);
	return left;
}

#endif // VECTOR2F_H
