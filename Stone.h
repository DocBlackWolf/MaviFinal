#pragma once

#include "libs.h"

class Stone
{
public:
    // Constructor to initialize the stone with a texture, position, and velocity
    Stone(const sf::Texture& texture, float velocityX, float x, float velocityY, float y);

    // Method to update the stone's position based on its velocity and the elapsed time
    void Movement(float delta, float limitX, float limitY);

    // Method to draw the stone on the given window
    void Draw(sf::RenderWindow* _wnd);

    // Method to get the current position of the stone
    sf::Vector2f GetPos() const;

    // Method to get the time the stone has been alive
    float GetTimeAlive();

    // Method to get the bounding rectangle of the stone (for collision detection)
    sf::FloatRect GetBounds() const;

private:
    // Sprite representing the stone
    sf::Sprite stone;

    // Clock to track how long the stone has been alive
    sf::Clock timeAlive;

    // Position coordinates of the stone
    float x, y;

    // Velocity components of the stone
    float velocityX, velocityY;
};
