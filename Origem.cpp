#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Player.h"
#include"Enemy.h"
#include "FrameText.h";
#include "map.h";

int main() {


	//-------------INITIALIZE-----------------
	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME",sf::Style::Default, settings);
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME",sf::Style::Default);
	window.setFramerateLimit(120);
	//sf::RectangleShape bullet(sf::Vector2f(20, 10));
	//-------------INITIALIZE-----------------

	FrameText frameRate;
	frameRate.Initialize();
	Map map;
	Player Myplayer;
	Enemy demon;
	
	Myplayer.initialize();
	demon.initialize();
	map.initialize();
	///------------------LOAD-----------------
	Myplayer.Load();
	map.Load();
	demon.Load();
	frameRate.Load();
	///------------------LOAD-----------------

	sf::Time deltaTimeTimer;
	sf::Clock clock;
	double deltaTime = 0;
	while (window.isOpen())
	{


		
		// -------------- UPDATE ---------------- // 
		sf::Event event; // criando um objeto chamado event
		while (window.pollEvent(event))// looping na fila de eventos (queue fila em ingles) 
		{
	
			// se o tipo for close fechar
			if (event.type == sf::Event::Closed) {
				window.close();

			}

			
		}
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		demon.Update(deltaTime);
		map.Update(deltaTime);
		Myplayer.Update(deltaTime, demon, mousePosition);
		clock.restart();
		 deltaTime = deltaTimeTimer.asMilliseconds();
		frameRate.Update(deltaTime);
		//------------UPDATE--------------		
		//  // -------------- DRAW ---------------- // 


			// Activate the window for OpenGL rendering
			window.setActive();

			////draw
			//window.draw(shape);
			//window.draw(rectangle);
			//window.draw(square);

			//window.draw(bullet);

			window.clear(sf::Color::Blue);//limpando  a screen
			demon.Draw(window);
			frameRate.Draw(window);
			Myplayer.Draw(window);
			map.Draw(window);
			//window.draw(playerSprite);//nao pode dar draw em uma texture

			window.display(); // chamando a date q tava no back-bufffer e botando na screenb
			deltaTimeTimer = clock.getElapsedTime();
		// -------------- DRAW ---------------- // 



		
	
	}
	return 0;
}

		





//sf::CircleShape shape(50.f);
//sf::RectangleShape rectangle(sf::Vector2f(150, 50));
//sf::CircleShape square(80.f, 3);
//rectangle.setOrigin(sf::Vector2f(0, 0));
////rectangle.setOrigin(rectangle.getSize()/ 2.0f); garante que sempre a origin será o centro
//square.setPosition(sf::Vector2f(50,50));
//square.setFillColor(sf::Color::Black);
//rectangle.setPosition(sf::Vector2f(100, 100));
//shape.setFillColor(sf::Color::Magenta);
//shape.setPosition(sf::Vector2f(100, 100));