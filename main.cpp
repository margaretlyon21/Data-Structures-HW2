#include <iostream>
#include <random>
using namespace std;

class Wheel{
    private:
        int slots;
    public:
        //function to spin the roullete wheel with variable slot nuumber
        int spinWheel(){ 
            int result = rand() % slots + 1;
            return result;
        }
        // wheel constructor
        Wheel(int slots) : slots(slots) {}
};

class Player{
    private:
        int money;
        //instance of wheel class
        Wheel ourWheel;
    public:
        //getter and setter for money
        int getMoney(){
            return money;
        }
        void setMoney(int dollars){
            money += dollars;
        }
        // function to spin the users wheel 
        int spinOurWheel(){
            return ourWheel.spinWheel();
        }
        //player constructor
        Player(int money, int slots) : money(money), ourWheel(slots) {}
};
int main(){
    int slots, startingCash;
    bool correctSlots = false;
    cout << "Welcome to Roullete! \nEnter the amount of money you would like to play with. \n";
    cin >> startingCash;

    //Gets the number of slots in the wheel, checks if it is valid
    while (!correctSlots){ 
    if (slots > 20 | slots < 6){
        cout << "Enter the number of slots on the wheel (min 6, max 20): \n";
        cin >> slots;
        if (slots > 20 | slots < 6){
        cout << "Invalid number of slots for the wheel. Try again!\n";
        }
        else{
            correctSlots = true;
        }
    }
    }
    //starts a new game, calls constructor for the player
    cout << "******************** Starting Game *********************\n";
    Player user(startingCash, slots);
    Player house(startingCash, slots);

    //loops while the player still has money
    while (user.getMoney() > 0){
        int bet;
        cout << "Current money: $" << user.getMoney() << "\n";
        cout << "Enter bet: ";
        cin >> bet;

        //checks if entered bet is valid 
        if (bet > user.getMoney()){
            cout << "You don't have enough money for that!";
            continue;
        }

        //spins the wheel for the user and the house
        int userSpin = user.spinOurWheel();
        int houseSpin1 = house.spinOurWheel();
        int houseSpin2 = house.spinOurWheel();
        cout << "Spin Result: " << userSpin << endl;

        //Allows the user to change wager, checks if entry is valid
        char choice;
        bool correctChoice = false;
        while (!correctChoice){
            cout << "Do you want to double (d), halve (h), or keep (k) the current wager?\n";
            cin >> choice;
                if (choice == 'd' | choice == 'h' | choice == 'k'){
                    correctChoice = true;
                }
                else{
                    cout << "Invalid input. Enter, d, h, or k! \n";
                }    
        }

        bool win;
        //doubles bet and checks who wins if user choses double
        if (choice == 'd'){
            bet *= 2;
            cout << "First house spin: " << houseSpin1 << endl;
            cout << "Second house spin: " << houseSpin2 << endl;
            if (userSpin > houseSpin1 && userSpin > houseSpin2){
                win = true;
                user.setMoney(bet);
            }
            else{
                win = false;
                user.setMoney(-bet);
            }
        }
        // halves bet and checks who wins if user choses half
        else if (choice == 'h'){
            bet /= 2;
            cout << "First house spin: " << houseSpin1 << endl;
            cout << "Second house spin: " << houseSpin2 << endl;
            if (userSpin > houseSpin1 | userSpin > houseSpin2){
                win = true;
                user.setMoney(bet);
            }
            else{
                win = false;
                user.setMoney(-bet);
            }
        }
        //checks who wins if no change to wager 
        else {
            cout << "House spin: " << houseSpin1 << endl;
            if (userSpin > houseSpin1){
                win = true;
                user.setMoney(bet);
            }
            else{
                win = false;
                user.setMoney(-bet);
            }
        }
        
        if (win){
            cout << "Player wins! Current money: $" << user.getMoney() << endl;
        }
        else{
            cout << "House wins! Current money: $" << user.getMoney() << endl;
        }

        //if the user ran out of money, loop terminates
        if (user.getMoney() <= 0){
            cout << "You ran out of money.\n";
            cout << "******************** Game Over *********************\n";
            break;
        }

        //checks if the user wants to continue the game or cash out
        char continueGame;
        cout << "Do you want to continue playing? (y/n)";
        cin >> continueGame;
        if (continueGame != 'y' && continueGame != 'Y'){
            cout << "You cashed out with $" << user.getMoney() <<".\n";
            break;
        }
        else{
            cout << "******************** Next Round *********************\n";
        }
    }
}

