#include "Bot.h"
Bot::Bot()
{
	m_texture.loadFromFile("./E-100.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.0f, m_sprite.getGlobalBounds().height / 2.0f);
	m_sprite.setPosition(sf::Vector2f(ScreenSize::s_width / 2.0f, ScreenSize::s_height / 2.0f));
}

void Bot::update(sf::Event& t_event, sf::RenderWindow& t_window)
{
	processCommands();
	//handleInput(t_event, t_window);
}


void Bot::processEvent(sf::Event& t_event, sf::RenderWindow& t_window)
{
	handleInput(t_event, t_window);
}


void Bot::handleInput(sf::Event& t_event, sf::RenderWindow& t_window)
{
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		if (t_event.mouseButton.button == sf::Mouse::Left)
		{
			m_mouseLeftButtonPressed = true;
		}
	}
	if (m_mouseLeftButtonPressed)
	{
		m_mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(t_window));
		std::cout << "mouse pos -- x:" << m_mousePos.x << " y: " << m_mousePos.y << "\n";
		m_queue.push(new MoveCommand(m_mousePos, m_sprite));
		m_mouseLeftButtonPressed = false;
	}
}

void Bot::processCommands()
{
	if (m_currentCommand != nullptr && !m_currentCommand->isFinished())
	{
		m_currentCommand->execute();
	}
	else if (m_queue.empty())
	{
		return;
	}
	else// otherwise grab the next command from the queue
	{
		if (m_currentCommand != nullptr)
		{
			m_currentCommand->setDirectionVec(sf::Vector2f(0.0f, 0.0f));
		}
		m_currentCommand = m_queue.front();
		m_queue.pop();
	}
}

void Bot::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_sprite);
}