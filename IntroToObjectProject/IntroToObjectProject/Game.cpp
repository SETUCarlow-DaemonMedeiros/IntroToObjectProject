#include "Game.h"
#include <iostream>
/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 960U, 540U, 32U }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
	/// Creating a viewport that scales images to the window size
	sf::View scaledView(sf::Vector2f{ 240,135 }, sf::Vector2f{ 480,270 }); // First vector is where the center of camera is, second value is full resolution size
	m_window.setView(scaledView);// sets a view on existing window
	m_renderTarget.create(480, 270); // New resolution regardless of window size
	m_renderTargetSprite.setTexture(m_renderTarget.getTexture());
	///

	loadAssets();
}

/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
#ifdef _DEBUG
			render(); // want to debug drawing while stepping through code
#endif // _DEBUG

		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}

/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Updates the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (t_deltaTime.asMilliseconds() != 16)
	{
		std::cout << "time warp" << std::endl; // expecting 60 fps of action
	}
	if (m_exitGame)
	{
		m_window.close();
	}

	m_playerOne.animatePlayer();
}

/// <summary>
/// Draws the frame
/// </summary>
void Game::render()
{
	m_renderTarget.clear(sf::Color::White);

	m_renderTarget.draw(m_levelOne.getFloorDetail());
	m_renderTarget.draw(m_levelOne.getColumnDetail());
	m_renderTarget.draw(m_playerOne.getPlayerDetail());


	m_renderTarget.display();
	m_window.draw(m_renderTargetSprite);
	m_window.display();
}

// This is empty: link to class methods that load images and audio.
void Game::loadAssets()
{

}