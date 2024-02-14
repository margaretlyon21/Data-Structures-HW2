#include <iostream>
#include <random>

#include "Wheel.h"

Wheel::Wheel(int maxVal)
{
    m_maxValue = maxVal;
}

int Wheel::Spin()
{
    return rand() % m_maxValue + 1;
}

void Wheel::setMax(int newMax)
{
    if (newMax < 6) newMax = 6;
    if (newMax > 20) newMax = 20;
    m_maxValue = newMax;
}