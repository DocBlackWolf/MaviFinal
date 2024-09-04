#include "Stone.h"

// Constructor to initialize the stone's position and texture
Stone::Stone(const sf::Texture& texture,float velocityx, float x,float velocityy, float y)
    : x(x), y(y)
{
    stone.setTexture(texture);
    stone.setPosition(x, y);
    timeAlive.restart();
    velocityX = velocityx;
    velocityY = velocityy;
}

void Stone::Movement(float delta, float limitx, float limity)
{
    
    


    float gravity = 9.8f; 

    velocityY += gravity * delta;
    

    y += velocityY * delta;
    x += velocityX * delta;

    if (y >= limity)
    {
        y = limity;      
        velocityY = -velocityY;
    }

    else if (y <= 0)
    {
        y = 0;         
        velocityY = -velocityY; 
    }

 
    if (x >= limitx)
    {
        x = limitx;     
    }
    else if (x <= 0)
    {
        x = 0;          
    }

    stone.setPosition(x, y); 
}


void Stone::Draw(sf::RenderWindow* _wnd)
{
    _wnd->draw(stone);
}

sf::Vector2f Stone::GetPos() const
{
    return stone.getPosition();
}

// Get the time the stone has been alive
float Stone::GetTimeAlive()
{
    return timeAlive.getElapsedTime().asSeconds();
}

// GetBounds function to return the bounding box of the stone
sf::FloatRect Stone::GetBounds() const
{
    return stone.getGlobalBounds();
}
