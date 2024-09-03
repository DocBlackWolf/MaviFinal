#include "Game.h"


Game::Game()
{
	_wnd = new sf::RenderWindow(sf::VideoMode(800, 600), "Game Window");
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