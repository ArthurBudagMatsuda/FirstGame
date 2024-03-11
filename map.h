#pragma once
#include <SFML/Graphics.hpp>
#include "tiles.h"
#include"mapLoader.h"
#include "MapData.h"
class Map
{
public:
	sf::Vector2i size;
	sf::Texture TileSheetTexture;
	int totalTiles;
	tile* tiles;
	mapLoader mapLoader;
	MapData md;
	int TotalTilesX;
	int TotalTilesY;
	//static const int mapSize = 6;
	//int tileIds[mapSize] = {
	//	4,4,4,
	//	6,6,6
	//};

	sf::Sprite* mapSprites;

	Map();
	~Map();
	void initialize();
	void Update(double deltaTime);
	sf::Sprite getSSprite();
	void Load(); 
	void Draw(sf::RenderWindow& window);
};

