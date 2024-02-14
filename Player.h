#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h"

class Player 
{
    public:
        Player(int startingMoney = 1000, int wheelValue = 10);

        int release();
        void changeWheelValue(int newValue);
        void win(int winAmount);
        void lose(int loseAmount);

        int getMoney() { return m_money; }
        void setMoney(int newMoney) { m_money = newMoney; }
    private:
        Wheel playerWheel;
        int m_money;
};


#endif