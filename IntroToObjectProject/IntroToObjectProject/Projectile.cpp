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