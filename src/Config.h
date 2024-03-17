#pragma once

#include <cstdint>
#include <string>
#include <filesystem>
#include <optional>

#include "SDL3/SDL_log.h"

enum class WindowMode
{
	Fullscreen,
	Windowed,
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
	int load(std::optional<std::filesystem::path> file_path);

public:
	uint32_t get_width() { return width; }
	uint32_t get_height() { return height; }

	bool vsync_enabled() { return vsync; }
	void set_vsync(bool enabled) { vsync = enabled; }

private:
	uint32_t width, height;
	WindowMode window_mode;
	bool vsync;
};
