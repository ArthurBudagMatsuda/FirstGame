#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Maths.h"


Player::Player() :PlayerSpeed(1.0f), maxFireRate(500), fireRateTimer(0), municao(10), timerMunition(Inf), Inf(-69000000.0f)
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
	MunitionText.setPosition(Sprite.getPosition());
	//Sprite.setOrigin(sf::Vector2f(60,50));

}
void Player::Load() {
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

	if (font.loadFromFile("assets/fonts/Arial.ttf")) {
		std::cout << "Arial Font loaded" << "\n";

		MunitionText.setFont(font);
		MunitionText.setCharacterSize(24);
		MunitionText.setFillColor(sf::Color::Red);
	}
	else
	{
		std::cout << "Font Loaded Failed" << "\n";
	};
	
}

void Player::Update(float deltaTime,Enemy &enemy, sf::Vector2i& mousePosition )
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			timerMunition = 0.0f;
			
		}
		timerMunition += deltaTime;
		if (timerMunition > 1000.0f) {
			municao = 10;
			timerMunition = Inf;
		}


		fireRateTimer += deltaTime;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate && municao > 0) {
		
			bullets.push_back(Bullet());
			int i = bullets.size() - 1;
			bullets[i].initialize(Sprite.getPosition(), sf::Vector2f(mousePosition),1.4f);
			bullets[i].load();
			fireRateTimer = 0;
			municao--;
		}
		for (size_t i = 0; i < bullets.size(); i++) {
			//sf::Vector2f direction = enemy.getSSprite().getPosition() - bullets[i].getPosition();//calculate the direction of every single bullet  
			//sf::Vector2f direction = sf::Vector2f(mousePosition) - bullets[i].getPosition(); // aqui ele me da a direcao 
			//                          estou enviando o mouseposition de acordo com a window, se eu pegar o mousePosition global vai bugar
			//direction = maths::NormalizeVector(direction);// aqui eu normalizo cortando em partes menores
			//bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed  * deltaTime);
			bullets[i].Update(deltaTime);
			if (enemy.getHealth() > 0) {
				if (maths::CheckRectColision(bullets[i].GetGlobalBounds(), enemy.getSSprite().getGlobalBounds())) {
					enemy.setHealth(enemy.getHealth() - 10);
					bullets.erase(bullets.begin() + i);
				}
			}

		}
	

		boundingRectangle.setPosition(Sprite.getPosition());
		//if (maths::CheckRectColision(Sprite.getGlobalBounds(), enemy.getSSprite().getGlobalBounds())) {
		//	std::cout << "colidion";
		//}
		if (municao > 0) {
			MunitionText.setString(std::to_string(municao));
			MunitionText.setPosition(Sprite.getPosition());
		
		}
}

sf::Sprite Player::getSSprite()
{
	return Sprite;
}

void Player::setMunition()
{

	
}




void Player::Draw(sf::RenderWindow &window)
{
	if (municao > 0) {
		window.draw(MunitionText);
	}
	window.draw(Sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++) {
		bullets[i].Draw(window);
	}

}
