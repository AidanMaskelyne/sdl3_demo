#include "Video.h"

namespace Video
{
	void window_set_display_mode(SDL_Window *window, WindowMode window_mode)
	{

	}

	// TODO: Check for errors after setting VSync
	void set_vsync(SDL_Renderer *renderer, Config *config, bool enabled)
	{
		int vsync;
		SDL_GetRenderVSync(renderer, &vsync);

		if (vsync == 0 && enabled)
		{
			SDL_Log("Toggling VSync on");
			SDL_SetRenderVSync(renderer, 1);
			config->set_vsync(true);
		}
		else if (vsync == 1 && !enabled)
		{
			SDL_Log("Toggling VSync off");
			SDL_SetRenderVSync(renderer, 0);
			config->set_vsync(false);
		}
	}
}
