/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   vector2f.cpp
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */


#include "vector2f.h"
#include "math.h"

const Vector2f Vector2f::zero = Vector2f(0,0);

Vector2f::Vector2f()
{

}

Vector2f::Vector2f(qreal x, qreal y):
x_(x),
y_(y)
{

}



qreal Vector2f::length() const
{
	return sqrt(x_*x_ + y_*y_);
}

void Vector2f::normalize()
{
	qreal l = length();
	x_ = x_/l;
	y_ = y_/l;
}


Vector2f Vector2f::normalized() const
{
	Vector2f nwVector(x_,y_);
	nwVector.normalize();
	return nwVector;
}


//////////////////////////////////
//								//
//		Operator overloading	//
//								//
//////////////////////////////////

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
