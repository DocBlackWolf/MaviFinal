#pragma once

#include "libs.h"
#include <map>
#include <string>

class TextureManager
{
public:
    // Constructor for the TextureManager
    TextureManager();

    // Retrieves a texture by its name, loading it if necessary
    const sf::Texture& GetTexture(const std::string& textureName);

private:
    // Map to store textures with their associated names
    std::map<std::string, sf::Texture> textures;

    // Loads a texture from a file and stores it in the textures map
    void LoadTexture(const std::string& textureName, const std::string& filePath);
};
