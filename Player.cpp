#include "Player.h"

Player::Player(const sf::Texture& texture)
    : PlayerPos(100.0f, 500.0f), JumpSpeed(800.0f), Jumped(false),
    _sound(std::make_unique<SoundHandler>())
{
    playerSpr.setTexture(texture);
}

void Player::Movement(float Delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        PlayerPos.x += 350.0f * Delta;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        PlayerPos.x -= 350.0f * Delta;
    }

    PlayerPos.y += 300.0f * Delta;
    if (PlayerPos.y > 600.0f) {
        PlayerPos.y = 600.0f;
    }

    if (TSJ.getElapsedTime().asMilliseconds() > 500) {
        Jumped = false;
    }
}

void Player::Draw(sf::RenderWindow* _wnd)
{
    playerSpr.setPosition(PlayerPos);
    _wnd->draw(playerSpr);
}

void Player::SetPos(sf::Vector2f Pos)
{
    PlayerPos = Pos;
}

sf::Vector2f Player::GetPos() const
{
    return PlayerPos;
}

sf::FloatRect Player::GetBounds() const
{
    return playerSpr.getGlobalBounds();
}
