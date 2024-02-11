#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

public:
	void initialize();//<- called once p App Start
	void Update();//<- called once p App start
	sf::Sprite getSSprite();
	void Load();//<- called once p frame
	void Draw(sf::RenderWindow& window);//<- called once p frame

};

