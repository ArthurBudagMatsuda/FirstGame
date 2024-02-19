#pragma once
#include <SFML/Graphics.hpp>
#include "tiles.h"
class Map
{
public:
	sf::Vector2i size;
	sf::Texture TileSheetTexture;
	int totalTiles;
	tile* tiles;
	int tileWidht;
	int tileHeight;
	int TotalTilesX;
	int TotalTilesY;
	int tileIds[6] = {
		4,4,4,
		6,6,6
	};
	sf::Sprite mapSprites[6];

	Map();
	~Map();
	void initialize();
	void Update(double deltaTime);
	sf::Sprite getSSprite();
	void Load(); 
	void Draw(sf::RenderWindow& window);
};

