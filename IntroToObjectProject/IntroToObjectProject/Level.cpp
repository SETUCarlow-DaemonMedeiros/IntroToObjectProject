#include "Level.h"

Level::Level() // Default constructor
{
	setDefFloor();
	setColumnDetail();
}

void Level::setDefFloor() // Sets default floor shape
{
	m_floorDef.setFillColor(sf::Color::Green);
	m_floorDef.setSize(sf::Vector2f{ 240.0f, 41.0f });
	m_floorDef.setOrigin(120.0, 41.0);
	m_floorDef.setPosition(120.0f, 135.0f);
}

sf::RectangleShape Level::getDefFloor() // Returns default floor shape
{
	return m_floorDef;
}

void Level::setColumnDetail() // Default values for column texture/sprite
{
	if (!m_columnTexture.loadFromFile("ASSETS\\IMAGES\\columns.png"))
	{
		std::cout << "Issue loading columns image" << std::endl;
	}

	m_columnSprite.setTexture(m_columnTexture);
	m_columnSprite.setOrigin(120.0f, 67.5f);
	m_columnSprite.setPosition(120.0f, 67.5f);
}

sf::Sprite Level::getColumnDetail() // Returns column sprite
{
	return m_columnSprite;
}