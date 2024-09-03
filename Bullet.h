#pragma once
#include "libs.h"

class Bullet
{
private:
	
	sf::Sprite bullet;
	float x, y;

public:
	Bullet(const sf::Texture& texture, float x, float y);
	void Movement(float delta);
	void Draw(sf::RenderWindow* _wnd);
	sf::FloatRect GetBounds() const;

};

