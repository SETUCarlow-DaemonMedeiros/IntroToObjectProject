#include "Level.h"

Level::Level() // Default constructor
{
	setDefFloor();
	setColumnDetail();
}

void Level::setDefFloor() // Sets default floor shape
{
	m_floorDef.setFillColor(sf::Color::Green);
	m_floorDef.setSize(sf::Vector2f{ 480.0f, 82.0f });
	m_floorDef.setPosition(0.0f, 188.0f);
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
	m_columnSprite.setScale(2.0f, 2.0f);
}

sf::Sprite Level::getColumnDetail() // Returns column sprite
{
	return m_columnSprite;
}