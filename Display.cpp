#pragma once
#include "Display.h"

    // Constructor to initialize the Display with a font
    Display::Display(const std::string& fontPath)
    {
        if (!font.loadFromFile(fontPath))
        {
            throw std::runtime_error("Failed to load font");
        }
        displayText.setFont(font);
        displayText.setCharacterSize(24); // Default size
        displayText.setFillColor(sf::Color::Black); // Default color
    }

    // Method to set custom text
    void Display::SetText(const std::string& text, float x, float y)
    {
        displayText.setString(text);
        displayText.setPosition(x, y);
    }

    // Method to start the countdown from a given time in seconds
    void Display::StartCountdown(float seconds, float x, float y)
    {
        countdownTime = sf::seconds(seconds);
        displayText.setPosition(x, y);
        clock.restart(); // Start or reset the clock
    }

    // Method to update the countdown and adjust the displayed text
    void Display::Update()
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time remaining = countdownTime - elapsed;

        if (remaining.asSeconds() <= 0)
        {
            displayText.setString("Time's up!");
        }
        else
        {
            int seconds = static_cast<int>(remaining.asSeconds());
            displayText.setString("Time remaining: " + std::to_string(seconds) + "s");
        }
    }

    // Method to draw the text on the provided window
    void Display::Draw(sf::RenderWindow* window)
    {
        window->draw(displayText);
    }

