#include "GameState.h"

GameState::GameState()
	: m_currentLevel(1), m_playerLives(3)
{

}

int GameState::getLevel() const
{
	return this->m_currentLevel;
}

void GameState::setLevel(int _level)
{
	this->m_currentLevel = _level;
}
	
int GameState::getPlayerLives() const
{
	return this->m_playerLives;
}

void GameState::setPlayerLives(int _lives)
{
	this->m_playerLives = _lives;
}
