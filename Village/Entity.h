#pragma once

#include "SFML/Graphics.hpp"

#include "InputState.h"
#include "GameState.h"

#include <iostream>

class Entity
{
public:
	Entity(int _objectID, std::string _objectName, sf::Vector2f _objectSize, sf::Vector2f _objectPosition, std::string _objectTexture, size_t frameQty);

	virtual ~Entity();

	virtual void update(const std::vector<Entity>& _entities, float _elapsedTime, const InputState& _inputState, const GameState& _gameState);

	virtual void render(sf::RenderTarget & _target);

	virtual void updateAnimation(float _elapsedTime);

	bool isCollidingWith(const Entity& _otherEntity) const;

	void handleCollisionWith(Entity& _otherEntity);

	void setObjectPosition(sf::Vector2f _objectPosition);

	sf::Vector2f getObjectPosition() const;

private:
	sf::Vector2f m_objectPosition;

	sf::RectangleShape m_objectShape;

	std::unique_ptr< sf::Texture > m_objectTexture;

	sf::Sprite m_objectSprite;

	int m_objectID;

	std::string m_objectName;

	std::vector<sf::IntRect> m_animationFrames;

	int m_currentFrame;
	
	float m_frameTime = 0.2f;
	
	float m_elapsedTime;
};

