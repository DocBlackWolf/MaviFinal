#pragma once
#include "Player.h"
#include "libs.h"

class Game
{
private:
	void Draw();
	void Update(float delta);
	void ProcessEvents();

	//window
	std::unique_ptr<sf::RenderWindow> _wnd;
	std::unique_ptr<Player> _player;


public:

	Game();
	void Loop();

};

