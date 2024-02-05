//#include <iostream>
//#include <string>
//#include <SFML/Graphics.hpp>
//#include <cstdlib>
//
//
//float KinematcEquation(float aceleration, float velocity, float position, float time) {
//	return 0.5f * aceleration * time * time + velocity * time + position;
//	//
//}
//int main() {
//
//
//	// set the shape color to green
//	//sf::ContextSettings settings;
//	//settings.antialiasingLevel = 8;
//	//sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME",sf::Style::Default, settings);
//	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME");
//	std::vector <sf::CircleShape> shape;
//	///------------------LOAD-----------------
//	int x;
//	int y;
//	int a;
//	int b;
//	int c;
//	int size;
//
//	///------------------LOAD-----------------
//
//	while (window.isOpen()) {
//
//
//		// -------------- UPDATE ---------------- // 
//		sf::Event event; // criando um objeto chamado event
//		while (window.pollEvent(event))// looping na fila de eventos (queue fila em ingles) 
//		{
//			// se o tipo for close fechar
//			if (event.type == sf::Event::Closed) {
//				window.close();
//
//			}
//
//		}
//	
//		// -------------- UPDATE ---------------- // 
//
//		// -------------- DRAW ---------------- // 
//		b = rand() % 255;
//		a = rand() % 255;
//		c = rand() % 255;
//		x = rand() % 800;
//		y = rand() % 600;
//		size = 1+rand() % 100;
//		sf::CircleShape circle(size);
//		circle.setFillColor(sf::Color(a,b,c));
//		circle.setPosition(sf::Vector2f(x, y));
//		shape.push_back(circle);
//
//
//		// Activate the window for OpenGL rendering
//		window.setActive();
//		window.clear(sf::Color::Blue);//limpando  a screen
//		////draw
//		for (int i = 0; i < shape.size(); i++) {
//			window.draw(shape[i]);
//		}
//		window.display(); // chamando a date q tava no back-bufffer e botando na screenb
//		// -------------- DRAW ---------------- // 
//
//	}
//	//Enemy Matsuda;
//	//Matsuda.setpower(10);
//
//	//std::cout << Matsuda.getpower();
//
//	return 0;
//}
//
//
//
//
