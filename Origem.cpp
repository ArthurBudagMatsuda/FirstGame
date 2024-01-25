#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
class Enemy {

private :
	int powerr = 0;
public:
	int damage = 0;
	int attackSpeed = 0;
	int health = 0;
	std::string firstName = "";
	void Kill() {
		std::cout << "TO MATANDO HAHAHHA " << std::endl;
	}
	void Walk() {
		std::cout << "TO andando " << std::endl;
	}
	void heal() {
		health = 10;
		std::cout << "TO curando  " << std::endl;
	}
	int getpower() {
		return powerr;
	}
	int setpower(int power) {
		powerr= power;
		return powerr;
	}
};

int main() {


	// set the shape color to green
	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME",sf::Style::Default, settings);
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME");
	sf::CircleShape shape(50.f);
	sf::RectangleShape rectangle(sf::Vector2f(150, 50));
	sf::CircleShape square(80.f, 3);
	rectangle.setOrigin(sf::Vector2f(0, 0));
	//rectangle.setOrigin(rectangle.getSize()/ 2.0f); garante que sempre a origin será o centro
	square.setPosition(sf::Vector2f(50,50));
	square.setFillColor(sf::Color::Black);
	rectangle.setPosition(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(sf::Vector2f(100, 100));

	while (window.isOpen()) {


		// -------------- UPDATE ---------------- // 
		sf::Event event; // criando um objeto chamado event
		while (window.pollEvent(event))// looping na fila de eventos (queue fila em ingles) 
		{
			// se o tipo for close fechar
			if (event.type == sf::Event::Closed) 
				window.close();


			// etc ...
		}
		// -------------- UPDATE ---------------- // 

		// -------------- DRAW ---------------- // 


		// Activate the window for OpenGL rendering
		window.setActive();
		window.clear(sf::Color::Blue);//limpando  a screen
		window.draw(shape);
		window.draw(rectangle);
		window.draw(square);
		//draw
		//draw player
		window.display(); // chamando a date q tava no back-bufffer e botando na screenb
		// -------------- DRAW ---------------- // 

	}
	//Enemy Matsuda;
	//Matsuda.setpower(10);

	//std::cout << Matsuda.getpower();

	return 0;
}




