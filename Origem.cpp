#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Player.h"
#include"Enemy.h"


int main() {


	//-------------INITIALIZE-----------------
	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME",sf::Style::Default, settings);
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME");
	//sf::RectangleShape bullet(sf::Vector2f(20, 10));
	//-------------INITIALIZE-----------------


	
	Player Myplayer;
	Enemy demon;
	
	Myplayer.initialize();
	demon.initialize();
	///------------------LOAD-----------------
	Myplayer.Load();
	demon.Load();


	///------------------LOAD-----------------


	


	while (window.isOpen())
	{
		
		
		// -------------- UPDATE ---------------- // 
		sf::Event event; // criando um objeto chamado event
		while (window.pollEvent(event))// looping na fila de eventos (queue fila em ingles) 
		{
			Myplayer.Update(demon);
			// se o tipo for close fechar
			if (event.type == sf::Event::Closed) {
				window.close();

			}


			//------------UPDATE--------------
		}


		 // -------------- DRAW ---------------- // 


			// Activate the window for OpenGL rendering
			window.setActive();

			////draw
			//window.draw(shape);
			//window.draw(rectangle);
			//window.draw(square);

			//window.draw(bullet);

			window.clear(sf::Color::Blue);//limpando  a screen
			demon.Draw(window);
			
			Myplayer.Draw(window);
			//window.draw(playerSprite);//nao pode dar draw em uma texture

			window.display(); // chamando a date q tava no back-bufffer e botando na screenb

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