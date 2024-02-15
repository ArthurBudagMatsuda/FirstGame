#include "FrameText.h"
#include <iostream>
FrameText::FrameText(): timer (0) // when my constructor is called, inicialize my timer with zero, this is called member initialization	
{
	
}
FrameText::~FrameText()
{
}
void FrameText::Initialize()
{
}

void FrameText::Load()
{
	if (font.loadFromFile("assets/fonts/Arial.ttf")) {
		std::cout << "Arial Font loaded" << "\n";

		frameRateText.setFont(font);
		frameRateText.setCharacterSize(24);
		frameRateText.setFillColor(sf::Color::Red);
	}
	else
	{
		std::cout << "Font Loaded Failed" << "\n";
	};

}

void FrameText::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= 100.0f) {
		std::string frameRateTextString = "FPS: " + std::to_string((int)1000.0 / (int)deltaTime) + " framtime: " + std::to_string(deltaTime);

		frameRateText.setString(frameRateTextString);
		timer = 0;
	}

}

void FrameText::Draw(sf::RenderWindow& window)
{
	window.draw(frameRateText);
}
