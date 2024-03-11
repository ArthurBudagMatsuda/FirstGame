#include "map.h"
#include <iostream>
#include "tiles.h"

Map::Map() : TotalTilesX(0), TotalTilesY(0), totalTiles(0),tiles(nullptr)
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

	mapLoader.load("assets/Maps/level1.vit", md);

	mapSprites = new sf::Sprite[md.dataLenght];
	if (TileSheetTexture.loadFromFile(md.tilesheet)) {











		TotalTilesX = TileSheetTexture.getSize().x / md.tilewidth;
		TotalTilesY = TileSheetTexture.getSize().y / md.tileheight;

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
				tiles[i].position = sf::Vector2i(x * md.tilewidth, y * md.tileheight); // rect to cortando o mapa para   a parte especifica

				//tiles[i].texture = &TileSheetTexture;
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

	for (int y = 0; y < md.mapHeight; y++) // drawing a specific part

	{
		for (int x = 0; x < md.mapWidht; x++)
		{
			int i = x + y * md.mapWidht;
			int index = md.data[i];
			mapSprites[i].setTexture(TileSheetTexture);//*tiles eu to desreferenciando
			//mapSprites[i].setTexture(*tiles[index].texture);//*tiles eu to desreferenciando
			mapSprites[i].setTextureRect(sf::IntRect(tiles[index].position.x,
				tiles[index].position.y,
				md.tilewidth,
				md.tileheight));

			mapSprites[i].setPosition(sf::Vector2f(x * md.tilewidth * mapSprites[i].getScale().x, y * md.tileheight * mapSprites[i].getScale().y));
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
	for (size_t i = 0; i < md.dataLenght; i++)
	{
		window.draw(mapSprites[i]);

	}
}
