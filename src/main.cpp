#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>

void toggle_fullscreen(SDL_Window* window)
{
	bool is_fullscreen = SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;

	SDL_SetWindowFullscreen(window, is_fullscreen ? 0 : SDL_WINDOW_FULLSCREEN);
}

void set_window_resolution(SDL_Window *window, int w, int h)
{
	
}

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialise SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_Version sdl_version;
	SDL_GetVersion(&sdl_version);
	SDL_Log("Using SDL version %u.%u.%u", sdl_version.major, sdl_version.minor, sdl_version.patch);

	if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) != 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindowAndRenderer failed: %s", SDL_GetError());
		return 1;
	}

	if (window == NULL || renderer == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "window or renderer was NULL: %s", SDL_GetError());
		return 1;
	}

	SDL_Event event;
	while (true)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_EVENT_QUIT)
			break;

		if (event.type == SDL_EVENT_KEY_DOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_f:		// Go fullscreen when F is pressed
				if (event.key.keysym.mod == 0)
					toggle_fullscreen(window);
				break;
			case SDLK_ESCAPE:	// Quit the program when ESCAPE is pressed
				SDL_Event quit_event;
				quit_event.type = SDL_EVENT_QUIT;
				SDL_PushEvent(&quit_event);
			default: break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x00);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	// Cleanup
	// --------------------------------------
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
