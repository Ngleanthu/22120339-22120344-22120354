#pragma once
#include"SFML/Graphics.hpp"
enum 
{
	HCMUS = 0, SACH, LOGO_HCMUS, PROFILE_ICON, STU_PROFILE_PIC,
	HELVETICA_BOLD, LIGHT, CHIVOMONO_LIGHT, CHIVOMONO_REGULAR, KANIT , SCHOOL_LOGO
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

