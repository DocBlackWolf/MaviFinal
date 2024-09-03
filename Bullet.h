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
	void Draw(std::unique_ptr<sf::RenderWindow>& _wnd);
	sf::FloatRect GetBounds() const;

};

