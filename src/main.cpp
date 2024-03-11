#include <SDL3/SDL.h>

int main(int argc, char *argv[])
{
	SDL_Version sdl_version;
	SDL_Window *window;

	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialise SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_GetVersion(&sdl_version);
	SDL_Log("Using SDL version %u.%u.%u", sdl_version.major, sdl_version.minor, sdl_version.patch);

	window = SDL_CreateWindow("SDL3 Demo", 640, 480, SDL_WINDOW_FULLSCREEN||SDL_WINDOW_VULKAN);
	if (window == NULL)
	{
		SDL_Log("Unable to create a window: %s", SDL_GetError());
		return 1;
	}

	SDL_Delay(3000);

	// --------------------------------------
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
