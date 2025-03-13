#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Level
{
public:

	Level();

	// Floor
	void setDefFloor();
	sf::RectangleShape getDefFloor();
	void setFloorDetail();
	sf::Sprite getFloorDetail();

	// Sky
	void setSkyDetail();
	sf::Sprite getSunrise();
	sf::Sprite getSunset();

	// Columns
	void setColumnDetail();
	sf::Sprite getColumnDetail();

private:

	// Floor
	sf::RectangleShape m_floorDef;
	sf::Texture m_tileTexture;
	sf::Sprite m_tileSprite;

	// Columns
	sf::Texture m_columnTexture;
	sf::Sprite m_columnSprite;

	// Sky
	sf::Texture m_sunriseTexture;
	sf::Sprite m_sunriseSprite;
	sf::Texture m_sunsetTexture;
	sf::Sprite m_sunsetSprite;

};