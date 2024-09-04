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
	void Draw();
	void Update(float delta);
	void ProcessEvents();
	void CheckCollisions();

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

