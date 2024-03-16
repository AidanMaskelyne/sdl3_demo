#pragma once

#include <string>
#include <filesystem>
#include <optional>

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
};
