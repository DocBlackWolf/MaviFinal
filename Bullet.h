#pragma once

#include "libs.h"

class Bullet
{
public:
    // Constructor to initialize the bullet with a texture and position
    Bullet(const sf::Texture& texture, float x, float y);

    // Method to handle the movement of the bullet
    void Movement(float delta);

    // Method to draw the bullet on the given window
    void Draw(sf::RenderWindow* _wnd);

    // Method to get the time the bullet has been alive
    float GetTimeAlive();

    // Method to get the bounding rectangle of the bullet (for collision detection)
    sf::FloatRect GetBounds() const;

private:
    // Sprite representing the bullet
    sf::Sprite bullet;

    // Clock to track how long the bullet has been alive
    sf::Clock timeAlive;

    // Position coordinates of the bullet
    float x, y;
};
