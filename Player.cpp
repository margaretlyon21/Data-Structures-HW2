#include <iostream>
#include <random>

#include "Player.h"

Player::Player(int startingMoney, int wheelValue)
{
    m_money = startingMoney;
    playerWheel = Wheel(wheelValue);
}

void Player::win(int winAmount)
{
    m_money += winAmount;
}

void Player::lose(int loseAmount)
{
    m_money -= loseAmount;
}

int Player::release()
{
    return playerWheel.Spin();
}

void Player::changeWheelValue(int newValue)
{
    playerWheel.setMax(newValue);
}