#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"
#include "sword.h"
#include <limits>

class Player
{

private : 	
	sf::Text  MunitionText;
	sf::Font font; 
	sf::Texture PlayerTexture; 
	sf::Sprite Sprite;
	float PlayerSpeed;
	int Xtexture;
	int Xindex;
	int yindex;
	float timerMunition;
	sf::Texture BulletTexture;
	int municao;
	std::vector<Bullet> bullets;
	float Inf;
	float maxFireRate;
	float fireRateTimer;

	
	Sword sword;



	sf::RectangleShape boundingRectangle;
	// static antes na da variavel ou da funcao faz ela ser '' global''' e tbm ela nao precisa criar uma instancia da classe para usar tipo eu nao preciso criar um Player player p usar
	// uma funcao , e bom pq tipo se eu decclaro uuma funcao static , todos os player irao utilizar a mesma date dessa funcao assim otimizando um poco
	float width = 120;
	float height = 100;
	sf::Vector2i size;

public:
	Player();
	~Player();

	void setMunition();
	void initialize();//<- called once p App Start
	void Update(float deltaTime,Enemy& enemy,sf::Vector2i &mousePosition);//<- called once p App start
	sf::Sprite getSSprite();
	void Load();//<- called once p frame
	void Draw(sf::RenderWindow &window);//<- called once p frame

};

//funcoes inline


