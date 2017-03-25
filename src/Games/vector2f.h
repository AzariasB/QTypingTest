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

	Vector2f(float x, float y);

	float x() const {
			return x_;
	}

	float y() const {
		return y_;
	}

	bool isNull() const{
		return x_ == 0 && y_ == 0;
	}

	float length() const;

	void normalize();

	Vector2f normalized() const;

	void setX(float x){x_ = x;}

	void setY(float y){y_ = y;}


private:
	float x_ = 0;
	float y_ = 0;

	bool clockWiseRotate_ = false;
};

#endif // VECTOR2F_H
