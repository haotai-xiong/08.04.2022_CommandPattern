#pragma once
#include "ScreenSize.h"

class Command 
{
public: 
	virtual ~Command() {} 
	virtual void execute() = 0;
	virtual bool isFinished() = 0;
	virtual void setDirectionVec(sf::Vector2f t_directionVec) = 0;
};

class MoveCommand : public Command {
public:
	MoveCommand(sf::Vector2f& t_destination, sf::Sprite& t_sprite); 
	virtual void execute() override;
	virtual bool isFinished() override;
	virtual void setDirectionVec(sf::Vector2f t_directionVec) { m_directionVec = t_directionVec; }

private:
	sf::Vector2f& m_destination;
	sf::Vector2f m_distanceVec{ 0.0f, 0.0f };
	float m_distanceToDestination{ 0.0f };
	sf::Vector2f m_pathVec{ 0.0f, 0.0f };
	float m_normalisation{ 0.0f };
	sf::Sprite& m_sprite;
	sf::Vector2f m_directionVec{ 0, 0 };
	// thresh hold
	float m_distanceThreshold{ 1.0f };
	//sf::Vector2f m_directionThreshold{ m_distanceThreshold ,m_distanceThreshold };
};