/// <summary>
/// #pragma once used so we don't process this file twice
/// </summary>
#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"

class Game
{
public:
	Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void loadAssets();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	sf::RenderTexture m_renderTarget;
	sf::Sprite m_renderTargetSprite;
	sf::View scaledView;

	Level m_levelOne;
	Player m_playerOne;
};