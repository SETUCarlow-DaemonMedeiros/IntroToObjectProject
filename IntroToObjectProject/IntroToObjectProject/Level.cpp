#include "Level.h"

Level::Level() // Default constructor
{
	setDefFloor();
}

void Level::setDefFloor() // Sets default floor shape
{
	m_floorDef.setFillColor(sf::Color::Green);
	m_floorDef.setSize(sf::Vector2f{ 800.0f, 200.0f });
	m_floorDef.setOrigin(400.0, 100.0);
	m_floorDef.setPosition(400.0f, 500.0f);
}

sf::RectangleShape Level::getDefFloor() // Returns default floor shape
{
	return m_floorDef;
}