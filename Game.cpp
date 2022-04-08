#include "Game.h"

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;

////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "SFML Playground", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	while (m_window.isOpen())
	{
		sf::Event event;
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents(event);

		while (lag > MS_PER_UPDATE)
		{
			//update(event ,lag);
			lag -= MS_PER_UPDATE;
		}
		update(event, lag);
		render();
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents(sf::Event& t_event)
{
	while (m_window.pollEvent(t_event))
	{
		if (t_event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		processGameEvents(t_event);
	}
}

////////////////////////////////////////////////////////////
void Game::processGameEvents(sf::Event& t_event)
{
	// check if the event is a a mouse button release
	if (sf::Event::KeyPressed == t_event.type)
	{
		switch (t_event.key.code)
		{
		case sf::Keyboard::Escape:
			m_window.close();
			break;
		case sf::Keyboard::Up:
			// Up key was pressed...
			break;
		default:
			break;
		}
	}
	m_bot.processEvent(t_event, m_window);
}

////////////////////////////////////////////////////////////
void Game::update(sf::Event& t_event,double dt)
{
	m_bot.update(t_event, m_window);
}

////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	m_bot.render(m_window);
	m_window.display();
}





