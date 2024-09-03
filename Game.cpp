#include "Game.h"


Game::Game()
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 600), "game window");
	_player = std::make_unique<Player>();



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
}

void Game::ProcessEvents()
{

}

void Game::Draw()
{
	_wnd->clear(sf::Color::White);

	//Draw calls
	_player->Draw(_wnd);
	//xxxxxxxxxxxxxxxx//

	_wnd->display();
}