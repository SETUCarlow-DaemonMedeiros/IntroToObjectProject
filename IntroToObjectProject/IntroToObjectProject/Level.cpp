#include "Level.h"

Level::Level() // Default constructor
{
	setDefFloor();
	setFloorDetail();
	setColumnDetail();
}

void Level::setDefFloor() // Sets default floor shape
{
	m_floorDef.setFillColor(sf::Color::Green);
	m_floorDef.setSize(sf::Vector2f{ 480.0f, 128.0f });
	m_floorDef.setPosition(0.0f, 174.0f);
}

sf::RectangleShape Level::getDefFloor() // Returns default floor shape
{
	return m_floorDef;
}

void Level::setFloorDetail()
{
	if (!m_tileTexture.loadFromFile("ASSETS\\IMAGES\\stonefloor1.png"))
	{
		std::cout << "Issue loading floor tile texture" << std::endl;
	}

	m_tileSprite.setTexture(m_tileTexture);
	m_tileSprite.setPosition(m_floorDef.getPosition());
	m_tileSprite.setTextureRect(sf::IntRect(0, 0, 480.0f, 128.0f));
	m_tileTexture.setRepeated(true);
}

sf::Sprite Level::getFloorDetail()
{
	return m_tileSprite;
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