#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare and Initialize Constants
    const double DOLLAR_BILL_THICKNESS_INCHES = 0.0043;
    
    // Declare and Initialize Variables
    double travel_distance = 0;
    double debt = 0;
    double dollar_miles = 0;
    double dollar_feet = 0;
    double dollar_inches = 0;
    double trips = 0;
    
    // Obtain Distance From User
    cout << "Enter distance (miles): ";
    cin >> travel_distance;
    
    // Obtain Debt Amount Input From User
    cout << "Enter debt ($): ";
    cin >> debt;
    
    // Calculate Total Height In Inches
    dollar_inches = debt * DOLLAR_BILL_THICKNESS_INCHES;
    
    // Convert Inches To Feet
    dollar_feet = dollar_inches / 12.0;
    
    // Convert Feet To Miles
    dollar_miles = dollar_feet / 5280.0;
    
    // Calculate Number of Trips
    trips = dollar_miles / travel_distance;
    
    // Output Initial Inputs
    cout << "For a debt of $" << fixed << right << setw(15) << setprecision(2) << debt << endl;
    cout << "and a distance of " << fixed << right << setw(25) << setprecision(4) << travel_distance << " miles" << endl;
    
    // Output Number of Trips Result
    cout << "You can make " << fixed << left << setw(5) << setprecision(0) << trips << " trips." << endl;
    
    return 0;
}
