#include "mapLoader.h"
#include <fstream>
#include <string>
void mapLoader::load(std::string filename)
{
	std::string line;
	std::ifstream file(filename);
	bool mapExist = false;
	if (file.is_open()) {
		while (std::getline(file,line))
		{
			if (!mapExist) {
				if (line == "[Map]")
				{
					mapExist = true;
					continue;
				}
				else {
					std::cout << "Map sintax is corrupt or not valid";
					break;
				}
			}
			

			if (mapExist) {
				int count = line.find("=");
				std::string variable = line.substr(0, count);
				std::string value = line.substr(count +1, line.length() - count);

				std::cout << variable << "\n";
				std::cout << count << "\n";
		
			}
		}
		file.close();
	}
	else {
		std::cout << "unable to open: " << filename << "\n";
	}
}

void mapLoader::Save(std::string filename)
{

	std::ofstream                 file;
	file.open("mapa.txt");
	file << "This is my Map" << "\n";
	file << "		4,4,4,6, 6, 6" << "\n";
	file.close();
}
