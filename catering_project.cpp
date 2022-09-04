#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    string NameOfEvent, CustomerName;
    double NumberOfGuest;
    int NumberOfMinutes;

    cout << "Enter the name of the events " << endl;
    getline(cin, NameOfEvent);
    cout << "Enter the costumer's first and last name " << endl;
    getline(cin, CustomerName);
    cout << "Enter the no. of guests " << endl;
    cin >> NumberOfGuest;
    cout << "Enter the no. of minutes in the event " << endl;
    cin >> NumberOfMinutes;

    cout << "Fall Dinner  " << endl;
    cout << "Event estimate for " << CustomerName << endl;

    int NumberOfServers, Cost1;
    double CostForOneServer, Test, TotalFoodCost, AverageCost, Cost2, DepositAmount, Totalcost;

    const double CostPerHour = 18.50;
    const double CostPerMinute = .40;
    const double CostOfDinner = 20.70;

    // get no. of servers
    Test = NumberOfGuest / 20;
    NumberOfServers = ceil(Test);

    // get cost of one server
    Cost1 = (NumberOfMinutes / 60) * CostPerHour;
    Cost2 = (NumberOfMinutes % 60) * CostPerMinute;
    CostForOneServer = Cost1 + Cost2;

    // get cost for food
    TotalFoodCost = NumberOfGuest * CostOfDinner;

    // get average per person
    AverageCost = TotalFoodCost / NumberOfGuest;

    // get total cost
    Totalcost = TotalFoodCost + (CostForOneServer * NumberOfServers);

    // get deposit amount(25%)
    DepositAmount = Totalcost * .25;

    // print values above
    cout << "Number of servers: " << NumberOfServers << fixed << setprecision(2) << endl;
    cout << "The cost for servers: " << setw(5) << CostForOneServer << endl;
    cout << "The cost for food is: " << setw(5) << TotalFoodCost << endl;
    cout << "Average cost per person: " << setw(5) << AverageCost << endl;
    cout << endl;
    cout << "Total cost is: " << setw(5) << Totalcost << endl;
    cout << endl;
    cout << "Please deposit a 25% deposit to reserve the event " << endl;
    cout << "The deposit needed is: " << setw(5) << DepositAmount << endl;

    return 0;
}