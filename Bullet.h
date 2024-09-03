#pragma once
#include "libs.h"

class Bullet
{
private:
	
	sf::Sprite bullet;
	sf::Clock timeAlive;
	float x, y;

public:
	Bullet(const sf::Texture& texture, float x, float y);
	void Movement(float delta);
	void Draw(sf::RenderWindow* _wnd);
	float GetTimeAlive();
	sf::FloatRect GetBounds() const;

};

