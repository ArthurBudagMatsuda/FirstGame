#include "sword.h"
#include <SFML/Graphics.hpp>
Sword::Sword()
{
}

Sword::~Sword()
{
}

void Sword::initialize(const sf::Vector2f& position)
{
	RectangleShape.setSize(sf::Vector2f(20.f, 100.f));
	RectangleShape.setFillColor(sf::Color::Red);
	RectangleShape.setPosition(sf::Vector2f(500, 300));
}

void Sword::Update()
{
}

void Sword::Draw(sf::RenderWindow& window)
{
	window.draw(RectangleShape);
}

void Sword::load()
{

}
