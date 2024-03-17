#include "Event.h"

namespace Event
{
	/**
	 *	Send an application quit event
	 */
	void send_quit_event()
	{
		SDL_Log("Sending quit event...");
		SDL_Event quit_event;
		quit_event.type = SDL_EVENT_QUIT;
		SDL_PushEvent(&quit_event);
	}

	void poll_events()
	{

	}
}
