#pragma once
#include <SFML/Graphics.hpp>
struct tile {
public:
	int id = -1;
	//sf::Texture* texture = nullptr;
	//sf::IntRect rect; // x,y,w,h <- necessita de 4 floats mt pesado noob
	sf::Vector2i position; // x , y 

};