// Lab D
// A program that allows a customer to contact customer support based on an error code and the number of days
// they have been experiencing a problem with their universal remote control device. The program will then
// allow the user to add another error code should they desire to continue or to exit the program completely.
// Christopher M. Anderson
// 2016-09-06

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    // Declare and Initialize Variable for Running Program Again
    char runAgain = 'n';

    // Delcare and Initialize Variables for Error Code and Problem Duration
    int errorCode = 0; // 1 - 8
    int problemDuration = 0; // Number of Days
    
    // Declare and Initialize Variables for Problem Description and Urgency
    string problemDescription = "";
    string problemUrgency = "";
    
    do {

        // Request User Input of Given Error Code and Number of Days the Problem Has Occurred
        cout << "Enter code: ";
        cin >> errorCode;
        cout << "Enter problem duration: ";
        cin >> problemDuration;
        
        // Determine Problem Description Based on Error Code
        switch(errorCode){
            case 1:
            case 2:
            case 3:{
                problemDescription = "IR malfunction";
                break;
            }
            case 4:{
                problemDescription = "receiver malfunction";
                break;
            }
            case 5:
            case 6:
            case 7:
            case 8:{
                problemDescription = "low battery";
                break;
            }
            default:{
                problemDescription = "unknown malfunction";
                break;
            }
        }
        
        
        // Determine Problem Urgency Based on Duration of Problem and Error Code
        if (problemDuration <= 7){
            if (errorCode == 1 || errorCode == 3){
                problemUrgency = "very low";
            } else {
                problemUrgency = "low";
            }
        } else if (problemDuration > 7 && problemDuration <= 14){
            if (errorCode == 6 || errorCode == 7){
                problemUrgency = "high";
            } else {
                problemUrgency = "medium";
            }
        } else {
            problemUrgency = "high";
        }
        
        // Output Problem Urgency and Description
        cout << "New " << problemUrgency << " urgency request for " << problemDescription << "." << endl;        

        // Determine If User Wants To Run Program Again
        cout << "Enter another code? ";
        cin >> runAgain;

    } while (runAgain != 'n' && runAgain != 'N');
    
	return 0;

}