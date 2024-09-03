#pragma once

#include "libs.h"
#include "SoundHandler.h"

class Player
{
public:
    Player(const sf::Texture& texture);

    void Movement(float Delta);
    void Draw(sf::RenderWindow* _wnd);
    void SetPos(sf::Vector2f Pos);

    sf::Vector2f GetPos() const;
    sf::FloatRect GetBounds() const;

private:
    std::unique_ptr<SoundHandler> _sound;

    sf::Sprite playerSpr;

    sf::Vector2f PlayerPos;
    sf::Clock TSJ; // Timer since jump

    float JumpSpeed;
    bool Jumped;
};
