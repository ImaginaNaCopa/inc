#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H

#define MIX_LOOP -1

#include <string>
#include <SDL2/SDL_mixer.h>

class AudioHandler 
{
public:
	AudioHandler();
	virtual ~AudioHandler();

	void playMusic(const int times_);
	void playEffect(const int times_);
	void stopMusic();
	void setMusicVolume(const unsigned int percent_);		
	void setEffectVolume(const unsigned int percent_);
	void changeMusic(const std::string& path_);
	void setCurrentMusic(const std::string& path_);
	void setCurrentEffect(const std::string& path_);

private:
	Mix_Music* currentMusic; 
	Mix_Chunk* currentEffect;
};

#endif //AUDIOHANDLER_H