#include "Player.h"

Player::Player() // Default constructor
{
	loadPlayerDefault();
}

void Player::loadPlayerDefault() // Sets default player shape
{
	m_playerDefault.setFillColor(sf::Color::Blue);
	m_playerDefault.setSize(sf::Vector2f{ 16.0f, 32.0f });
	m_playerDefault.setOrigin(8.0, 32.0);
	m_playerDefault.setPosition(120.0f, 105.0f);
}

sf::RectangleShape Player::getPlayerDefault() // Returns default player shape
{
	return m_playerDefault;
}