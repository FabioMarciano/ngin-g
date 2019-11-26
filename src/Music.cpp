/**
 * Music class file
 *
 * @author Fabio Marciano
 * @version 0.0.1
 *
 */

#include "include/Music.h"

Mix_Music *Music::music = NULL;

bool Music::Load(const std::string filepath) {
	bool result = true;

	Music::Stop();

	try {
		if (filepath.empty()) throw "Path to file can not be empty";

		if (!(Music::music = Mix_LoadMUS(filepath.c_str()))) throw "Could not open given file";

	} catch(const std::string message) {
		result = false;
	}

	return result;
}

void Music::Stop(void) {
	Mix_HaltMusic();
	Mix_RewindMusic();
}

void Music::Pause(void) {
	if (Mix_PlayingMusic()) {
		Mix_PauseMusic();
	}
}

void Music::Resume(void) {
	if (Mix_PausedMusic()) {
		Mix_ResumeMusic();
	}
}

void Music::Play(const std::string filepath) {
	Music::Quit();
	if (Music::Load(filepath)) Music::Play();
}

void Music::Play() {
	if (Music::music) Mix_PlayMusic(Music::music, -1);
}

void Music::Quit(void) {
	Music::Stop();
	Music::music = NULL;
}
