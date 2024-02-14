#ifndef WHEEL_H
#define WHEEL_H

class Wheel 
{
    public:
        Wheel(int maxVal = 10);
        int Spin();

        void setMax(int newMax);
        int getMax() { return m_maxValue; }
    private:
        int m_maxValue;
};


#endif