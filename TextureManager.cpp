#include "TextureManager.h"
#include <stdexcept>

TextureManager::TextureManager()
{
    LoadTexture("player", "path/to/player_texture.png");
    LoadTexture("bullet", "path/to/bullet_texture.png");
    LoadTexture("enemy", "path/to/enemy_texture.png");
}

void TextureManager::LoadTexture(const std::string& textureName, const std::string& filePath)
{
    sf::Texture texture;
    texture.loadFromFile(filePath); 
    textures[textureName] = texture;
}

const sf::Texture& TextureManager::GetTexture(const std::string& textureName)
{
    return textures[textureName];  
