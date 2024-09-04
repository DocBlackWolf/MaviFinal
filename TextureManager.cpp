#include "TextureManager.h"
#include <stdexcept>

TextureManager::TextureManager()
{
    LoadTexture("player", "Recursos/Imagenes/jumper.png");
    LoadTexture("bullet", "Recursos/Imagenes/bullet.png");
    LoadTexture("stone", "Recursos/Imagenes/stone.png");
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
}