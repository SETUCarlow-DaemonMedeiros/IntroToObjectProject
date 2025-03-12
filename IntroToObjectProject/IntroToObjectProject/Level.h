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
	sf::Sprite Level::getFloorDetail();

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

};