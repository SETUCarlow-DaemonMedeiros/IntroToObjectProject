#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:

	Player();

	// Player shape
	void loadPlayerDefault();
	sf::RectangleShape getPlayerDefault();

private:

	// Player shape
	sf::RectangleShape m_playerDefault;
};