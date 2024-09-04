#pragma once
#include "libs.h"

class Stone
{
private:

	sf::Sprite stone;
	sf::Clock timeAlive;
	float x, y;
	float velocityY;
	float velocityX;

public:
	Stone(const sf::Texture& texture, float velocityx, float x, float velocityy, float y);
	void Movement(float delta,float limitx, float limity);
	void Draw(sf::RenderWindow* _wnd);

	sf::Vector2f GetPos() const;
	float GetTimeAlive();
	sf::FloatRect GetBounds() const;

};


