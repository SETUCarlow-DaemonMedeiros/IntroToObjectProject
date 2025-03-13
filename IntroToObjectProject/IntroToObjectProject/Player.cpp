#include "Player.h"

Player::Player() // Default constructor
{
	loadPlayerDefault();
	loadPlayerDetail();
}

void Player::loadPlayerDefault() // Sets default player shape
{
	m_playerDefault.setFillColor(sf::Color::Blue);
	m_playerDefault.setSize(sf::Vector2f{ 64.0f, 32.0f });
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
	m_knightSprite.setOrigin(32, 32);
	m_knightSprite.setPosition(240.0f, 200.0f);
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
		m_playerHeading = "None";
		break;
	case 2:
		m_playerHeading = "North";
		break;
	case 3:
		m_playerHeading = "South";
		break;
	case 4:
		m_playerHeading = "East";
		break;
	case 5:
		m_playerHeading = "West";
		break;
	case 6:
		m_playerHeading = "Throwing";
		break;
	default:
		m_playerHeading = "None";
		break;
	}
}

std::string Player::getPlayerHeading()
{
	return m_playerHeading;
}

void Player::setThrowing(bool t_throwing)
{
	m_throwing = t_throwing;
}

void Player::animatePlayer()
{
	int frame = 0;
	int rowNum = 0;
	const int SIZE = 64;

	m_frameCounter += m_frameIncrement; // Increases frame count by increment amount (speed it cycles through frames)
	frame = static_cast<int>(m_frameCounter); // Current frame count

	if (m_throwing == false)
	{
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
		}

		if (m_playerHeading == "North" || m_playerHeading == "South" || m_playerHeading == "East" || m_playerHeading == "West")
		{

			m_animationFrame = 6;
			m_frameIncrement = 0.2f;
			rowNum = 64;

			if (frame >= m_animationFrame)
			{
				frame = 0;
				m_frameCounter = 0.0f;
			}
		}
	}

	if (m_throwing == true)
	{
		m_playerHeading = "Throwing";

		m_animationFrame = 6;
		m_frameIncrement = 0.3f;
		rowNum = 128;

		if (frame >= m_animationFrame)
		{
			frame = 0;
			m_frameCounter = 0.0f;
			m_playerHeading = "None";
			m_throwing = false;
		}
	}
	m_knightSprite.setTextureRect(sf::IntRect{ frame * SIZE, rowNum, SIZE, SIZE });
}

void Player::movePlayerUp()
{
	int posx = m_knightSprite.getPosition().x;
	int posy = m_knightSprite.getPosition().y;

	if (m_knightSprite.getPosition().y > 130.0f)
	{
		m_playerHeading = "North";
		posy -= speed;
		m_knightSprite.setPosition(posx, posy);
	}
}

void Player::movePlayerDown()
{
	int posx = m_knightSprite.getPosition().x;
	int posy = m_knightSprite.getPosition().y;

	if (m_knightSprite.getPosition().y < 238.0f)
	{
		m_playerHeading = "South";
		posy += speed;
		m_knightSprite.setPosition(posx, posy);
	}
}

void Player::movePlayerRight()
{
	int posx = m_knightSprite.getPosition().x;
	int posy = m_knightSprite.getPosition().y;

	if (m_knightSprite.getPosition().x < 465.0f)
	{
		m_playerHeading = "East";
		posx += speed;
		m_knightSprite.setPosition(posx, posy);
		m_knightSprite.setScale (1.0, 1.0f);
	}
}

void Player::movePlayerLeft()
{
	int posx = m_knightSprite.getPosition().x;
	int posy = m_knightSprite.getPosition().y;

	if (m_knightSprite.getPosition().x > 16.0f)
	{
		m_playerHeading = "West";
		posx -= speed;
		m_knightSprite.setPosition(posx, posy);
		m_knightSprite.setScale(-1.0, 1.0f);
	}
}