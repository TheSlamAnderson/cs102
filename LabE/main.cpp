// Lab E
// A password-generating program that will use the random number generator and a defined array to produce characters for the user.
// The user will supply how long they want their password, and then either accept or reject the passwords that the program generates. 
// Christopher M. Anderson
// 2016-09-21

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// DECLARE GLOBAL CONSTANTS FOR SIZE AND DEFINITION OF POSSIBLE CHARACTERS FOR PASSWORD
const int ARRSIZE = 10;
const char ARRPASS[ARRSIZE] = {'a', 'b', 'c', 'd', 'E', 'F', '!', '*', '6', '2'};


// PROTOTYPE FOR FUNCTION TO GET CHARACTER FROM RANDOM NUMBER
char getRandChar(); 

// BEGIN MAIN FUNCTION
int main(){
    
    // DECLARE AND INITIALIZE VARIABLES FOR SEED, PASSWORD LENGTH, AND PASSWORD ACCEPTANCE
    int seedNum = 0;
    int passLength = 0;
    char accPass = 'y';
    
    // REQUEST SEED NUMBER FROM USER
    cout << "Enter seed: ";
    cin >> seedNum;
    
    // SEED RANDOM NUMBER GENERATOR WITH INPUT FROM USER
    srand(seedNum);

    // REQUEST LENGTH OF PASSWORD FROM USER
    cout << "Enter password length: ";
    cin >> passLength;
        
    // ENSURE PASSWORD LENGTH IS MORE THAN 1 CHARACTER AND NOT MORE THAN 25 CHARACTERS
    if(passLength < 1){
        passLength = 1;
    } else if(passLength > 25){
        passLength = 25;
    }
    
    // BEGIN PASSWORD GENERATOR LOOP
    do{

        // DECLARE AND INITIALIZE PASSWORD STRING
        string passWord = "";
        
        // CREATE PASSWORD USING LENGTH OF PASSWORD AND GETTING RANDOM CHARACTERS FROM PASSWORD ARRAY
        for(int i=0;i<passLength;i++)
        {
            passWord += getRandChar();
        }
        
        // OUTPUT SELECTED PASSWORD
        cout << passWord << endl;
        
        // ASK USER IF THEY ACCEPT PASSWORD
        cout << "Accept password? ";
        cin >> accPass;

    } while(accPass != 'y' && accPass != 'Y');
    
    return 0;
}

// RANDOM CHARACTER FUNCTION
char getRandChar() {
    int randNum = rand() % (ARRSIZE);
    char randChar = ARRPASS[randNum];
    return randChar;
}