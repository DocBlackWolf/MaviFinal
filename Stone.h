#pragma once
#include "libs.h"

class Stone
{
private:

	sf::Sprite stone;
	sf::Clock timeAlive;
	float x, y;

public:
	Stone(const sf::Texture& texture, float x, float y);
	void Movement(float delta);
	void Draw(sf::RenderWindow* _wnd);
	float GetTimeAlive();
	sf::FloatRect GetBounds() const;

};


