#include <iostream>
#include <string>
#include <cstdlib> //needed to use random numbers
#include <ctime>
using namespace std;
void rules();

int main()
{

    string playername;
    int balance; //stores players balance
    int bettingamount;
    int guess;
    int dice; //stores the random number
    char choice;
    srand(time(0)); //seed the random generator
    cout << "\n\t\t========WELCOME TO THE CASINO WORLD========\n\n";
    cout << "What's your name: " << endl;
    getline(cin, playername);
    cout << "\n\nEnter the starting balance to play game: $";
    cin >> balance;

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << endl;
        // get player's betting balance
        do
        {
            cout << "Hey, " << playername << ", enter amount to bet : $ ";
            cin >> bettingamount;
            if (bettingamount > balance)
                cout << "Betting amount can't be more than current balance!" << endl
                     << "\nRe-enter balance" << endl;

        } while (bettingamount > balance);

        // get player's number
        do
        {
            cout << "Guess any betting number between 1 & 10 : ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be betwen 1 to 10 " << endl
                     << "Re-enter number: " << endl;
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won $" << bettingamount * 10;
            balance = balance + bettingamount * 10;
        }
        else
        {
            cout << "Oops, better luck next time!! You lost $ " << bettingamount << endl;
            balance = balance - bettingamount;
        }

        cout << "\nThe winning number was : " << dice << endl;
        cout << playername << ", you have balance of $ " << balance << endl;

        if (balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (Y/N)? " << endl;
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game.Your balance is $ " << balance << endl
         << endl;

    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t========CASINO NUMBER GUESS RULES!========" << endl;
    cout << "\t1. Choose number between 1 to 10 " << endl;
    cout << "\t2. Winner gets 10 times of the money bet" << endl;
    cout << "\t3. Wrong bet, and you lose the amount you bet " << endl
         << endl;
}