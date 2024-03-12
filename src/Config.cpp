#include <iostream>

#include "Config.h"

#define VAR_TO_STR(var) (#var)

namespace fs = std::filesystem;

void Config::load(std::optional<fs::path> file_path)
{
	fs::path fp;

	if (!file_path.has_value())
	{
		fp = fs::current_path();
		fp.append("config.ini");
		SDL_Log("No INI file supplied, loading %ls instead", fp.c_str());
	}
	else {
		fp = fs::absolute(file_path.value());
		SDL_Log("Loading %ls", fp.c_str());
	}
}