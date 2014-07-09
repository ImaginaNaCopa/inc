#include "audiohandler.h"

namespace audioHandler
{
	Mix_Music* currentMusic = NULL; 
	Mix_Chunk* currentEffect = NULL;

	void setCurrentMusic(const std::string& path_){
		if(currentMusic != nullptr){
			Mix_FreeMusic(currentMusic);
		}

		currentMusic = Mix_LoadMUS(path_.c_str());
	}

	void playMusic(const int times_){
		if(currentMusic){
			Mix_PlayMusic(currentMusic, times_);
		}
	}

	void stopMusic(){
		Mix_HaltMusic();	
	}

	void setMusicVolume(const unsigned int percent_){
		const int value = percent_ * MIX_MAX_VOLUME/100;
		Mix_VolumeMusic(value);
	}

	void setCurrentEffect(const std::string& path_){
		if(currentEffect)
			Mix_FreeChunk(currentEffect);

		currentEffect = Mix_LoadWAV(path_.c_str());
	}

	void playEffect(const int times_){
		if(currentEffect){
			Mix_PlayChannel(1, currentEffect, times_);
		}
	}

	void setEffectVolume(const unsigned int percent_){
		const int value = percent_ * MIX_MAX_VOLUME/100;
		Mix_Volume(1, value);
	}

	void changeMusic(const std::string& path_){
		stopMusic();
		setCurrentMusic(path_);
		playMusic(MIX_LOOP);
	}


}