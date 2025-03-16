#include "Projectile.h"

Projectile::Projectile() // Default constructor
{
	setupDart();
}

void Projectile::setupDart()
{
	if (!m_dartTexture.loadFromFile("ASSETS\\IMAGES\\dart.png"))
	{
		std::cout << "Issue loading dart texture" << std::endl;
	}
	m_dartSprite.setTexture(m_dartTexture);
	m_dartSprite.setOrigin(32, 22);
	m_dartSprite.setPosition(240, 200);
}

sf::Sprite Projectile::getDart()
{
	return m_dartSprite;
}

void Projectile::setDartLocation(sf::Vector2f(t_location))
{
	m_dartSprite.setPosition(t_location);
}

void Projectile::setFiring(bool t_firing)
{
	m_isFiring = t_firing;
}

bool Projectile::getFiring()
{
	return m_isFiring;
}

void Projectile::setThrown(bool t_thrown)
{
	m_dartThrown = t_thrown;
}

bool Projectile::getThrown()
{
	return m_dartThrown;
}

void Projectile::moveDartRight()
{
	int posx = m_dartSprite.getPosition().x;
	int posy = m_dartSprite.getPosition().y;

	m_dartSprite.setScale(1.0f, 1.0f);

	if (m_isFiring == true)
	{
		if (m_dartThrown == false)
		{
			posx += m_dartSpeed;
			m_dartSprite.setPosition(posx, posy);

			if (m_dartSprite.getPosition().x > 480)
			{
				m_dartThrown = true;
				resetAmmo();
			}
		}
	}
}

void Projectile::resetAmmo()
{
	
	m_dartSprite.setPosition(240, 200);
}
