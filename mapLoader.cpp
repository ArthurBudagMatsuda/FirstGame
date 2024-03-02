#include "mapLoader.h"
#include <fstream>
#include <string>
#include "MapData.h"
void mapLoader::load(std::string filename)
{
	MapData data;
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

				try
				{



					if (variable == "tilesheet") {
						data.tilesheet = value;

					}
					else if (variable == "name") {
						data.name = value;

					}
					else if (variable == "tileWidth") {

						data.tilewidth = std::stoi(value);

					}
					else if (variable == "tileHeight") {
						data.tileheight = std::stoi(value);

					}
					else if (variable == "scalex") {

						data.scalex = std::stoi(value);

					}
					else if (variable == "scaley") {

						data.scaley = std::stoi(value);

					}

					else if (variable == "dataSize") {

						data.dataLenght = std::stoi(value);

					}

					else if (variable == "data") {
						int count = value.find(',');
						std::string v = value.substr(0, count); 
						data.data = nullptr;
						int count2 = value.find(',',4);//o segundo argumento é de onde 
						v = value.substr(count, count2);


					}
				}
				catch (const std::exception&)
				{
					std::cout << "MapLoader catch failed." << filename << "\n";
				}
				
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
