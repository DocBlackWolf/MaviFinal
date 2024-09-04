#include "Game.h"

Game::Game()
{
    _wnd = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game Window");
    _textureManager = new TextureManager();
    _display = new Display("Recursos/Fuentes/junegull.ttf");
    _display->StartCountdown(10, 1000, 100);
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
        Update(delta);
        Draw();
    }
}

void Game::Update(float delta)
{
    _display->Update();
    if (_display->GetRemainingTime() <= 0) 
    {
        std::string scoreText = "Total Score: " + std::to_string(gameScore);
        _display->SetText(scoreText,300,300);
    }

    if (_display->GetRemainingTime() > 0)
{
        _player->Movement(delta);

    // Bullet movement
    for (auto& bullet : _bullets)
    {
        bullet.Movement(delta);
    }

    // Stone movement and out-of-bounds deletion
    for (auto it = _rocks.begin(); it != _rocks.end();)
    {
        it->Movement(delta, _wnd->getSize().x, _wnd->getSize().y);

        if (it->GetPos().y >= _wnd->getSize().y)
        {
            it = _rocks.erase(it); // Remove rock if it goes out of bounds

        }
        else
        {
            ++it;
        }
    }

    // Rock spawning
    if (rockSpawn.getElapsedTime().asSeconds() > 1)
    {
        float randomX = static_cast<float>(rand() % static_cast<int>(_wnd->getSize().x));
        float randomVelocityX = static_cast<float>((rand() % 200) - 100) / 100.0f; // Horizontal velocity between -1.0 and 1.0
        _rocks.push_back(Stone(_textureManager->GetTexture("stone"), randomVelocityX, randomX,80,0 ));
        rockSpawn.restart();
    }
}

    // Collision detection
    CheckCollisions();
}

void Game::ProcessEvents()
{
    sf::Event event;
    while (_wnd->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _wnd->close();

        // Handle bullet creation on Space key press
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && lastInput.getElapsedTime().asSeconds() > 0.1)
        {
            sf::Vector2f playerPos = _player->GetPos();
            _bullets.push_back(Bullet(_textureManager->GetTexture("bullet"), playerPos.x + 60, playerPos.y));
            lastInput.restart();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
        {
            ResetGame();
        }
    }
}

void Game::Draw()
{
    _wnd->clear(sf::Color::White);

    // Draw player
    _player->Draw(_wnd);

    // Draw bullets
    for (auto& bullet : _bullets)
    {
        bullet.Draw(_wnd);
    }

    // Draw rocks
    for (auto& rock : _rocks)
    {
        rock.Draw(_wnd);
    }

    // Draw clock
    _display->Draw(_wnd);

    _wnd->display();
}

void Game::CheckCollisions()
{
    for (auto bulletIt = _bullets.begin(); bulletIt != _bullets.end();)
    {
        bool bulletRemoved = false;

        for (auto stoneIt = _rocks.begin(); stoneIt != _rocks.end();)
        {
            if (bulletIt->GetBounds().intersects(stoneIt->GetBounds()))
            {
                stoneIt = _rocks.erase(stoneIt);
                bulletIt = _bullets.erase(bulletIt);
                bulletRemoved = true;
                gameScore++;
                break;
            }
            else
            {
                ++stoneIt;
            }
        }

        if (!bulletRemoved)
        {
            ++bulletIt;
        }
    }
}

void Game::ResetGame()
{
    _bullets.clear();
    _rocks.clear();
    _player = new Player(_textureManager->GetTexture("player"));
    _display->StartCountdown(10, 300, 300);
}
