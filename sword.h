#pragma once
#include <SFML/Graphics.hpp>
class Sword
{
private:
	sf::Sprite Sprite;
	sf::RectangleShape RectangleShape;


public:

	Sword();
	~Sword();


	void initialize(const sf::Vector2f& position);
	void Update();
	void Draw(sf::RenderWindow& window);
	void load(); 


};

