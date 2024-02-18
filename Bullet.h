#pragma once
#include <SFML/Graphics.hpp>
class Bullet // creating a individual bullet para que cada bullet tennha sua propria direcao
{
private:
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Vector2f direction;// cada bullet tem uma direcao individual para cada
	float speed; // e uma velocidad

public:


	
	//           position = start position , where the bullet spawn | target = where  the bullet will go , speed = speed of the bullet
	void initialize(const sf::Vector2f &position, const sf::Vector2f &target,float speed);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
    void load(); //static?
	Bullet();
	~Bullet();
	inline const  sf::FloatRect& GetGlobalBounds() { return Sprite.getGlobalBounds(); };



};

