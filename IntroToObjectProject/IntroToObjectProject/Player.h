#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:

	Player();

	// Player shape
	void loadPlayerDefault();
	sf::RectangleShape getPlayerDefault();
	void loadPlayerDetail();
	sf::Sprite getPlayerDetail();

	// Direction/Actions
	void setPlayerHeading(int t_heading);
	std::string getPlayerHeading();
	void setThrowing(bool t_throwing);

	// Animate Player
	void animatePlayer();

	// Movement
	void movePlayerUp();
	void movePlayerDown();
	void movePlayerRight();
	void movePlayerLeft();

private:

	// Player shape
	sf::RectangleShape m_playerDefault;
	sf::Texture m_knightTexture;
	sf::Sprite m_knightSprite;

	// Directions/Actions
	std::string m_playerHeading = "None";
	bool m_throwing{ false };

	// Animate Player
	int m_knightFrame{ -1 };
	int m_animationFrame = 5;
	float m_frameCounter = 0.0f;
	float m_frameIncrement = 0.3f;

	// Move player
	int speed = 3;
};