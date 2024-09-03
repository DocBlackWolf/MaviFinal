#pragma once
#include "libs.h"

class SoundHandler
{
public:
    SoundHandler();

    // Methods to play each sound
    void playJumpSound();
    void playHitSound();
    void playWinSound();

private:
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer winBuffer;

    sf::Sound jump;
    sf::Sound hit;
    sf::Sound win;
};
