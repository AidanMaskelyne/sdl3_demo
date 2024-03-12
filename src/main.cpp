#include <SDL3/SDL.h>

int main(int argc, char *argv[])
{
	SDL_Version sdl_version;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialise SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_GetVersion(&sdl_version);
	SDL_Log("Using SDL version %u.%u.%u", sdl_version.major, sdl_version.minor, sdl_version.patch);

	if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_FULLSCREEN, &window, &renderer) != 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindowAndRenderer failed: %s", SDL_GetError());
		return 1;
	}

	if (window == NULL || renderer == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to create a window/renderer: %s", SDL_GetError());
		return 1;
	}

	while (true)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_EVENT_QUIT)
			break;

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	// --------------------------------------
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
