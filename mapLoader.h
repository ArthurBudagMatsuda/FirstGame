#pragma once
#include <iostream>
#include "MapData.h"


class mapLoader
{
private:
public:
	void load(std::string filename,MapData& data);
	void Save(std::string filename);

};

