#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Text  healthText;
	sf::Font font;

	int health;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:

	Enemy();
	~Enemy();
	void initialize();//<- called once p App Start
	void Update(float deltaTime);//<- called once p App start
	sf::Sprite getSSprite();
	void Load();//<- called once p frame
	void Draw(sf::RenderWindow& window);//<- called once p frame
	int getHealth();
	int setHealth(int x);
};

