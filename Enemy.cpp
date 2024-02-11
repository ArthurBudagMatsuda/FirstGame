#include "Enemy.h"
#include <iostream>
void Enemy::initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Green);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(120, 100);
	Sprite.scale(sf::Vector2f(2, 2));

	boundingRectangle.setSize(sf::Vector2f(size.x * Sprite.getScale().x, size.y * Sprite.getScale().y));
}

void Enemy::Update()
{
	boundingRectangle.setPosition(Sprite.getPosition());

}

sf::Sprite Enemy::getSSprite()
{
	return Sprite;
}

void Enemy::Load()
{
	if (Texture.loadFromFile("assets/player/texture/SpriteSheets.png")) {//fazer uma classe load game para dar load em tudo 
		std::cout << "Enemy Texture Loaded.";
		Sprite.setTexture(Texture);

		int Xindex = 2;//120
		int yindex = 2;//100
		//X,Y,width,height
		// 
		//Sprite.setTextureRect(sf::IntRect(Xindex * 120, yindex * 100, 120, 100));
		Sprite.setTextureRect(sf::IntRect(Xindex * size.x, yindex * size.y, 120, 100));
		Sprite.setPosition(sf::Vector2f(100, 100));
		//Sprite.scale(sf::Vector2f(2, 2));
	}
	else {
		std::cout << "Enemy Texture Failed.";
	}

}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(boundingRectangle);
	 window.draw(Sprite);
}

