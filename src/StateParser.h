/*
 * StateParser.h
 *
 *  Created on: Jun 25, 2015
 *      Author: youssef
 */

#ifndef STATEPARSER_H_
#define STATEPARSER_H_
#include <iostream>
#include <vector>
#include "tinyxml.h"
#include "TextureManager.h"
class GameObject;
using namespace std;
class StateParser {
public:
	StateParser();
	virtual ~StateParser();
	bool parseState(const char *stateFile, std::string stateID,
			std::vector<GameObject*> *pObjects,std::vector<std::string> *pTextureIDS);

private:
	void parseObjects(TiXmlElement *pStateRoot,	std::vector<GameObject*> *pObjects);
	void parseTextures(TiXmlElement *pStateRoot,std::vector<std::string> *pTextureIDS);

};

#endif /* STATEPARSER_H_ */
