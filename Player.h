#pragma once

#include "libs.h"
#include "SoundHandler.h"

class Player
{
public:
    // Constructor that takes a texture reference to initialize the player's sprite
    Player(const sf::Texture& texture);

    // Handles the player's movement based on the elapsed time (Delta)
    void Movement(float Delta);

    // Draws the player sprite to the provided render window
    void Draw(sf::RenderWindow* _wnd);

    // Sets the player's position to the specified coordinates
    void SetPos(sf::Vector2f Pos);

    // Returns the player's current position
    sf::Vector2f GetPos() const;

    // Returns the bounding box of the player's sprite (for collision detection)
    sf::FloatRect GetBounds() const;

private:
    // Sound handler for managing player-related sound effects
    std::unique_ptr<SoundHandler> _sound;

    // The sprite representing the player
    sf::Sprite playerSpr;

    // The current position of the player
    sf::Vector2f PlayerPos;

    // Timer to track the time since the player last jumped
    sf::Clock TSJ;

    // The speed at which the player jumps
    float JumpSpeed;

    // Flag to indicate whether the player has jumped
    bool Jumped;
};
