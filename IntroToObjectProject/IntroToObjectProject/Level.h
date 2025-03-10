#pragma once

#include <SFML/Graphics.hpp>

class Level
{
public:

	Level();

	void setDefFloor();
	sf::RectangleShape getDefFloor();

private:

	sf::RectangleShape m_floorDef;

};