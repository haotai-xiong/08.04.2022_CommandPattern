#include "Command.h"

MoveCommand::MoveCommand(sf::Vector2f& t_destination, sf::Sprite& t_sprite)
	:
	m_destination(t_destination),
	m_sprite(t_sprite)
{
}

void MoveCommand::execute()
{
	if (m_directionVec.x == 0.0f && m_directionVec.y == 0.0f)
	{
		m_pathVec = m_destination - m_sprite.getPosition();
		m_normalisation = sqrtf(m_pathVec.x * m_pathVec.x + m_pathVec.y * m_pathVec.y);
		m_directionVec.x = m_pathVec.x / m_normalisation;
		m_directionVec.y = m_pathVec.y / m_normalisation;
	}
	else
	{
		//std::cout << "destination x: " << m_destination.x << " y: " << m_destination.y << "\n";
		//std::cout << "m_directionVec x: " << m_directionVec.x << " y: " << m_directionVec.y << "\n";
		m_sprite.move(m_directionVec);
	}
}

bool MoveCommand::isFinished()
{
	m_distanceVec = m_destination - m_sprite.getPosition();
	m_distanceToDestination = sqrtf(m_distanceVec.x * m_distanceVec.x + m_distanceVec.y * m_distanceVec.y);
	//std::cout << "distance to destination :" << m_distanceToDestination << "\n";
	if (m_distanceToDestination < m_distanceThreshold)
	{
		m_directionVec = sf::Vector2f(0.0f, 0.0f);
		return true;
	}
	else
	{
		return false;
	}
}
