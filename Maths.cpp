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
