#pragma once
#include <SFML/Graphics.hpp>
class maths
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static bool CheckRectColision(sf::FloatRect rect1, sf::FloatRect rect2);

};

