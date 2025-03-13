#include "Player.h"

Player::Player() // Default constructor
{
	loadPlayerDefault();
	loadPlayerDetail();
}

void Player::loadPlayerDefault() // Sets default player shape
{
	m_playerDefault.setFillColor(sf::Color::Blue);
	m_playerDefault.setSize(sf::Vector2f{ 16.0f, 32.0f });
	m_playerDefault.setOrigin(8.0, 32.0);
	m_playerDefault.setPosition(240.0f, 250.0f);
}

sf::RectangleShape Player::getPlayerDefault() // Returns default player shape
{
	return m_playerDefault;
}

void Player::loadPlayerDetail()
{
	if (!m_knightTexture.loadFromFile("ASSETS\\IMAGES\\playeranimation.png"))
	{
		std::cout << "Issue loading knight texture" << std::endl;
	}

	m_knightSprite.setTexture(m_knightTexture);
	m_knightSprite.setOrigin(32, 64);
	m_knightSprite.setPosition(m_playerDefault.getPosition());
}

sf::Sprite Player::getPlayerDetail()
{
	return m_knightSprite;
}

void Player::setPlayerHeading(int t_heading)
{
	switch (t_heading)
	{
	case 1:
		m_playerHeading = "North";
		break;
	case 2:
		m_playerHeading = "NorthEast";
		break;
	case 3:
		m_playerHeading = "East";
		break;
	case 4:
		m_playerHeading = "SouthEast";
		break;
	case 5:
		m_playerHeading = "South";
		break;
	case 6:
		m_playerHeading = "SouthWest";
		break;
	case 7:
		m_playerHeading = "West";
		break;
	case 8:
		m_playerHeading = "Northwest";
		break;
	case 9:
		m_playerHeading = "None";
	default:
		m_playerHeading = "None";
		break;
	}
}

std::string Player::getPlayerHeading()
{
	return m_playerHeading;
}

void Player::animatePlayer()
{
	int frame = 0;
	int rowNum = 0;
	const int SIZE = 64;

	m_frameCounter += m_frameIncrement; // Increases frame count by increment amount (speed it cycles through frames)
	frame = static_cast<int>(m_frameCounter); // Current frame count

	if (m_playerHeading == "None")
	{

		m_animationFrame = 5;
		m_frameIncrement = 0.15f;
		rowNum = 0;

		if (frame >= m_animationFrame)
		{
			frame = 0;
			m_frameCounter = 0.0f;
		}

		if (frame != m_knightFrame)
		{
			m_knightFrame = frame;
			m_knightSprite.setTextureRect(sf::IntRect{ frame * SIZE, rowNum, SIZE, SIZE });
		}
	}
}

void Player::movePlayer()
{
	int posx = m_knightSprite.getPosition().x;
	int posy = m_knightSprite.getPosition().y;

	if (m_playerHeading == "North")
	{
		posy -= speed;
	}

	else if (m_playerHeading == "NorthEast")
	{
		posx += speed;
		posy -= speed;
	}

	else if (m_playerHeading == "East")
	{
		posx += speed;
	}

	else if (m_playerHeading == "SouthEast")
	{
		posx += speed;
		posy += speed;
	}

	else if (m_playerHeading == "South")
	{
		posy += speed;
	}

	else if (m_playerHeading == "SouthWest")
	{
		posx -= speed;
		posy += speed;
	}

	else if (m_playerHeading == "West")
	{
		posx -= speed;
	}

	else if (m_playerHeading == "NorthWest")
	{
		posx -= speed;
		posy -= speed;
	}

	m_knightSprite.setPosition(posx, posy);
}
