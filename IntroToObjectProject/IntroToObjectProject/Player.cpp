#include "Player.h"

Player::Player()
{
	loadPlayerDefault();
}

void Player::loadPlayerDefault()
{
	m_playerDefault.setFillColor(sf::Color::Blue);
	m_playerDefault.setSize(sf::Vector2f{ 64.0f, 64.0f });
	m_playerDefault.setOrigin(32.0, 32.0);
	m_playerDefault.setPosition(400.0f, 300.0f);
}

sf::RectangleShape Player::getPlayerDefault()
{
	return m_playerDefault;
}
