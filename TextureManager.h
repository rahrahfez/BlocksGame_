#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <map>

class TextureManager {
	std::map<std::string, SDL_Texture*> m_textureMap;
	SDL_Texture* m_texture;
	int m_width, m_height;
public:
	TextureManager() : m_width(0), m_height(0) {}
	~TextureManager() {}
	bool load(std::string fileName, std::string textureID, SDL_Renderer* m_renderer);
	void draw(std::string id, float x, float y, int width, int height, SDL_Renderer* m_renderer); // still frames 'background' 'blocks' ' ball'
	void drawFrame(std::string id, float x, float y, int width, int height, int frame, SDL_Renderer* m_renderer); // render frame
	bool loadText(std::string id, std::string string, TTF_Font* font, SDL_Color color, SDL_Renderer* m_renderer);
	void drawText(std::string id, int x, int y, SDL_Renderer* m_renderer);
	std::map<std::string, SDL_Texture*> getTextureMap() { return m_textureMap; }
	void clearTexureMap(std::string id);
};
#endif
 //testing changes