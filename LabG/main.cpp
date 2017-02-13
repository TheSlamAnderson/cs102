// Lab G
// Program that creates a simplified array class that stores strings inside of an array.
// The class has logic to allow for one-based indexing, whereas the first element is 1, not 0.
// This is to help those programmers just being introduced to arrays have an easier time. 
// Christopher M. Anderson
// 2016-10-05

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// DECLARE AND INITIALIZE CONSTANT FOR ARRAY SIZE
const unsigned int MAX_ARRAY_SIZE = 30;

// PROTOTYPE FOR CLASS MEMBER FUNCTION
class SimpleArray{

    // A private array of strings with a maximum size of MAX_ARRAY_SIZE.
    string myArray[MAX_ARRAY_SIZE];

    public:

        // A public member function that returns a bool and takes an integer and a string.
        bool setVal(const unsigned int &, const string &);

        // A public member function that returns a string and takes an integer.
        string getVal(const unsigned int &) const;

};

// PROTOTYPE FOR NON-MEMBER FUNCTION TO DISPLAY MENU TO USER
void userMenu(char&);

// PROTOTYPE FOR NON-MEMBER FUNCTION TO INITIALIZE EMPTY ARRAY
SimpleArray initArr();

// BEGIN MAIN FUNCTION
int main(){

    // Declare and initialize variable to store user's choice and repeat.
    char userChoice = 'a';
    unsigned int repeat = 0;
    
    // Initial Empty Array
    SimpleArray SA = initArr();

    // Do/While statement to print menu and input user's choice
    // Then calls class member functions based on user choice or quits   
    do {
    
        // Print menu and get user's choice.
        userMenu(userChoice);
        
        // If user chooses q exit
        if(userChoice == 'q'){

            // Set repeat variable to 1 to break the loop.
            repeat = 1;

        } else {
            
            // Declare and initialize variable to store user's input.
            int index = 0;
            string value = "";
        
            switch(userChoice){
                
                // If user chooses s, ask for inputs and call class member function.
                case 's':{
                    cin >> index >> value;
                    if (SA.setVal(index,value) == false){
                        cout << "Unable to set index " << index << endl;
                    }
                    break;
                };
                
                // If user chooses g, ask for input and call class member function.
                case 'g':{
                    cin >> index;
                    if (SA.getVal(index) == "ERROR"){
                        cout << "Unable to get index " << index << endl;
                    } else {
                        cout << "Element " << index << " = " << SA.getVal(index) << endl;
                    }
                    break;
                }
            }

        }
    
    } while (repeat == 0);
    
    return 0;

}

// NON-MEMBER FUNCTION TO DISPLAY MENU TO USER
void userMenu(char& userChoiceF){

    do {
        
        // Output user menu options.
        cout << "s index value - Set a value in the array" << endl;
        cout << "g index - Get a value in the array" << endl;
        cout << "q - Quit" << endl;

        // Input choice from user.
        cin >> userChoiceF;
        
    } while (userChoiceF != 's' && userChoiceF != 'g' && userChoiceF != 'q' );

}

// NON-MEMBER FUNCTION TO INITIALIZE EMPTY ARRAY
SimpleArray initArr(){
    SimpleArray SA;
    for(unsigned int i=0;i<MAX_ARRAY_SIZE;i++){
        SA.setVal(i+1,"EMPTY");
    }
    return SA;
}

// CLASS MEMBER FUNCTIONS

// A public member function that returns a bool and takes an integer and a string.
// This member function will set the integer element to the corresponding string value.
// This member function returns true only if it was able to set an element in the array to the given value.
// The lower and upper bounds of the element index are checked to ensure it is within the array's bounds. 
bool SimpleArray::setVal(const unsigned int &index, const string &value){
    if (index < 1 || index > MAX_ARRAY_SIZE){
        return false;
    } else {
        myArray[index-1] = value;
    }
    return true;
}

// A public member function that returns a string and takes an integer.
// This member function will look up the given element and return it if it is within the bounds of the array.
// If the given integer is not within the boundaries of the private member array, return the string "ERROR".
string SimpleArray::getVal(const unsigned int &index) const {
    if (index < 1 || index > MAX_ARRAY_SIZE){
        return "ERROR";
    } else {
        return myArray[index-1];
    }
}