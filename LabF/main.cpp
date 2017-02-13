// Lab F
// A program that provides a list of mathematical operations that the user can choose from. The user will then provide the two operands.
// The program will perform the operation and output the result back to the user. This will repeat until the user chooses to quit. 
// Christopher M. Anderson
// 2016-09-29

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

// PROTOTYPE FOR NON-MEMBER FUNCTION TO DISPLAY MENU TO USER
void userMenu(int&);

// PROTOTYPE FOR CLASS MEMBER FUNCTION
class Calculator{
    
    // Declare variables for left operand, right operand, and result
    double _lOp,_rOp,_result;

    public:
    
        // Takes a value and sets the left operand to the value; returns nothing
        void SetLeft(double);

        // Analagous to SetLeft, except operates on the right operand
        void SetRight(double);

        // Stores the product of left * right into result; returns nothing
        void Multiply();

        // Stores the quotient of left / right into result; returns nothing
        void Divide();

        // Stores the sum of left + right into result; returns nothing
        void Add();

        // Stores the difference of left - right into result; returns nothing
        void Subtract();

        // Raises the left operand to the power of the right and stores the result into result; returns nothing
        void Exponent();

        // An accessor that returns the value of the result
        double GetResult() const;
};

// BEGIN MAIN FUNCTION
int main(){
    
    // Declare and initialize variable to store user's choice and operands
    int userChoice = 0;
    double left = 0.0;
    double right = 0.0;
    int repeat = 0;
    
    // Do/While statement to print menu and input user's choice
    // Then calls class member functions based on user choice or quits
    // Also ensures choice is valid (between 1 and 6)
    do {
        
        // Print menu and get user's choice
        userMenu(userChoice); 
    
        // If user chooses 6 exit, otherwise input operands from user
        if(userChoice == 6){
            // Set repeat variable to 1 to break the loop.
            repeat = 1;
        } else {
            
            // Request operands from user
            cout << "Enter operands: ";

            // Input operands from user
            cin >> left >> right;
            
            // Initialize new instance of calculator class
            Calculator calc;
            
            // Set class member functions
            calc.SetLeft(left);
            calc.SetRight(right);
            
            // Call desired class member function
            switch(userChoice){
                case 1:{
                    calc.Add();         // Call Calculator::Add Function
                    break;
                }
                case 2:{
                    calc.Subtract();    // Call Calculator::Subtract Function
                    break;
                }
                case 3:{
                    calc.Multiply();    // Call Calculator::Multiply Function
                    break;
                }
                case 4:{
                    calc.Divide();      // Call Calculator::Divide Function
                    break;
                }
                case 5:{
                    calc.Exponent();    // Call Calculator::Exponent Function
                    break;
                }
                default:{
                    break;
                }
            }
            
            // Output results to user
            cout << endl;
            cout << "Result = " << fixed << setprecision(3) << calc.GetResult() << endl;

        }    
    
    } while (repeat == 0);
    
    return 0;
}

// NON-MEMBER FUNCTION TO DISPLAY MENU TO USER
void userMenu(int& userChoiceF){
l
    do {
        
        // Output user menu options
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exponent" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter operation: ";
            
        // Input choice from user
        cin >> userChoiceF;
        
    } while (!(userChoiceF > 0 && userChoiceF < 7));

}

// CLASS MEMBER FUNCTIONS

// Takes a value and sets the left operand to the value; returns nothing
void Calculator::SetLeft(double left){
    _lOp = left;
}

// Analagous to SetLeft, except operates on the right operand
void Calculator::SetRight(double right){
    _rOp = right;
}

// Stores the product of left * right into result; returns nothing
void Calculator::Multiply() {
    _result = _lOp * _rOp;
}

// Stores the quotient of left / right into result; returns nothing
void Calculator::Divide() {
    _result = _lOp / _rOp;
}

// Stores the sum of left + right into result; returns nothing
void Calculator::Add() {
    _result = _lOp + _rOp;
}

// Stores the difference of left - right into result; returns nothing
void Calculator::Subtract() {
    _result = _lOp - _rOp;
}

// Raises the left operand to the power of the right and stores the result into result; returns nothing
void Calculator::Exponent() {
    _result = pow(_lOp,_rOp);
}

// An accessor that returns the value of the result
double Calculator::GetResult() const {
    return _result;
}