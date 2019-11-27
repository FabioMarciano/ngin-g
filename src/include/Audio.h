/**
 * Audio header file
 *
 * @author Fabio Marciano
 * @version 0.0.1
 *
 */

#ifndef __AUDIO_H__
    #define __AUDIO_H__ 1

	#include <string>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_mixer.h>

	class Audio {
		private:
			static bool status;
			Audio();

		public:
			static bool Init();
			static void Quit();
	};

#endif
