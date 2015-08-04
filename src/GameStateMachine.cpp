/*
 * GameStateMachine.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: youssef
 */

#include "GameStateMachine.h"

GameStateMachine::GameStateMachine() {
	// TODO Auto-generated constructor stub
}

GameStateMachine::~GameStateMachine() {
	// TODO Auto-generated destructor stub
}
void GameStateMachine::pushstate(GameState *pState) {
	cout << "Push state"<<'\n';
	m_gameStates.push_back(pState);
	pState->onEnter();
}
void GameStateMachine::popState() {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->onExit()) {
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}

	}
}
void GameStateMachine::changeState(GameState *pState) {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->getStateID() == pState->getStateID()) {
			return;
		}
		if (m_gameStates.back()->onExit()) {
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
	m_gameStates.push_back(pState);
	pState->onEnter();

}
void GameStateMachine::render() {

	if(!m_gameStates.empty()){
		m_gameStates.back()->render();
	}else
	{
		cout<<"m_gameStates is Empty"<<'\n';
	}
}
void GameStateMachine::update() {
	if(!m_gameStates.empty()){
			m_gameStates.back()->update();
		}
}
