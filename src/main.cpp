#include <SDL3/SDL.h>

#include <SDL3/SDL_render.h>
#include <cstdint>
#include <iostream>
#include <optional>

#include "Video.h"
#include "Input.h"
#include "Event.h"
#include "Config.h"

int load_application_settings(Config *config)
{
	if (config->load(std::nullopt) != 0)
	{
		return 1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	/* Load the application settings from the config file */
	Config config;
	if (load_application_settings(&config) != 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "FATAL: Failed to load application settings");
		return 1;
	}

	SDL_Window *window;
	SDL_Renderer *renderer;

	/* Init SDL */
	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialise SDL: %s", SDL_GetError());
		return 1;
	}

	/* Version info */
	SDL_Version sdl_version;
	SDL_GetVersion(&sdl_version);
	SDL_Log("Using SDL version %u.%u.%u", sdl_version.major, sdl_version.minor, sdl_version.patch);

	/* Create the window and rendering context */
	//SDL_Log("Creating window of resolution %ix%i", config.get_width(), config.get_height());
	//if (SDL_CreateWindowAndRenderer(config.get_width(), config.get_height(), 0, &window, &renderer) != 0)
	//{
	//	SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindowAndRenderer failed: %s", SDL_GetError());
	//	SDL_Quit();
	//	return 1;
	//}
	
	window = SDL_CreateWindow("SDL3 Demo", config.get_width(), config.get_height(), SDL_WINDOW_MOUSE_GRABBED);
	if (window == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "window was NULL: %s", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, NULL, config.vsync_enabled() ? SDL_RENDERER_PRESENTVSYNC : 0);
	if (renderer == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "renderer was NULL: %s", SDL_GetError());
		return 1;
	}

	/* Main window loop */
	SDL_Event event;
	bool running = true;
	while (running)
	{
		uint64_t start_tick = SDL_GetPerformanceCounter();

		SDL_PollEvent(&event);
		if (event.type == SDL_EVENT_QUIT)
			break;

		if (event.type == SDL_EVENT_KEY_DOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_v:
				Video::set_vsync(renderer, &config, !config.vsync_enabled());
				break;
			case SDLK_ESCAPE:
				Event::send_quit_event();
				break;
			default: break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		/* Timing stuff */
		uint64_t end_tick = SDL_GetPerformanceCounter();

		float elapsedMS = (end_tick - start_tick) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
	}

	/* SDL Cleanup */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	/* SDL_Quit() quits all the initialised subsystems */
	SDL_Quit();

	return 0;
}
