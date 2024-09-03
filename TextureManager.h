#pragma once

#include "libs.h"
#include <map>
#include <string>

class TextureManager
{
public:
    TextureManager();

    const sf::Texture& GetTexture(const std::string& textureName);

private:
    std::map<std::string, sf::Texture> textures;

    void LoadTexture(const std::string& textureName, const std::string& filePath);
};

