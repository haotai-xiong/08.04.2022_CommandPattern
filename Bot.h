#pragma once
#include <queue>
#include "Command.h"

class Bot {
public:
	Bot();
	void update(sf::Event& t_event, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);
	void processEvent(sf::Event& t_event, sf::RenderWindow& t_window);

	void handleInput(sf::Event& t_event, sf::RenderWindow& t_window);
	void processCommands(); 
private:
	Command* m_currentCommand{ nullptr };
	std::queue<Command*> m_queue;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_mousePos;
	bool m_mouseLeftButtonPressed{ false };
};