#include "Bullet.h"

Bullet::Bullet(const sf::Texture& texture, float x, float y)
    : x(x), y(y)  
{
    bullet.setTexture(texture);
    bullet.setPosition(x, y);
}

void Bullet::Movement(float delta)
{
    y -= 600 * delta;
    bullet.setPosition(bullet.getPosition().x, y);
}

void Bullet::Draw(sf::RenderWindow* _wnd)
{
    _wnd->draw(bullet);
}

float Bullet::GetTimeAlive()
{
    return timeAlive.getElapsedTime().asSeconds();
}

sf::FloatRect Bullet::GetBounds() const
{
    return bullet.getGlobalBounds();
}
