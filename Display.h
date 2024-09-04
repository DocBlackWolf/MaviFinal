#pragma once
#include "libs.h"

class Display
{
private:
    sf::Font font;                // Font for rendering text
    sf::Text displayText;         // SFML text object for displaying text
    sf::Time countdownTime;       // Time for the countdown
    sf::Clock clock;              // Clock to manage the countdown

public:
    // Constructor to initialize the Display with a font
    Display(const std::string& fontPath);

    // Method to set custom text
    void SetText(const std::string& text, float x, float y);

    // Method to start the countdown from a given time in seconds
    void StartCountdown(float seconds, float x, float y);

    // Method to update the countdown and adjust the displayed text
    void Update();

    // Method to draw the text on the provided window
    void Draw(sf::RenderWindow* window);

    // Method to return the remaning time
    float GetRemainingTime() const;
};
