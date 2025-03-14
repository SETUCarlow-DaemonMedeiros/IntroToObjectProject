#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include <cstdlib>
#include <ctime>

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

	// Sunrays
	void setUpSunrays();
	void animateSunrays();
	sf::Sprite Level::getSunrayOne();
	sf::Sprite Level::getSunrayTwo();


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

	// Sunrays
	sf::Texture m_sunray1Text;
	sf::Sprite m_sunray1Sprite;
	sf::Texture m_sunray2Text;
	sf::Sprite m_sunray2Sprite;
	sf::Color m_opacity{ 255,255,255,255 }; // White
	sf::Color m_opacity2{ 255,255,255,255 }; // White
	bool fadeOut{ true };
	bool fadeOut2{ true };
};