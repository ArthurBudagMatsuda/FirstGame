#include "map.h"
#include <iostream>
Map::Map() :tileWidht(16), tileHeight(16), TotalTilesX(0), TotalTilesY(0)
{
}

Map::~Map()
{
}

void Map::initialize()
{
}

void Map::Load()
{
	if (TileSheetTexture.loadFromFile("assets/Maps/MapTest.png")) {
		TotalTilesX = TileSheetTexture.getSize().x / tileWidht;
		TotalTilesY = TileSheetTexture.getSize().y / tileHeight;

		std::cout << TotalTilesX;
		std::cout << TotalTilesY;
		std::cout << "Map Texture Loaded.";
		for (size_t i = 0; i < 10; i++) {
			Sprite[i].setTexture(TileSheetTexture);
			Sprite[i].setTextureRect(sf::IntRect(i * tileWidht, 0 * tileHeight, tileWidht, tileHeight));
			Sprite[i].setScale(sf::Vector2f(5, 5));
			Sprite[i].setPosition(sf::Vector2f(100 + i * tileWidht * 5,  100 ));
		}

	}
	else {
		std::cout << "Map Texture Failed.";
	}
}
void Map::Update(float deltaTime)
{
}

sf::Sprite Map::getSSprite()
{
	return sf::Sprite();
}



void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 10; i++) {
		window.draw(Sprite[i]);

	}
}
