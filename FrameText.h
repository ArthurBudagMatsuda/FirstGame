#pragma once
#include <SFML/Graphics.hpp>
class FrameText
{
private:
	sf::Text  frameRateText;
	sf::Font font;
	float timer;

public:
	FrameText();	
	~FrameText();
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

