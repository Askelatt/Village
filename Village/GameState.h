#pragma once
class GameState
{
public:
    GameState();

    int getLevel() const;
    void setLevel(int _level);

    int getPlayerLives() const;
    void setPlayerLives(int _lives);


private:
    int m_currentLevel;
    int m_playerLives;
   
    // (todo) add other parameters of game state

};

