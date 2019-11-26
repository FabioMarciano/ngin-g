/**
 * Music class header file
 *
 * @author Fabio Marciano
 * @version 0.0.1
 *
 */

#ifndef __MUSIC_H__
    #define __MUSIC_H__ 1

	#include <string>
	#include "SDL2/SDL_mixer.h"

	class Music {
		private:

		/**
		 * @type Mix_Music - Music handle pointer
		 * @static
		*/
		static Mix_Music *music;

		public:

		/**
		 * @static - Loads the music file
		 * @param {string} filepath - The path to the file to be loaded
		 * @returns {bool} - True if file is loaded with success
		*/
		static bool Load(const std::string filepath);

		/**
		 * @static - Stop the current execution an unloads the music file
		*/
		static void Quit(void);

		/**
		 * @static - Loads and plays an given file
		 * @param {string} - The file to be loaded
		*/
		static void Play(const std::string filepath);

		/**
		 * @static - Plays an previous loaded file
		*/
		static void Play(void);

		/**
		 * @static - Stops an execution
		*/
		static void Stop(void);

		/**
		 * @static - Pauses an execution
		*/
		static void Pause(void);

		/**
		 * @static - Resume an paused execution
		*/
		static void Resume(void);
	};

#endif
