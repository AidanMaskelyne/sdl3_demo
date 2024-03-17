#include <filesystem>

#include <SDL3/SDL_log.h>
#include <toml++/toml.hpp>

#include "Config.h"

namespace fs = std::filesystem;

int Config::load(std::optional<fs::path> file_path)
{
	fs::path fp;

	if (!file_path.has_value())
	{
		fp = fs::current_path();
		fp.append("config.toml");
		SDL_Log("CONFIG: No TOML file supplied, loading %s instead", fp.c_str());
	} else
	{
		fp = fs::absolute(file_path.value());
		SDL_Log("Loading %s", fp.c_str());
	}

	toml::table tbl;
	try
	{
		tbl = toml::parse_file(fp.native());
	}
	catch (const toml::parse_error& err)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "CONFIG: Failed to parse TOML file: %s", err.what());
		return 1;
	}

	/* We can extract the value or a default value instead */
	width = tbl.at_path("display.resolution.width").value_or(640);
	height = tbl.at_path("display.resolution.height").value_or(480);

	vsync = tbl.at_path("display.vsync").value_or(true);

	return 0;
}
