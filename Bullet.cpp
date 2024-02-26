#include "Bullet.h"
#include "Maths.h"
#include <iostream>
Bullet::Bullet()
{

}

Bullet::~Bullet()
{
}
// const significA QUE EU NAO PODEREI ALTERAR O VALOR ORIGINAL QUE NESSE CONTEXTO E A POSICAO DE PLAYER / NAO PODEREI AUTERAR POR OUTRAS CLASSES ETC
void Bullet::initialize(const sf::Vector2f &position, const sf::Vector2f &target,float speed, sf::Texture &Texture)
{
	this->speed = speed; // this referencia a classe original
	Sprite.setTexture(Texture);
	Sprite.setPosition(position);
	direction =  maths::NormalizeVector( target - position);// se eu calcular a direction uma vez ( no caso eu calculo quando aperto o mause)
	//entao a bullet vai seguir apenas a ultima posicao do maose , e nao vai ficar seguindo ele constantemente
}


void Bullet::Update(float deltaTime)
{
	Sprite.setPosition(Sprite.getPosition() + direction * speed * deltaTime);

}


void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite);
}

void Bullet::load()
{

}

