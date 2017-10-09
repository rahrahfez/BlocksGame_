#include "TextureManager.h"

bool TextureManager::load(std::string fileName, std::string textureID, SDL_Renderer* m_renderer) {
	SDL_Surface* tempSurface = SDL_LoadBMP(fileName.c_str());
	SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0xFF, 0, 0xFF));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	if (texture != 0) {
		m_textureMap[textureID] = texture;
		return true;
	}
	return false;
}

void TextureManager::draw(std::string id, float x, float y, int width, int height, SDL_Renderer* m_renderer) {
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopy(m_renderer, m_textureMap[id], &srcRect, &dstRect);
}

void TextureManager::drawFrame(std::string id, float x, float y, int width, int height, int frame, SDL_Renderer* m_renderer) {
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	srcRect.x = width * frame;
	srcRect.y = height / 4;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopy(m_renderer, m_textureMap[id], &srcRect, &dstRect);
}

bool TextureManager::loadText(std::string id, std::string string, TTF_Font* font, SDL_Color color, SDL_Renderer* m_renderer) {
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, string.c_str(), color);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
	if (m_texture == NULL) return false;
	m_width = textSurface->w;
	m_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	if (m_texture != 0) {
		m_textureMap[id] = m_texture;
		return false;
	}
	return true;
} 

void TextureManager::drawText(std::string id, int x, int y, SDL_Renderer* m_renderer) {
	SDL_Rect srcRect = { 0, 0, m_width, m_height };
	SDL_Rect dstRect = { x, y, m_width, m_height };
	SDL_RenderCopy(m_renderer, m_textureMap[id], &srcRect, &dstRect);
}

void TextureManager::clearTexureMap(std::string id) {
	m_textureMap.erase(id);
}
