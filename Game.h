#pragma once
#include "libs.h"

class Game
{
private:
	void Draw();
	void Update(float delta);
	void ProcessEvents();

	//window
	std::unique_ptr<sf::RenderWindow> _wnd;


public:

	Game();
	void Loop();

};

