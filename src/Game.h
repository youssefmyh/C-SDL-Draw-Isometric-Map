/*
 * Game.h
 *
 *  Created on: Jun 3, 2015
 *      Author: youssef
 */

#ifndef GAME_H_
#define GAME_H_
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"
#include "MenuObject.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
using namespace std;

enum game_states {
	MENU=0,
	PLAY=1,
	GAMEOVER=2
};
class Game {
public:
	~Game() {
	}
	static Game *instance() {
		if (s_pinstance == 0) {
			s_pinstance = new Game();
		}
		return s_pinstance;
	}
	bool init();
	bool init(const char * title, int xPos, int yPos, int w, int h, int flags);
	void render();
	void update();
	void handleEvenets();
	void clean();
	void quit();
	GameStateMachine* getGameStateMachine(){return m_pgameStateMachine;}
	bool running() {
		return m_bRunning;
	}
    
    int getGameWidth()const {
        return 1600;
    }
    
    int getGameHeight()const {
        return 800;
    }
	SDL_Renderer *getRenderer() const {
		return m_pRender;
	}
private:
	bool m_bRunning;
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRender;
	SDL_Texture *m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	int m_currentFrame;
	std::vector<GameObject*> m_gameObjects;
	GameObject *m_player;
	GameObject *m_enemy1;
	GameObject *m_enemy2;
	GameObject *m_enemy3;
	static Game *s_pinstance;
	int m_currentGameState;
    int m_width;
    int m_height;
	GameStateMachine*m_pgameStateMachine;
	Game() {
	}
};
typedef Game TheGame;

#endif /* GAME_H_ */
