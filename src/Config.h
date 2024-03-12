#pragma once

#include <string>
#include <filesystem>
#include <optional>

#include <SDL_log.h>

enum DisplayMode {
	Fullscreen,
	Windowed,
};

struct Settings_General {

};

struct Settings_Display {
	int width;
	int height;
	DisplayMode display_mode;
};

class Config
{
public:
	/**
	 * Load a config file in the INI format. If no path is provided, it attempts to load config.ini in the current directory.
	 * Will overwrite previous settings if called more than once
	 * 
	 * @param file_path - Path to a .ini file
	 */
	void load(std::optional<std::filesystem::path> file_path);

private:
	/* Each struct of options is a heading in the INI file */
	Settings_Display display_settings;	// e.g. [Display] heading
};