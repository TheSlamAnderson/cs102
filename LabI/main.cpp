// =================================================================================================
// NAME:            Lab I
// AUTHOR:          Christopher M. Anderson
// DATE:            2016-10-28
// PURPOSE:
// This program will input a set of students and their scores from a file. Then, the program will 
// generate a report to a file summarizing the average score for each of the students. The list of 
// students is in reverse order. So, the program will read in the entire student report into an
// array (up to a maximum of 10 students), reverse the array, and then generate the report.
// =================================================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


// CONSTANTS =======================================================================================

// Constant that stores the maximum number of elements in the Student structures array (10)
const int MAX_STUDENTS = 10;


// STUDENT STRUCTURE (CLASS) =======================================================================

struct Student{

    string _FirstName;
    string _LastName;
    double _AvgScore;

};


// PROTOTYPE NON-MEMBER FUNCTIONS ==================================================================

// ***** Reading Input Function ******************
// This function will read the input file stream parameter into the Student structures array. The 
// function will read the input file line-by-line and break apart the fields using a string stream.
// The function does not know how many students will be input so will count and not to go past the 
// capacity of the array.

int FuncRead(ifstream& inFile, Student studentList[]);

// ***** Reversing Array Function ****************
// This function will reverse the Student structures in the array so that the very first student
// will be the very last student, the second student will be the second to last student, and so
// forth.

void FuncRev(Student studentList[], int numRec);

// ***** Printing Student Report Function ********
// This function will output a report using the output file stream object and the reversed array of 
// student structures using the following format:
// LastName, FirstName               =  XXX.YY
// The LastName, FirstName will be in a left-justfied field of 20 characters. The XXX.YY represents 
// the calculated average scores and will be in fixed-decimal notation, precise to 2 decimal places.

void FuncPrint(ofstream& outFile, Student studentList[], int numRec);


// MAIN FUNCTION ===================================================================================

int main(){

    // ***** DECLARATIONS ************************

    // Declare file name variables
    string inFile, outFile;
    
    // Declare number of records variable
    int numRec = 0;
    
    // Declare empty array of students with given constant size
    Student studentList[MAX_STUDENTS];


    // ***** USER INPUT **************************

    // Request name of input file
    cout << "Enter input filename: ";
    cin >> inFile;

    // Request name of output file
    cout << "Enter output filename: ";
    cin >> outFile;


    // ***** INPUT FILE **************************

    // Initialize ifstream
    ifstream fin;

    // Open input file
    fin.open(inFile);
    if(fin.fail()){

        // Display error message and close if unable to open
        cout << "Unable to open input file.\n";
        return -1;

    } else {

        // Call function to read file, input records into array, and return number of records
        numRec = FuncRead(fin,studentList);

        // Call function to read array of students and reverse the order
        FuncRev(studentList,numRec);

    }

    // Close input file
    fin.close();


    // ***** OUTPUT FILE *************************

    // Initialize ofstream
    ofstream fout;

    // Open output file
    fout.open(outFile);

    // Call function to print student report to output file
    FuncPrint(fout,studentList,numRec);

    // Close output file
    fout.close();


    // ***** END MAIN ****************************
    return 0;

}


// DEFINE NON-MEMBER FUNCTIONS =====================================================================

// ***** Reading Input Function ******************
int FuncRead(ifstream& inFile, Student studentList[]){
    
    // ***** DECLARATIONS **********************
    Student tempStudent;
    string studentRecord;
    int recCount= 0;
    
    // Read in file line by line, as long as number of records are less than maximum allowed
    while(getline(inFile,studentRecord) && recCount < MAX_STUDENTS){

        // Ensure any blank lines are skipped
        if(studentRecord != "" && studentRecord != " "){

            // ***** DECLARATIONS **********************
            int numScores = 0;
            double indScore = 0.0;
            double totScores = 0.0;
            double avgScore = 0.0;

            // Initialize string stream
            istringstream sin;

            // Clear string stream
            sin.clear();

            // Set string stream
            sin.str(studentRecord);

            // Set given record first name equal to first entry in line
            sin >> tempStudent._FirstName;
            
            // Set given record last name equal to second entry in line
            sin >> tempStudent._LastName;

            // Loop through remaining data in line
            while(sin >> indScore){

                // Increment total number of scores
                numScores++;

                // Add individual score to total score
                totScores += indScore;
            }
            
            // Calculate average scores
            if(numScores != 0){
                avgScore = totScores / numScores;
            } else {
                avgScore = 0.0;
            }
            
            // Set given record average score equal to above calculation
            tempStudent._AvgScore = avgScore;
            

            // Copy the temporary student structure onto the student structures array
            studentList[recCount] = tempStudent;
    
            // Increment total number of records
            recCount++;

        }
    }

    // Return total number of records
    return recCount;

}


// ***** Reversing Array Function ****************
void FuncRev(Student studentList[], int numRec){
    
    // Loop through number of students
    for(int i=0;i<numRec/2;i++){
        
        // ***** DECLARATIONS **********************
        
        // Declare temporary struct
        Student temp;
        
        // Set temporary struct equal to current record
        temp = studentList[i];
        
        // Set current record equal to desired record
        studentList[i] = studentList[numRec - i -1];
        
        // Set that record equal to temporary record
        studentList[numRec - i -1] = temp;
    }
}


// ***** Printing Student Report Function ********
void FuncPrint(ofstream& outFile, Student studentList[], int numRec){
    
    // If no records, output error, otherwise, output formatted entry
    if(numRec == 0){

        outFile << "No students to report.\n";

    } else {

        // Loop through records
        for(int i=0;i<numRec;i++){

            // Initialize output stream to formate first and last name
            ostringstream outName;
            outName << studentList[i]._LastName << ", " << studentList[i]._FirstName;

            // Output formatted name to file
            outFile << fixed << left << setw(20) << outName.str();
            
            // Output formatted score to file
            outFile << " = " << setprecision(2) << studentList[i]._AvgScore << endl;
        }
    }
}


// =================================================================================================
// END OF PROGRAM