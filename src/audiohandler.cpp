#include "audiohandler.h"

AudioHandler::AudioHandler() :
	currentMusic(nullptr),
	currentEffect(nullptr)
{

}

AudioHandler::~AudioHandler(){
	step("[Aim] Destroying.");
	if(this->currentMusic != nullptr){
		Mix_FreeMusic(this->currentMusic);
		this->currentMusic = nullptr;
	}
	if(this->currentEffect != nullptr){
		Mix_FreeChunk(this->currentEffect);
		this->currentEffect = nullptr;
	}
}

void AudioHandler::setCurrentMusic(const std::string& path_){
	if(this->currentMusic != nullptr){
		Mix_FreeMusic(this->currentMusic);
	}

	this->currentMusic = Mix_LoadMUS(path_.c_str());
}

void AudioHandler::playMusic(const int times_){
	if(this->currentMusic){
		Mix_PlayMusic(this->currentMusic, times_);
	}
}

void AudioHandler::stopMusic(){
	Mix_HaltMusic();	
}

void AudioHandler::setMusicVolume(const unsigned int percent_){
	const int value = percent_ * MIX_MAX_VOLUME/100;
	Mix_VolumeMusic(value);
}

void AudioHandler::setCurrentEffect(const std::string& path_){
	if(this->currentEffect)
		Mix_FreeChunk(this->currentEffect);

	this->currentEffect = Mix_LoadWAV(path_.c_str());
}

void AudioHandler::playEffect(const int times_){
	if(this->currentEffect){
		Mix_PlayChannel(1, this->currentEffect, times_);
	}
}

void AudioHandler::setEffectVolume(const unsigned int percent_){
	const int value = percent_ * MIX_MAX_VOLUME/100;
	Mix_Volume(1, value);
}

void AudioHandler::changeMusic(const std::string& path_){
	stopMusic();
	setCurrentMusic(path_);
	playMusic(MIX_LOOP);
}