/**
 * Music class file
 *
 * @author Fabio Marciano
 * @version 0.0.1
 *
 */

#include "include/Music.h"

Mix_Music *Music::music = NULL;
int Music::fade = MUSIC_FADE_DEFAULT;
std::string Music::file = MUSIC_FILE_EMPTY;
int Music::repeat = MUSIC_REPEAT_FOREVER;

bool Music::Load(const std::string filepath) {
	bool result = true;

	Music::Stop();

	try {
		if (filepath.empty()) throw "Path to file can not be empty";
		Music::file = filepath;

		if (!(Music::music = Mix_LoadMUS(Music::file.c_str()))) throw "Could not open given file";

	} catch(const std::string message) {
		result = false;
	}

	return result;
}

void Music::Stop(void) {
	while ((!Mix_FadeOutMusic(Music::fade)) && Mix_PlayingMusic()) {
		SDL_Delay(100);
	}
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
	if (filepath.empty()) throw "Path to file can not be empty";

	Music::Quit();
	if (Music::Load(filepath)) Music::Play();
}

void Music::Play() {
	if (Music::music && Mix_PlayingMusic() != 1) {
		Mix_FadeInMusic(Music::music, Music::repeat, Music::fade);
	}
}

void Music::Quit(void) {
	Music::Stop();
	Mix_FreeMusic(Music::music);
	Music::music = NULL;
}
