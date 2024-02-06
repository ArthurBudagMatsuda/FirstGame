#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>


sf::Vector2f NormalizeVector(sf::Vector2f vector) {
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y
	);
	sf::Vector2f NormalizedVector;
	NormalizedVector.x = vector.x / m;
	NormalizedVector.y = vector.y / m;
	return NormalizedVector;
}


int main() {
	float bulletSpeed{ 0.5f };

	// set the shape color to green
	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME",sf::Style::Default, settings);
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME");
	std::vector<sf::RectangleShape> bullets{};
	//sf::RectangleShape bullet(sf::Vector2f(20, 10));


	///------------------LOAD-----------------
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	if (enemyTexture.loadFromFile("assets/player/texture/enemySpriteSheets.png")) {
		std::cout << "Enemy Texture loaded.";
		enemySprite.setTexture(enemyTexture);
		int Xindex = 0;
		int Yindex = 0;
		enemySprite.setTextureRect(sf::IntRect(Xindex * 45, Yindex * 51, 45, 51));
		enemySprite.scale(sf::Vector2f(2, 2));

		enemySprite.setPosition(sf::Vector2f(5, 5));
	}
	else
	{
		std::cout << "Player texture Failed.";
	}
	sf::Texture PlayerTexture;
	sf::Sprite playerSprite;
	if (PlayerTexture.loadFromFile("assets/player/texture/SpriteSheets.png")) {//fazer uma classe load game para dar load em tudo 
		std::cout << "Player Texture Loaded.";
		playerSprite.setTexture(PlayerTexture);

		int Xindex = 2;//120
		int yindex = 2;//100
		//X,Y,width,height
		playerSprite.setTextureRect(sf::IntRect(Xindex * 120, yindex * 100, 120, 100));
		playerSprite.setPosition(sf::Vector2f(400, 400));
		playerSprite.scale(sf::Vector2f(2, 2));
	}
	else {
		std::cout << "Player Texture Failed.";
	}
	//bullet.setPosition(playerSprite.getPosition());

	///------------------LOAD-----------------

	//----------------Calculate bullet position----------------

	//----------------Calculate bullet position----------------
	sf::Vector2f direction;


	while (window.isOpen())
	{
		sf::Vector2f postion = playerSprite.getPosition();

		// -------------- UPDATE ---------------- // 
		sf::Event event; // criando um objeto chamado event
		while (window.pollEvent(event))// looping na fila de eventos (queue fila em ingles) 
		{
			// se o tipo for close fechar
			if (event.type == sf::Event::Closed) {
				window.close();

			}
			//bullet.setPosition(bullet.getPosition() + direction * bulletSpeed);

			//para ajustar o movimento bugado - multiplica a velocidade , pela difenca do frame atual pelo ultimo frame , ou seja frameatual - frameanterior , 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

				playerSprite.setPosition(postion + sf::Vector2f(1, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {


				playerSprite.setPosition(postion - sf::Vector2f(1, 0));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {


				playerSprite.setPosition(postion - sf::Vector2f(0, 1));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

				playerSprite.setPosition(postion + sf::Vector2f(0, 1));
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

				bullets.push_back(sf::RectangleShape(sf::Vector2f(50, 25)));
				int i = bullets.size() - 1;

				bullets[i].setPosition(playerSprite.getPosition());


			}
			for (size_t i = 0; i < bullets.size(); i++) {
				direction = enemySprite.getPosition() - bullets[i].getPosition();//calculate the direction of every single bullet  
				direction = NormalizeVector(direction);
				bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);
			}
		}

			//for (size_t i = 0; i < bullets.size(); i++) {
			//	sf::Vector2f direction = enemySprite.getPosition() - bullets[i].getPosition();//calculate the direction of every single bullet  
			//		direction = NormalizeVector(direction);
			//		bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);
		   //}
				// -------------- DRAW ---------------- // 


			// Activate the window for OpenGL rendering
			window.setActive();

			////draw
			//window.draw(shape);
			//window.draw(rectangle);
			//window.draw(square);

			//window.draw(bullet);

			window.clear(sf::Color::Blue);//limpando  a screen
			window.draw(enemySprite);
			window.draw(playerSprite);//nao pode dar draw em uma texture
			for (size_t i = 0; i < bullets.size(); i++) {
				window.draw(bullets[i]);
			}
			window.display(); // chamando a date q tava no back-bufffer e botando na screenb
			// -------------- DRAW ---------------- // 



		// etc ...


		

	}
	return 0;
}
			// -------------- UPDATE ---------------- // 

		//Enemy Matsuda;
		//Matsuda.setpower(10);

		//std::cout << Matsuda.getpower();

		





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