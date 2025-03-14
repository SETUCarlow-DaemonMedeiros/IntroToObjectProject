#include "Level.h"

Level::Level() // Default constructor
{
	setDefFloor();
	setFloorDetail();
	setColumnDetail();
	setSkyDetail();
	setUpSunrays();
	setupClouds();
	setupCandles();
}

void Level::setDefFloor() // Sets default floor shape
{
	m_floorDef.setFillColor(sf::Color::Green);
	m_floorDef.setSize(sf::Vector2f{ 480.0f, 128.0f });
	m_floorDef.setPosition(0.0f, 142.0f);
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
	m_tileSprite.setTextureRect(sf::IntRect(0, 0, 480.0f, 142.0f));
	m_tileTexture.setRepeated(true);
}

sf::Sprite Level::getFloorDetail()
{
	return m_tileSprite;
}

void Level::setSkyDetail()
{
	if (!m_sunriseTexture.loadFromFile("ASSETS\\IMAGES\\sunrise.png"))
	{
		std::cout << "Issue loading floor tile texture" << std::endl;
	}

	m_sunriseSprite.setTexture(m_sunriseTexture);

	if (!m_sunsetTexture.loadFromFile("ASSETS\\IMAGES\\sunset.png"))
	{
		std::cout << "Issue loading floor tile texture" << std::endl;
	}

	m_sunsetSprite.setTexture(m_sunsetTexture);
}

sf::Sprite Level::getSunrise()
{
	return m_sunriseSprite;
}

sf::Sprite Level::getSunset()
{
	return m_sunsetSprite;
}

void Level::setColumnDetail() // Default values for column texture/sprite
{
	if (!m_columnTexture.loadFromFile("ASSETS\\IMAGES\\columns.png"))
	{
		std::cout << "Issue loading columns image" << std::endl;
	}

	m_columnSprite.setTexture(m_columnTexture);
}

sf::Sprite Level::getColumnDetail() // Returns column sprite
{
	return m_columnSprite;
}

void Level::setUpSunrays()
{
	if (!m_sunray1Text.loadFromFile("ASSETS\\IMAGES\\sunray1.png"))
	{
		std::cout << "Issue loading sunray #1 image" << std::endl;
	}
	if (!m_sunray2Text.loadFromFile("ASSETS\\IMAGES\\sunray2.png"))
	{
		std::cout << "Issue loading sunray #2 image" << std::endl;
	}

	m_sunray1Sprite.setTexture(m_sunray1Text);
	m_sunray2Sprite.setTexture(m_sunray2Text);
	m_opacity.a = 50.0f;
	m_opacity2.a = 25.0f;
	m_sunray1Sprite.setColor(m_opacity);
	m_sunray1Sprite.setColor(m_opacity2);
}

sf::Sprite Level::getSunrayOne()
{
	return m_sunray1Sprite;
}

sf::Sprite Level::getSunrayTwo()
{
	return m_sunray2Sprite;
}

void Level::animateSunrays()
{
	int flash = 1;

	if (fadeOut == true)
	{
		m_opacity.a -= flash;

		if (m_opacity.a <= 25) 
		{
			fadeOut = false;
		}
	}

	if (fadeOut == false)
	{
		m_opacity.a += flash;

		if (m_opacity.a >= 50)
		{
			fadeOut = true;
		}
	}
	if (fadeOut2 == true)
	{
		m_opacity2.a -= flash;

		if (m_opacity2.a <= 25)
		{
			fadeOut2 = false;
		}
	}

	if (fadeOut2 == false)
	{
		m_opacity2.a += flash;

		if (m_opacity2.a >= 50)
		{
			fadeOut2 = true;
		}
	}

	m_sunray1Sprite.setColor(m_opacity);
	m_sunray2Sprite.setColor(m_opacity2);
}

void Level::setupClouds()
{
	if (!m_cloud1Text.loadFromFile("ASSETS\\IMAGES\\clouds.png"))
	{
		std::cout << "Issue loading cloud image" << std::endl;
	}
	m_cloud1Sprite.setTexture(m_cloud1Text);
	
	m_cloud1Sprite.setOrigin(960, 0);
	m_cloud1Sprite.setPosition(960, 0);
}

sf::Sprite Level::getClouds1()
{
	return m_cloud1Sprite;
}

void Level::setupCandles()
{
	if (!m_candleText.loadFromFile("ASSETS\\IMAGES\\candles.png"))
	{
		std::cout << "Issue loading candle image" << std::endl;
	}
	m_candleSprite.setTexture(m_candleText);
}

sf::Sprite Level::getCandles()
{
	return m_candleSprite;
}

void Level::animateCandles()
{
	int frame = 0;
	int rowNum = 0;
	const int HEIGHT = 64;
	const int WIDTH = 480;

	m_frameCounter += m_frameIncrement; // Increases frame count by increment amount (speed it cycles through frames)
	frame = static_cast<int>(m_frameCounter); // Current frame count

	m_animationFrame = 8;
	m_frameIncrement = 0.15f;
	rowNum = 0;

	if (frame >= m_animationFrame)
	{
		frame = 0;
		m_frameCounter = 0.0f;
	}

	m_candleSprite.setTextureRect(sf::IntRect{rowNum, frame * HEIGHT, WIDTH, HEIGHT });
}

