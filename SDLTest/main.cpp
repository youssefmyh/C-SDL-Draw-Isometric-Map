#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
#include "Vector2D.h"
using namespace std;
bool init(const char * title, int xPos, int yPos, int w, int h, int flags);

Game *g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
int main() {
    Uint32 framestart, frameTime;
    
    g_game = TheGame::instance();
    g_game->init("First Window", SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED, 2208, 1242, SDL_WINDOW_SHOWN);
    
    while (g_game->running()) {
        framestart = SDL_GetTicks();
        g_game->handleEvenets();
        g_game->update();
        g_game->render();
        frameTime = SDL_GetTicks() - framestart;
        if (frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        } else {
            SDL_Delay(DELAY_TIME);
        }
    }
    return 1;
}




/*
 SDL2 Isometric tile map test
 */
/*
// includes
#include <iostream>
#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

//global

bool quit = false;

const int WINDOW_W = 640;
const int WINDOW_H = 480;

const int TILECLIPS = 1;
const int TILECLIP_H = 128;
const int TILECLIP_W = 256;
SDL_Rect tileClip[TILECLIPS];

const int TILE_MAP_ROWS = 10;
const int TILE_MAP_COLUMNS = 10;
int tileMap[TILE_MAP_ROWS][TILE_MAP_COLUMNS] = {
    {8,8,0,8,4,4,4,5,5,5},
    {8,8,0,8,4,5,4,4,5,5},
    {8,8,0,8,4,4,4,5,5,4},
    {8,8,0,8,8,8,8,8,8,8},
    {8,8,0,0,0,0,0,0,0,0},
    {8,8,8,8,8,0,8,8,8,8},
    {8,8,8,8,8,0,8,8,8,8},
    {8,8,8,8,8,0,8,8,8,8},
    {8,8,8,8,8,0,8,8,8,8},
    {8,8,8,8,8,0,8,8,8,8}
};

const int tileVelocity = 10;
int tileVolocity_X = 0;
int tileVolocity_Y = 0;

SDL_Renderer * renderer = NULL;
SDL_Texture * loadTexture(std::string path);
SDL_Texture * tileTexture = NULL;

void init();
void loadMedia();
void events();

int main(int argc,char* argv[]){
    
    init();
    loadMedia();
    
    while(!quit)
    {
        events(); // check for user input
        
        //get x/y's to create isometric map
        for(int r = 0; r < TILE_MAP_ROWS; r++)
        {
            for(int c = 0; c < TILE_MAP_COLUMNS; c++)
            {
                // STARTING POSITION
                int start_x, start_y;
                start_x = (WINDOW_W/2) - (TILECLIP_W/2); // adjust x start position
                start_y = ((WINDOW_H/2) - (TILECLIP_H/2))/TILECLIP_W; // adjust y start position
                
                int x,y;
                x = start_x + ((c*(TILECLIP_W/2)) - (r*(TILECLIP_W/2)));
                y = start_y + (((r*TILECLIP_H) + (c*TILECLIP_H))/2);
                
                //MOVEMENT
                // include velocity
                x += tileVolocity_X;
                y += tileVolocity_Y;
                
                SDL_Rect tileRect;
                tileRect.h = TILECLIP_H;
                tileRect.w = TILECLIP_W;
                tileRect.x = x;
                tileRect.y = y;
                
                //go through each tile clip and each map array int and RenderCopy
                for(int i = 0; i < TILECLIPS; i++ )
                {
                    if(tileMap[r][c] == i)
                    {
                        SDL_RenderCopy(renderer,tileTexture,&tileClip[i],&tileRect);
                    }
                }
            }
        }
        
        SDL_RenderPresent(renderer); //display all render copies on window
        SDL_RenderClear(renderer);//clear renderer ready for next copy
    }
    return 0;
}

void init()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("windowName", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void events()
{
    SDL_Event keyEvent;
    while(SDL_PollEvent(&keyEvent))
    {
        //Check for quit
        if(keyEvent.type==SDL_QUIT)
        {
            quit=true;
        }
        
        if(keyEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            if(keyEvent.button.button == SDL_BUTTON_LEFT)
            {
                //mouseClick_x = keyEvent.button.x;
                //mouseClick_y = keyEvent.button.y;
            }
        }
        
        //check for key down
        if(keyEvent.type == SDL_KEYDOWN)
        {
            switch(keyEvent.key.keysym.sym)
            {
                case SDLK_UP: tileVolocity_Y -= tileVelocity; break;
                case SDLK_DOWN: tileVolocity_Y += tileVelocity; break;
                case SDLK_LEFT: tileVolocity_X -= tileVelocity; break;
                case SDLK_RIGHT: tileVolocity_X += tileVelocity; break;
            }
        }
        //check for key up
        if(keyEvent.type == SDL_KEYUP)
        {
            switch(keyEvent.key.keysym.sym)
            {
                case SDLK_UP: tileVolocity_Y += tileVelocity; break;
                case SDLK_DOWN: tileVolocity_Y -= tileVelocity; break;
                case SDLK_LEFT: tileVolocity_X += tileVelocity; break;
                case SDLK_RIGHT: tileVolocity_X -= tileVelocity; break;
            }
        }
    }
}

SDL_Texture* loadTexture(std::string path)
{
    SDL_Surface* windowSurface = NULL;
    
    std::cout << "\n--- LOAD PNG AND CONVERT INTO TEXTURE ---\n";
    SDL_Texture* newTexture = NULL;
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0x00, 0xFF));
    if(loadedSurface != NULL){std::cout << path << " was loaded." << std::endl;}
    else{std::cout << path << " was not loaded." << std::endl;}
    
    newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
    if(newTexture != NULL){std::cout << path << " was converted into a texture." << std::endl;}
    else{std::cout << "ERROR: " << path << " was not converted into a texture." << std::endl;}
    
    SDL_FreeSurface(loadedSurface);
    
    return newTexture;
}

void loadMedia()
{
    tileTexture = loadTexture("dirt.png");
    
    // Note: for this to work ALL tiles MUST have a y value of 0 in the .png image file
    for(int i = 0; i < TILECLIPS; i++)
    {
        tileClip[i].h = TILECLIP_H;
        tileClip[i].w = TILECLIP_W;
        tileClip[i].x = i * TILECLIP_W;
        tileClip[i].y = 0;
    }
}*/
