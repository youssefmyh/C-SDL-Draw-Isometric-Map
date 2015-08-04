/*
 * TextureManager.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: youssef
 */

#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager() {
	// TODO Auto-generated constructor stub

}

TextureManager::~TextureManager() {
	// TODO Auto-generated destructor stub
}

bool TextureManager::load(std::string fileName, std::string id,
		SDL_Renderer *pRenderer) {
	SDL_Surface *m_surface = IMG_Load(fileName.c_str());
	if (m_surface == 0) {
		return false;
	}
	SDL_Texture *m_texure = SDL_CreateTextureFromSurface(pRenderer, m_surface);
	SDL_FreeSurface(m_surface);
	if (m_texure != 0) {
		m_textureMap[id] = m_texure;
	}
	return true;

}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer*pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0,
			flip);

}

void TextureManager::drawFrame(std::string id, int x, int y, int width,
		int height, int currentRow, int currentFrame, SDL_Renderer*pRenderer,
		SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0,
			flip);
}

void TextureManager::drawTile(std::string id, int margin, int
                              spacing, int x, int y, int width, int height, int currentRow,
                              int currentFrame, SDL_Renderer *pRenderer)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = margin + (spacing + width) * currentFrame;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
                     &destRect, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::drawTile(std::string id, int margin, int
                              spacing, int width, int height, int currentRow,
                              int currentCol, SDL_Renderer *pRenderer,SDL_Rect *destRect)
{
    SDL_Rect srcRect;
    srcRect.x = margin + (spacing + width) * currentCol;
    srcRect.y = margin + (spacing + height) * currentRow;
    srcRect.w =  width;
    srcRect.h =  height;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
                     destRect, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::clearFromTextureMap(std::string id)
   {
     m_textureMap.erase(id);
   }
