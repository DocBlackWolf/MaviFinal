#pragma once

#include "libs.h"

class SoundHandler
{
public:
    // Constructor to load sound buffers and set up sounds
    SoundHandler();

    // Method to play the jump sound effect
    void playJumpSound();

    // Method to play the hit sound effect
    void playHitSound();

    // Method to play the win sound effect
    void playWinSound();

private:
    // Sound buffers to hold audio data for each sound effect
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer winBuffer;

    // Sound objects to play each sound effect
    sf::Sound jump;
    sf::Sound hit;
    sf::Sound win;
};
