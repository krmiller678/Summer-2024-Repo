#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class TextureHelper
{
	static unordered_map < string, sf::Texture> textures;
	static void LoadTexture(string fileName); // LoadTexture("space")
public:
	static sf::Texture& GetTexture(string textureName);
	static void Clear(); // call this once at the end of main();
};

