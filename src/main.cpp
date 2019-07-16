/**
 * Main source file
 *
 * @author Fabio Marciano
 * @version 0.0.1
 *
 */

#include <SDL2/SDL.h>
#include <stdio.h>

// Screen dimension constants
const int SCREEN_LEN_X = 640;
const int SCREEN_LEN_Y = 480;
const char *SCREEN_TITLE = "Ngin-G";

int main(int argc, char *argv[]) {
	// The window we'll be rendering to
	SDL_Window *window = NULL;

	// The surface contained by the window
	SDL_Surface *screenSurface = NULL;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		//Create window
		window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_LEN_X, SCREEN_LEN_Y, SDL_WINDOW_SHOWN);
		if(window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		} else {
			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	// Destroy window
	SDL_DestroyWindow(window);

	// Quit SDL subsystems
	SDL_Quit();

	return 0;
}
