#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:

	Player();

	void loadPlayerDefault();
	sf::RectangleShape getPlayerDefault();

private:

	sf::RectangleShape m_playerDefault;
};