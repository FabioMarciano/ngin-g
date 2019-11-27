#include "./include/Audio.h"

bool Audio::status = false;

bool Audio::Init() {
	if (!Audio::status) {
		new Audio();
	}
	return Audio::status;
}

void Audio::Quit() {
	Mix_Quit();
	Audio::status &= false;
}

Audio::Audio() {
	Audio::status &= (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) >= 0);
}
