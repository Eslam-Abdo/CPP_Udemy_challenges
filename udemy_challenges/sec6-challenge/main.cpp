
// Section 6
// Challenge

/* 
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>

using namespace std;

int main() {
    const short price_per_small_room {25};
    const short price_per_large_room {35};
    const float tax {0.06};
    const short estimates_valid_days {30};

    int number_per_small_room {25};
    int number_per_large_room {35};
    
    cout << "Welcome to Frank's Carpet Cleaning Service" << endl;

    cout << "\nEnter the number per small room: " ;
    cin >> number_per_small_room;
    
    cout << "\nEnter the number per large room: " ;
    cin >> number_per_large_room;

    cout << "\nEstimate for carpet cleaning service" ;

    cout << "\nNumber of small rooms: " << number_per_small_room;
    cout << "\nNumber of large rooms: " << number_per_large_room;

    cout << "\nPrice per small room: $" << price_per_small_room;
    cout << "\nPrice per large room: $" << price_per_large_room;

    int cost;
    cost = number_per_small_room * price_per_small_room + number_per_large_room * price_per_large_room;

    cout << "\nCost: " << cost;
    cout << "\nTax: $" << tax;
    
    cout << "\n===============================";
    
    double total_estimates;
    total_estimates = tax * cost + cost;

    cout << "\nTotal estimate: $" << total_estimates;
    cout << "\nThis estimate is valid for " << estimates_valid_days << " days";

    cout << endl;
    return 0;
}

