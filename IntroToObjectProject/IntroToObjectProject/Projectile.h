#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Projectile
{

public:

	Projectile();

	void setupDart();
	sf::Sprite getDart();
	void setDartLocation(sf::Vector2f(t_location));
	void setFiring(bool t_firing);
	bool getFiring();
	void setThrown(bool t_thrown);
	bool getThrown();
	void moveDartRight();
	void resetAmmo();

private:

	sf::Texture m_dartTexture;
	sf::Sprite m_dartSprite;

	bool m_isFiring{ false };
	bool m_dartThrown{ false };

	int m_dartSpeed = 5;
};