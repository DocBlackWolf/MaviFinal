#pragma once
#include "Player.h"
#include "TextureManager.h"
#include "Bullet.h"
#include "Stone.h"
#include "Display.h"
#include "libs.h"

class Game
{
private:
	void Draw(); // Method for all the draw calls
	void Update(float delta); // Method for handling main logic
	void ProcessEvents(); //Method mainly intended to handle imputs
	void CheckCollisions(); //Method for cheking collitions
	void ResetGame(); // Method for reseting the game

	//window
	sf::RenderWindow* _wnd;
	//texture manager
	TextureManager* _textureManager;
	//display
	Display* _display;
	//Game objects
	Player* _player;
	std::vector<Bullet> _bullets;
	std::vector<Stone> _rocks;

	//clocks
	sf::Clock rockSpawn;
	sf::Clock lastInput;

public:

	Game();
	void Loop();

};

