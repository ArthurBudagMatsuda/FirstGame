#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Maths.h"


Player::Player() :bulletSpeed(0.5f), PlayerSpeed(1.0f), maxFireRate(1000), fireRateTimer(0)
{
}

Player::~Player()
{
}

void Player::initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(120, 100);
	Sprite.scale(sf::Vector2f(2, 2));

	boundingRectangle.setSize(sf::Vector2f(size.x *Sprite.getScale().x, size.y * Sprite.getScale().y));

}

void Player::Update(float deltaTime,Enemy &enemy)
{
	sf::Vector2f postion = Sprite.getPosition();

	
		//bullet.setPosition(bullet.getPosition() + direction * bulletSpeed);

		//para ajustar o movimento bugado - multiplica a velocidade , pela difenca do frame atual pelo ultimo frame , ou seja frameatual - frameanterior , 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			Sprite.setPosition(postion + sf::Vector2f(1, 0) * PlayerSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {


			Sprite.setPosition(postion - sf::Vector2f(1, 0) * PlayerSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {


			Sprite.setPosition(postion - sf::Vector2f(0, 1) * PlayerSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

			Sprite.setPosition(postion + sf::Vector2f(0, 1) * PlayerSpeed * deltaTime);
		}


		fireRateTimer += deltaTime;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate) {

			bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
			int i = bullets.size() - 1;

			bullets[i].setPosition(Sprite.getPosition());

			fireRateTimer = 0;//mution -1 noob
		}
		for (size_t i = 0; i < bullets.size(); i++) {
			sf::Vector2f direction = enemy.getSSprite().getPosition() - bullets[i].getPosition();//calculate the direction of every single bullet  
			direction = maths::NormalizeVector(direction);
			bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed  * deltaTime);
		}
	

		boundingRectangle.setPosition(Sprite.getPosition());
		if (maths::CheckRectColision(Sprite.getGlobalBounds(), enemy.getSSprite().getGlobalBounds())) {
			std::cout << "colidion";
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
		Sprite.setTextureRect(sf::IntRect(Xindex * size.x, yindex * size.y, 120, 100));
		Sprite.setPosition(sf::Vector2f(400, 400));
	}
	else {
		std::cout << "Player Texture Failed.";
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(Sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}

}
