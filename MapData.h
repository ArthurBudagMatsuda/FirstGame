#pragma once
#include  <string>
struct MapData {

	std::string tilesheet = "";
	std::string name = "";

	int tilewidth = 0;
	int  tileheight = 0;

	int scalex = 0;
	int scaley = 0;

	int dataLenght = 0;
	int* data = nullptr;
};
