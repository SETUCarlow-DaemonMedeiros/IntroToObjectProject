#include "Player.h"

Player::Player() // Default constructor
{
	loadPlayerDefault();
}

void Player::loadPlayerDefault() // Sets default player shape
{
	m_playerDefault.setFillColor(sf::Color::Blue);
	m_playerDefault.setSize(sf::Vector2f{ 64.0f, 64.0f });
	m_playerDefault.setOrigin(32.0, 32.0);
	m_playerDefault.setPosition(400.0f, 300.0f);
}

sf::RectangleShape Player::getPlayerDefault() // Returns default player shape
{
	return m_playerDefault;
}