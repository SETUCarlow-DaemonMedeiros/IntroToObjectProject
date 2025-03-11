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

	// Columns
	void setColumnDetail();
	sf::Sprite getColumnDetail();

private:

	// Floor
	sf::RectangleShape m_floorDef;

	// Columns
	sf::Texture m_columnTexture;
	sf::Sprite m_columnSprite;

};