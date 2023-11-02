#include "Entity.h"

Entity::Entity(int _objectID, std::string _objectName, sf::Vector2f _objectSize, sf::Vector2f _objectPosition, std::string _objectTexture, size_t frameQty)
	: m_objectID(_objectID), m_objectName(_objectName), m_objectPosition(_objectPosition)
{
	this->m_objectShape.setSize( _objectSize );
	this->m_objectTexture = std::make_unique<sf::Texture>();

	if (!this->m_objectTexture->loadFromFile(_objectTexture))
	{
		std::cout << "Failed to load texture for object with id " << m_objectID << " and name " << m_objectName << std::endl;
	}

	this->m_objectSprite.setTexture(*this->m_objectTexture);

	for (size_t i = 0; i < frameQty; i++)
	{
		this->m_animationFrames.push_back(sf::IntRect(i*48, 21, 32, 32)); 
	}
	
	this->m_objectSprite.setTextureRect(this->m_animationFrames[this->m_currentFrame]);

	this->m_objectSprite.setScale(2, 2);

	this->setObjectPosition(this->m_objectPosition);
}

Entity::~Entity()
{

}

void Entity::update(const std::vector<Entity>& entities, float elapsedTime, const InputState& inputState, const GameState& gameState)
{
	//todo
}

void Entity::render(sf::RenderTarget& _target)
{
	_target.draw(this->m_objectSprite);
}

void Entity::updateAnimation(float _elapsedTime)
{
	this->m_elapsedTime += _elapsedTime;

	if (this->m_elapsedTime >= this->m_frameTime)
	{
		this->m_elapsedTime = 0.0f;

		this->m_currentFrame = (this->m_currentFrame + 1) % this->m_animationFrames.size();

		this->m_objectSprite.setTextureRect(this->m_animationFrames[this->m_currentFrame]);
	}
}

bool Entity::isCollidingWith(const Entity& _otherEntity) const
{
	return (this->m_objectPosition.x < _otherEntity.m_objectPosition.x + _otherEntity.m_objectShape.getSize().x &&
		this->m_objectPosition.x + this->m_objectShape.getSize().x > _otherEntity.m_objectPosition.x &&
		this->m_objectPosition.y < _otherEntity.m_objectPosition.y + _otherEntity.m_objectShape.getSize().y &&
		this->m_objectPosition.y + m_objectShape.getSize().y > _otherEntity.m_objectPosition.y);
}

void Entity::handleCollisionWith(Entity& _otherEntity)
{
	//todo
}

void Entity::setObjectPosition(sf::Vector2f _objectPosition)
{
	this->m_objectPosition.x = _objectPosition.x;
	this->m_objectPosition.y = _objectPosition.y;
	this->m_objectSprite.setPosition(this->m_objectPosition);
}

sf::Vector2f Entity::getObjectPosition() const
{
	return this->m_objectPosition;
}
