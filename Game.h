#pragma once
#include "Player.h"
#include "TextureManager.h"
#include "Bullet.h"
#include "libs.h"

class Game
{
private:
	void Draw();
	void Update(float delta);
	void ProcessEvents();

	//window
	sf::RenderWindow* _wnd;
	//texture manager
	TextureManager* _textureManager;

	//Game objects
	Player* _player;
	std::vector<Bullet> _bullets;

public:

	Game();
	void Loop();

};

