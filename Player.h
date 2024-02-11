#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{

private : 	
	sf::Texture PlayerTexture; 
	sf::Sprite Sprite;
	std::vector<sf::RectangleShape> bullets{};
	float bulletSpeed{ 0.5f };
	sf::RectangleShape boundingRectangle;
	// static antes na da variavel ou da funcao faz ela ser '' global''' e tbm ela nao precisa criar uma instancia da classe para usar tipo eu nao preciso criar um Player player p usar
	// uma funcao , e bom pq tipo se eu decclaro uuma funcao static , todos os player irao utilizar a mesma date dessa funcao assim otimizando um poco
	float width = 120;
	float height = 100;
	sf::Vector2i size;
public:
	void initialize();//<- called once p App Start
	void Update(Enemy& enemy);//<- called once p App start
	sf::Sprite getSSprite();
	void Load();//<- called once p frame
	void Draw(sf::RenderWindow &window);//<- called once p frame

};

//funcoes inline


