/*
 * LoaderParams.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Home
 */

#ifndef LOADERPARAMS_H_
#define LOADERPARAMS_H_
#include <iostream>
using namespace std;
class LoaderParams {
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID) :
		m_x(x), m_y(y), m_width(width), m_height(height), m_texureID(textureID) {

	}
	LoaderParams(int x, int y, int width, int height, int numOfFrames,
			int animateSpeed, int callBackID, std::string textureID) :
		m_x(x), m_y(y), m_width(width), m_height(height),
				m_numOfFrames(numOfFrames), m_animateSpeed(animateSpeed),
				m_callBackID(callBackID), m_texureID(textureID) {

	}
	virtual ~LoaderParams();

	int getX() const {
		return m_x;
	}
	int getY() const {
		return m_y;
	}
	int getWidth() const {
		return m_width;
	}
	int getHeight() const {
		return m_height;
	}
	int getCallBackID() const {
		return m_callBackID;
	}
	int getNumOfFrames() const {
		return m_numOfFrames;
	}
	int getAnimateSpeed() const {
		return m_animateSpeed;
	}
	std::string getTextureID() const {
		return m_texureID;
	}

private:
	int m_x, m_y, m_width, m_height, m_numOfFrames,
			m_animateSpeed,m_callBackID;
	std::string m_texureID;
};

#endif /* LOADERPARAMS_H_ */
