#include "mapLoader.h"
#include <fstream>
#include <string>
void mapLoader::load(std::string filename ,MapData &data)
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

				std::cout << value << "\n";
				std::cout << variable << "\n";

				try
				{


					if (variable == "version") {
						data.version = std::stoi(value);
					}
					if (variable == "tilesheet") {
						data.tilesheet = value;

					}
					else if (variable == "name") {
						data.name = value;

					}
					else if (variable == "mapWidth") {

						data.mapWidht = std::stoi(value);

					}
					else if (variable == "mapHeight") {

						data.mapHeight = std::stoi(value);

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

						data.data = new int[data.dataLenght]; // lembrar de deletar
						int offset = 0;
						int i = 0;
						while (true)
						{

							int count = value.find(',', offset);
							std::string mapindex = value.substr(offset, count - offset);
							data.data[i] = std::stoi(mapindex);

							if (count == -1 )
								break;
							offset = count + 1;
							i++;
						}
						


					

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
