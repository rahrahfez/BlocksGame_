#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SDL_mixer.h>
#include <string>
#include <map>

enum sound_type {
	SOUND_MUSIC,
	SOUND_FX
};

class SoundManager {
	SoundManager();
	~SoundManager();
	static SoundManager* m_instance;
	std::map<std::string, Mix_Chunk*>m_sfx;
	std::map<std::string, Mix_Music*>m_music;

public:
	static SoundManager* Instance() {
		if (m_instance == 0) {
			m_instance = new SoundManager();
			return m_instance;
		}
		return m_instance;
	}
	bool load(std::string fileName, std::string id, sound_type type);
	void playSound(std::string id);
	void playMusic(std::string id, int loop);
};

#endif
