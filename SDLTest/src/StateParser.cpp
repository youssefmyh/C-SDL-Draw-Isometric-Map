/*
 * StateParser.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: Home
 */

#include "StateParser.h"
#include "Game.h"
#include "GameObjectFactory.h"
#include "MenuButtonCreator.h"
StateParser::StateParser() {
	// TODO Auto-generated constructor stub
	   TheGameObjectFactory::instance()->registerType("playbutton", new
	   MenuButtonCreator());
	   TheGameObjectFactory::instance()->registerType("exitbutton", new
	 	   MenuButtonCreator());
}

StateParser::~StateParser() {
	// TODO Auto-generated destructor stub
}

bool StateParser::parseState(const char *stateFile, std::string stateID,
		std::vector<GameObject*> *pObjects,
		std::vector<std::string> *pTextureIDS) {

	cout<<"File ready"<<'\n';
	TiXmlDocument xmlDoc;
	if (!xmlDoc.LoadFile(stateFile)) {
		cout << "not able to load file " << '\n' << stateFile;
		return false;
	}
	TiXmlElement *pRoot = xmlDoc.RootElement();
	TiXmlElement *pStateRoot = 0;
	cout<<"File ready";

	for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		if (e->Value() == stateID) {
		 pStateRoot = e;
		}

	}

	TiXmlElement *pTextureRoot = 0;
	 cout<<"pTextureRoot ready"<<'\n';

	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		if (e->Value() == string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}


	TiXmlElement *pObjectsRoot = 0;

	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		if (e->Value() == string("OBJECTS")) {
			pObjectsRoot = e;
		}
	}

	parseTextures(pTextureRoot, pTextureIDS);
	 cout<<"pTextureRoot loaded"<<pTextureRoot->Value()<<'\n';
	 cout<<"pObjectsRoot loaded"<<pObjectsRoot->Value()<<'\n';

	parseObjects(pObjectsRoot, pObjects);

	return true;
}

void StateParser::parseObjects(TiXmlElement *pStateRoot,
		std::vector<GameObject*> *pObjects) {
	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement())
	{


       // <object type="MenuButton" x="100" y="100" width="400" height="100" textureID="playbutton" numFrames="0" callbackID="1"/>
		int x,y,width,height,numFrames,callbackID,animSpeed;
		string textureID;
		textureID=e->Attribute("textureID");
		e->Attribute("x",&x);
		e->Attribute("y",&y);
		e->Attribute("numFrames",&numFrames);
		e->Attribute("width",&width);
		e->Attribute("height",&height);
		e->Attribute("callbackID",&callbackID);
		e->Attribute("animSpeed",&animSpeed);
		GameObject *gameObject=TheGameObjectFactory::instance()->create(textureID);
		gameObject->load(new LoaderParams(x,y,width,height,numFrames,animSpeed,callbackID,textureID));
		pObjects->push_back(gameObject);
	}
}
void StateParser::parseTextures(TiXmlElement *pStateRoot,
		std::vector<std::string> *pTextureIDS) {
	for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e=e->NextSiblingElement()) {
		string fileName = e->Attribute("filename");
		string fileID = e->Attribute("ID");
		pTextureIDS->push_back(fileID);
		TheTextureManager::Instance()->load(fileName, fileID,TheGame::instance()->getRenderer());
	}
}

