#include "SoundHandler.h"
#include <iostream>

SoundHandler::SoundHandler() {
    // Load the sound buffer for jump sound
    if (!jumpBuffer.loadFromFile("Recursos/Sonido/jump.ogg")) 
    {
        std::cerr << "Error loading jump.wav" << std::endl;
    }
    else 
    {
        jump.setBuffer(jumpBuffer);
    }

    // Load the sound buffer for hit sound
    if (!hitBuffer.loadFromFile("Recursos/Sonido/hit.ogg")) {
        std::cerr << "Error loading hit.wav" << std::endl;
    }
    else 
    {
        hit.setBuffer(hitBuffer);
    }

    // Load the sound buffer for win sound
    if (!winBuffer.loadFromFile("Recursos/Sonido/coin.ogg")) {
        std::cerr << "Error loading win.wav" << std::endl;
    }
    else 
    {
        win.setBuffer(winBuffer);
    }
}

// Method to play the jump sound
void SoundHandler::playJumpSound() 
{
    jump.play();
}

// Method to play the hit sound
void SoundHandler::playHitSound() 
{
    hit.play();
}

// Method to play the win sound
void SoundHandler::playWinSound() 
{
    win.play();
}
