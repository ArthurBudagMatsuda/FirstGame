#include "map.h"
#include <iostream>
#include "tiles.h"
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
		totalTiles = TotalTilesX * TotalTilesY;
		tiles = new tile[totalTiles];
		for (int y = 0; y < TotalTilesY; y++)
		{
			for (int x = 0; x < TotalTilesX; x++)
			{
				int i = x + y * TotalTilesX;
				tiles[i].id = i;
				//tiles[i].texture = &TileSheetTexture;
				tiles[i].position = sf::Vector2i(x * tileWidht, y * tileHeight); // rect to cortando o mapa para   a parte especifica
				//tiles[i].sprite.setTexture(TileSheetTexture);
				//sf::IntRect(x * tileWidht, y * tileHeight, tileWidht, tileHeight);

				//tiles[i].sprite.setScale(sf::Vector2f(3, 3));
				//tiles[i].sprite.setPosition(sf::Vector2f(10+ x * tileWidht * 3, 10 +y * tileWidht * 3 ));
			}

	
		}

	}
	else {
		std::cout << "Map Texture Failed.";
	}

	for (int y = 0; y < 2; y++) // drawing a specific part

	{
		for (int x = 0; x < 3; x++)
		{
			int i = x + y * 3;
			int index = tileIds[i];
			mapSprites[i].setTexture(TileSheetTexture);//*tiles eu to desreferenciando
			//mapSprites[i].setTexture(*tiles[index].texture);//*tiles eu to desreferenciando
			mapSprites[i].setTextureRect(sf::IntRect(tiles[index].position.x,
				tiles[index].position.y,
				tileWidht,
				tileHeight));
			mapSprites[i].setScale(sf::Vector2f(3, 3));
			mapSprites[i].setPosition(sf::Vector2f(x * 32 * 3, y * 16 * 3));
		}

	}
}
void Map::Update(double deltaTime)
{
}

sf::Sprite Map::getSSprite()
{
	return sf::Sprite();
}



void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 6; i++)
	{
		window.draw(mapSprites[i]);

	}
}
