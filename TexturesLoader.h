#pragma once
#include <SFML/Graphics.hpp>
struct DataTexture {
	// uma regra criada apenas entre programadores é que struct e para apenas data , sem  funcoes
	int id = -1;
	sf::Texture* texture = nullptr;
	sf::Sprite sprite;
	
};