#pragma once
#include <SFML/Graphics.hpp>
class Map
{
private:
	sf::Vector2i size;
	sf::Texture TileSheetTexture;
	sf::Sprite Sprite[10];
	int tileWidht;
	int tileHeight;
	int TotalTilesX;
	int TotalTilesY;
public:
	Map();
	~Map();
	void initialize();
	void Update(float deltaTime);
	sf::Sprite getSSprite();
	void Load(); 
	void Draw(sf::RenderWindow& window);
};

