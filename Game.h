#pragma once
#include "Player.h"
#include "TextureManager.h"
#include "libs.h"

class Game
{
private:
	void Draw();
	void Update(float delta);
	void ProcessEvents();

	//window
	sf::RenderWindow* _wnd;
	TextureManager* _textureManager;
	Player* _player;


public:

	Game();
	void Loop();

};

