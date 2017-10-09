#include "GameObject.h"
#include "TextureManager.h"

bool GameObject::load(std::string fileName, std::string textureID, SDL_Renderer* m_renderer) {
	TextureManager::Instance()->load(fileName, textureID, m_renderer);
	return true;
}

void GameObject::render(std::string id, int x, int y, int width, int height, SDL_Renderer* m_renderer) {
	TextureManager::Instance()->draw(id, x, y, width, height, m_renderer);
}

void GameObject::close(std::string id) {
	TextureManager::Instance()->clearTexureMap(id);
}