/*
 * Vector2D.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: Home
 */

#include "Vector2D.h"

Vector2D::~Vector2D() {
	// TODO Auto-generated destructor stub
}

float Vector2D::length() {
	return sqrt(m_x * m_x + m_y * m_y);
}
Vector2D Vector2D::operator +(const Vector2D &v2) const {
	return Vector2D(m_x + v2.getX(), m_y + v2.getY());

}

void Vector2D::normalize() {
	float l=length();
	if(l>0)
	{
		(*this) *=1/l;
	}
}
