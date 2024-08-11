#include "TextureHelper.h"

// redeclare the variable so that this file knows it exists and can use it 
unordered_map < string, sf::Texture> TextureHelper::textures;

void TextureHelper::LoadTexture(string fileName)
{
	string path = "images/";
	path += fileName + ".png";
	textures[fileName].loadFromFile(path);
}

sf::Texture& TextureHelper::GetTexture(string textureName)
{
	if (textures.find(textureName) == textures.end())
		LoadTexture(textureName);
	return textures[textureName];
}

void TextureHelper::Clear()
{
	textures.clear(); // get rid of all stored objects
}