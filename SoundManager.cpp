#include "SoundManager.h"

SoundManager* SoundManager::m_instance = 0;

SoundManager::SoundManager() {
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
}

SoundManager::~SoundManager() {
	Mix_CloseAudio();
}

bool SoundManager::load(std::string fileName, std::string id, sound_type type) {
	if(type == SOUND_MUSIC) {
		Mix_Music* music = Mix_LoadMUS(fileName.c_str());
		m_music[id] = music;
	}
	else if(type == SOUND_FX) {
		Mix_Chunk* sound = Mix_LoadWAV(fileName.c_str());
		m_sfx[id] = sound;
	}
	return true;
}

void SoundManager::playMusic(std::string id, int loop) {
	Mix_PlayMusic(m_music[id], loop);
}

void SoundManager::playSound(std::string id) {
	Mix_PlayChannel(-1, m_sfx[id], 0);
}
