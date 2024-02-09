#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Maths.h"


void Player::initialize()
{
}

void Player::Update(Enemy &enemy)
{
	sf::Vector2f postion = Sprite.getPosition();

	
		//bullet.setPosition(bullet.getPosition() + direction * bulletSpeed);

		//para ajustar o movimento bugado - multiplica a velocidade , pela difenca do frame atual pelo ultimo frame , ou seja frameatual - frameanterior , 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			Sprite.setPosition(postion + sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {


			Sprite.setPosition(postion - sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {


			Sprite.setPosition(postion - sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

			Sprite.setPosition(postion + sf::Vector2f(0, 1));
		}



		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
			int i = bullets.size() - 1;

			bullets[i].setPosition(Sprite.getPosition());


		}
		for (size_t i = 0; i < bullets.size(); i++) {
			sf::Vector2f direction = enemy.getSSprite().getPosition() - bullets[i].getPosition();//calculate the direction of every single bullet  
			direction = maths::NormalizeVector(direction);
			bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);
		}
	
	
}

sf::Sprite Player::getSSprite()
{
	return Sprite;
}


void Player::Load(){
	if (PlayerTexture.loadFromFile("assets/player/texture/SpriteSheets.png")) {//fazer uma classe load game para dar load em tudo 
		std::cout << "Player Texture Loaded.";
		Sprite.setTexture(PlayerTexture);

		int Xindex = 2;//120
		int yindex = 2;//100
		//X,Y,width,height
		Sprite.setTextureRect(sf::IntRect(Xindex * 120, yindex * 100, 120, 100));
		Sprite.setPosition(sf::Vector2f(400, 400));
		Sprite.scale(sf::Vector2f(2, 2));
	}
	else {
		std::cout << "Player Texture Failed.";
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(Sprite);

	for (size_t i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}

}
