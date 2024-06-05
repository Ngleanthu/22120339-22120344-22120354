#include "AssetManager.h"
AssetManager::AssetManager()
{

}
AssetManager::~AssetManager()
{

}
void AssetManager::AddTexture(int id , std::string filePath)
{
	sf::Texture texture;
	if (texture.loadFromFile(filePath))
	{
		_textures[id] = texture;
	}
}
void AssetManager::AddFont(int id , std::string filePath)
{
	sf::Font font;
	if (font.loadFromFile(filePath))
	{
		_fonts[id] = font;
	}
}

sf::Texture& AssetManager::GetTexture(int id)
{
	return _textures[id];
}
sf::Font& AssetManager::GetFont(int id)
{
	return _fonts[id];
}

