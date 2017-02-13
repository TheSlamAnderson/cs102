// Lab C
// A program that calculates change based on cost and money tendered.
// Christopher M. Anderson
// 2016-08-30

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Declare and Initialize Variables for Cost, Money, and Change
    double cost = 0;
    double money = 0;
    double change = 0;
    
    // Request Cost of Item From User And Ensure Cost Is Less Than $100,000.
    do {
        cout << "Enter cost $";
        cin >> cost;
    } while (cost > 100000.00);
    
    // Request Money Given From User And Ensure It Is Greater Than $0.
    do {
        cout << "Enter money $";
        cin >> money;
    } while (money <= 0);
    
    // Output Blank Line
    cout << endl;
    
    // Calculate Change Due
    change = money - cost;
    
    // Output Amount of Change If Any Is Due
    if (change < 0){
        cout << "Customer did not give you enough money." << endl;
    } else if (change == 0) {
        cout << "Customer paid exact change." << endl;
    } else {
        cout << "Give the customer $" << fixed << setprecision(2) << change << "." << endl;
    }
    
	return 0;
}
