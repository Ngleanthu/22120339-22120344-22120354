#pragma once
#include"SFML/Graphics.hpp"
enum 
{
	HCMUS = 0, LIGHT , SACH
};
class AssetManager
{
private:
	sf::Texture* _textures = new sf::Texture[100];
	sf::Font* _fonts = new sf::Font[100];


public:
	AssetManager();
	~AssetManager();
	void AddTexture(int id , std::string filePath);
	void AddFont(int id , std::string filePath);
	sf::Texture& GetTexture(int id);
	sf::Font& GetFont(int id);

};

