// Lab H
// The purpose of this program is to multiply a matrix (a 2 dimensional array) by a vector (a one dimensional array).
// Each of the arrays will be implemented in the program using a class.
// The program will be reading two separate files: one containing a vector and the other containing a matrix.
// The program will then multiply the vector and matrix together and write the resulting vector to a file. 
// Christopher M. Anderson
// 2016-10-19

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// DECLARE AND INITIALIZE CONSTANTS FOR VECTOR AND MATRIX SIZES
const int VECTOR_SIZE = 4; // (0: x, 1: y, 2: z, and 3: w)
const int MATRIX_ROWS = 4;
const int MATRIX_COLS = 4;

// PROTOTYPE FOR VECTOR CLASS
class Vector {

    double v[VECTOR_SIZE];

public:

    // Set will set the index of the array to the given value
    void Set(int index, double value);

    // Get will return the value of the array at the given index
    double Get(int index) const;

};

// PROTOTYPE FOR MATRIX CLASS
class Matrix {

   double m[MATRIX_ROWS][MATRIX_COLS];

public:

    // Set will set the row, col of the matrix to the given value
   void Set(int row, int col, double value);

    // Get will get the value of the matrix at the given row and column
   double Get(int row, int col) const;

};

// PROTOTYPE FOR NON MEMBER FUNCTION 

// This function will perform the multiplication and return a brand new Vector with the result. 
Vector Multiply(const Matrix &m, const Vector &v);



// BEGIN MAIN FUNCTION
int main(){

    // Declare vector and matrix instances
    Vector vin;
    Matrix min;
    
    // Declare file name variables
    string vfile,mfile,ofile = "test";
    
    // Initialize ifstream
    ifstream vfin;
    ifstream mfin;
    
    // Request name of vector input file
    cout << "Enter vector filename: ";
    cin >> vfile;

    // Request name of matrix input file
    cout << "Enter matrix filename: ";
    cin >> mfile;

    // Request name for output file
    cout << "Enter result filename: ";
    cin >> ofile;
    
    // Print blank line
    cout << endl;
    
    // Open vector file
    vfin.open(vfile);
    if(vfin.fail()){
        
        // Display error message and close if unable to open
        cout << "Unable to open vector file.";
        return -10;
    } else {

        // Declare variables for column number and value
        int col;
        double value;
        
        // Loop through vector file
        for(col=0;col<VECTOR_SIZE;col++){
            if(!(vfin>>value)){
                
                // Display error message and close if unable to read
                cout << "Unable to read vector file.";
                return -11;
            }
            
            // Set vin vector values to values from file
            vin.Set(col,value);
        }

    }
    
    // Close vector file
    vfin.close();

    // Open matrix file
    mfin.open(mfile);
    if(mfin.fail()){
        
        // Display error message and close if unable to open
        cout << "Unable to open matrix file.";
        return -20;
    } else {



        // Loop through matrix file rows
        for (int row=0;row<MATRIX_ROWS;row++){
            
            // Declare variables for row and column numbers and value
            double value = 0.0;
            
            // Loop through matrix file columns
            for(int col=0;col<MATRIX_COLS;col++){
                if(!(mfin>>value)){
                    
                    // Display error message and close if unable to read
                    cout << "Unable to read matrix file.";
                    return -21;
                }
                
                // Set min matrix values to values from file
                min.Set(row,col,value);
            }
        }

    }
    
    // Close matrix file
    mfin.close();
    
    // Declare New Vector And Perform Calculations
    Vector VNew = Multiply(min,vin);
    
    // Initialize ofstream
    ofstream fout;
    
    // Open output file
    fout.open(ofile);
    
    // Write result to file
    for(int i=0;i<VECTOR_SIZE;i++){
        fout << fixed << left << setprecision(1) << setw(6) << VNew.Get(i) << " ";
    }
    
    // Close output file
    fout.close();

    // Return and End Program
    return 0;
}



// VECTOR CLASS MEMBER FUNCTIONS

// Set will set the index of the array to the given value
void Vector::Set(int index, double value){
    v[index] = value;
}

// Get will return the value of the array at the given index
double Vector::Get(int index) const {
    return v[index];
}


// MATRIX CLASS MEMBER FUNCTIONS

// Set will set the row, col of the matrix to the given value
void Matrix::Set(int row, int col, double value){
    m[row][col] = value;
}

// Get will get the value of the matrix at the given row and column
double Matrix::Get(int row, int col) const {
    return m[row][col];
}


// NON MEMBER FUNCTION 

// This function will perform the multiplication and return a brand new Vector with the result. 
Vector Multiply(const Matrix &m, const Vector &v){
    
    // Declare New Vector
    Vector VNew;

    // Multiple Given Matrix By Given Vector
    for(int mrow=0;mrow<MATRIX_ROWS;mrow++){
        double vresult = 0.0;
        for(int mcol=0;mcol<MATRIX_COLS;mcol++){
            vresult += m.Get(mrow,mcol) * v.Get(mcol);
        }
        VNew.Set(mrow,vresult);
    }

    // Return New Vector
    return VNew;

}