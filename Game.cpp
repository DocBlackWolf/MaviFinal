#include "Game.h"


Game::Game()
{
	_wnd = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game Window");
	_textureManager = new TextureManager();
	_player = new Player(_textureManager->GetTexture("player"));




}

void Game::Loop()
{
	sf::Clock clock;
	clock.restart();
	float delta;
	while (_wnd->isOpen())
	{
		delta = clock.restart().asSeconds();

		ProcessEvents();
		Draw();
		Update(delta);
	}


}


void Game::Update(float delta)
{
	_player->Movement(delta);

	for (auto& bullet : _bullets)
	{
		bullet.Movement(delta);
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_wnd->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_wnd->close();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
		{
			
			sf::Vector2f playerPos = _player->GetPos();
			_bullets.push_back(Bullet(_textureManager->GetTexture("bullet"), playerPos.x, playerPos.y));
		}
	}
}

void Game::Draw()
{
	_wnd->clear(sf::Color::White);

	//Draw calls
	_player->Draw(_wnd);

	for (auto& bullet : _bullets)
	{
		bullet.Draw(_wnd);
	}
	//xxxxxxxxxxxxxxxx//

	_wnd->display();
}