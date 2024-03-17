/* Video.h */
#pragma once

#include "Config.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

namespace Video
{
	enum class WindowMode
	{
		Fullscreen,
		Windowed,
	};

	/**
	 * Change a specified window's display mode between fullscreen and normal windowed.
	 *
	 * @param window_mode The new window mode to set the window to
	 */
	void window_set_display_mode(SDL_Window *window, WindowMode window_mode);

	/**
	 * Enabled/disable VSync for a specified renderer
	 *
	 * @param enabled Whether VSync should be enabled or not
	 */
	void set_vsync(SDL_Renderer *renderer, Config *config, bool enabled);
}
