#include "Enemy.h"
#include <iostream>
void Enemy::initialize()
{
}

void Enemy::Update()
{
}

sf::Sprite Enemy::getSSprite()
{
	return Sprite;
}

void Enemy::Load()
{
	if (Texture.loadFromFile("assets/player/texture/ramatra.png")) {//fazer uma classe load game para dar load em tudo 
		std::cout << "Enemy Texture Loaded.";
		Sprite.setTexture(Texture);

		int Xindex = 2;//120
		int yindex = 2;//100
		//X,Y,width,height
		//Sprite.setTextureRect(sf::IntRect(Xindex * 120, yindex * 100, 120, 100));
		Sprite.setPosition(sf::Vector2f(100, 100));
		//Sprite.scale(sf::Vector2f(2, 2));
	}
	else {
		std::cout << "Enemy Texture Failed.";
	}
}

void Enemy::Draw(sf::RenderWindow& window)
{
	return window.draw(Sprite);
}

