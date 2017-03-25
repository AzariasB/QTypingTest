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

Vector2f::Vector2f(float x, float y):
x_(x),
y_(y)
{

}



float Vector2f::length() const
{
	return sqrt(x_*x_ + y_*y_);
}

void Vector2f::normalize()
{
	float l = length();
	x_ = x_/l;
	y_ = y_/l;
}

Vector2f Vector2f::normalized() const
{
	Vector2f nwVector(x_,y_);
	nwVector.normalize();
	return nwVector;
}
