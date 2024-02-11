#include "Maths.h"
#include <SFML/Graphics.hpp>




sf::Vector2f maths::NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f NormalizedVector;
	NormalizedVector.x = vector.x / m;
	NormalizedVector.y = vector.y / m;
	return NormalizedVector;
}

bool maths::CheckRectColision(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (rect1.left + rect1.width > rect2.left && rect2.left + rect2.width > rect1.left &&
		
		rect2.top + rect2.height > rect1.top && rect1.top + rect2.height > rect2.top
		)
		return true;

	return false;
}
