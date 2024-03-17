#pragma once

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_events.h>

namespace Event
{
	void send_quit_event();
	void poll_event();
}
