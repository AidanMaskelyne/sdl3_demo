#include <filesystem>
#include <iostream>
#include <optional>
#include <string>
#include <fstream>

namespace fs = std::filesystem;

struct Display {
	int width, height;
};

struct Settings {
	Display display;
};

void parse_ini(std::optional<std::filesystem::path> file_path, Settings *settings)
{
	fs::path fp;

	if (!file_path.has_value())
	{
		fp = fs::current_path();
		fp.append("config.ini");
		std::wcout << "No INI file supplied, loading " << fp.native() << " instead" << std::endl;
	}
	else {
		fp = fs::absolute(file_path.value());
		std::wcout << "Loading " << fp.native() << std::endl;
	}

	std::ifstream file(fp);

	if (!file.is_open())
	{
		std::wcout << "ERROR: failed to open " << fp.native() << std::endl;
	}

	std::vector<std::string> file_contents;
	std::string line;
	while (std::getline(file, line))
	{
		file_contents.push_back(line);
	}

	std::cout << std::endl << "FILE CONTENTS: " << std::endl;
	for (int i = 0; i < file_contents.size(); i++)
	{
		std::cout << file_contents[i] << std::endl;
	}

	file.close();
}