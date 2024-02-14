#include <iostream>

#include "Wheel.h"
#include "Player.h"

using namespace std;

int main()
{
    bool isPlaying = true;

    string inText;

    cout << "Hi, welcome to this wheel game thing." << endl;

    cout << "How much money do you want to use to play this session? ";
    int startingMoney;
    cin >> startingMoney;
    while (startingMoney <= 0)
    {
        cout << "You can't bring nothing!" << endl;
        cout << "How much money do you want to use to play this session? ";
        cin >> startingMoney;
    }

    cout << "How much values do you want to be on the wheels (min: 6, max: 20)? ";
    int wheelValue;
    cin >> wheelValue;
    while (wheelValue < 6 || wheelValue > 20)
    {
        cout << "Invalid amount!" << endl;
        cout << "How much values do you want to be on the wheels (min: 6, max: 20)? ";
        cin >> wheelValue;
    }

    Player p = Player(startingMoney, wheelValue);
    Wheel house = Wheel(wheelValue);

    int input;
    string inText;
    while (isPlaying)
    {
        cout << "You currently have " << p.getMoney() << "$" << endl;

        cout << "How much do you wanna bet? ";
        int betAmount;
        cin >> betAmount;
        while (betAmount < 0 || betAmount > p.getMoney())
        {
            cout << "Invalid amount!" << endl;
            cout << "How much do you wanna bet? ";
            cin >> betAmount;
        }

        int playerRoll = p.release();

        cout << "You roll a " << playerRoll << "! Do you want to Keep, Halve, or Double your bet (1, 2, 3)? ";
        cin >> input;
        while (input != 1 && input != 2 && input != 3)
        {
            cout << "Invalid input!" << endl;
            cout << "Do you want to Keep, Halve, or Double your bet (1, 2, 3)? ";
            cin >> input;
        }

        switch (input)
        {
        case 1: // Keep, so house roll once
            int houseRoll = house.Spin();
            cout << "House roll a " << houseRoll << "! ";
            if (houseRoll < playerRoll) 
            {
                cout << "You win " << betAmount << "$" << endl;
                p.win(betAmount);
            }
            else 
            {
                cout << "You lose " << betAmount << "$" << endl;
                p.lose(betAmount);
            }
            break;

        case 2: // Halve, so house roll twice, player hold money if house doesn't win both
            int houseRoll1 = house.Spin();
            int houseRoll2 = house.Spin();
            cout << "House roll a " << houseRoll1 << " and " << houseRoll2 << "! ";

        case 3: // Double, player lose double if house win one, but win double if player win both
        
        default:
            break;
        }

        
        cout << "Do you want to cash out (type 0 to cash out, type anything to continue)? ";
        cin >> inText;
        if (inText == "0") isPlaying = false;
    }

    return 0;
}