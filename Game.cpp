#include "Game.h"


Game::Game()
{
	_wnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 600), "game window");




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
}

void Game::ProcessEvents()
{

}

void Game::Draw()
{


}