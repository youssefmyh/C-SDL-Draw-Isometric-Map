/*
 * Vector2D.h
 *
 *  Created on: Jun 15, 2015
 *      Author: youssef
 */

#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <math.h>
class Vector2D {
public:
	Vector2D(float x, float y) :
		m_x(x), m_y(y) {
	}
	virtual ~Vector2D();
	float getX() const {
		return m_x;
	}
	float getY() const {
		return m_y;
	}
	void setX(float x) {
		m_x = x;
	}
	void setY(float y) {
		m_y = y;
	}
	float length();

	Vector2D operator+(const Vector2D &v2) const;
	friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2) {
		v1.m_x += v2.getX();
		v1.m_y += v2.getY();
		return v1;
	}

	Vector2D operator*(const float scaler) {
		return Vector2D(scaler * m_x, scaler * m_y);
	}
	Vector2D& operator*=(float scaler) {
		m_x *= scaler;
		m_y *= scaler;
		return *this;
	}

	Vector2D operator-(const Vector2D &v2) const {
		return Vector2D(m_x - v2.getX(), m_y - v2.getY());
	}

	friend Vector2D& operator-=(Vector2D &v1, const Vector2D &v2) {
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}
	Vector2D operator/(float scalar) {
		return Vector2D(m_x / scalar, m_y / scalar);
	}
	Vector2D& operator/=(float scalar) {
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	void normalize();
private:
	float m_x;
	float m_y;

};

#endif /* VECTOR2D_H_ */
