// =================================================================================================
// NAME:            Lab J
// AUTHOR:          Christopher M. Anderson
// DATE:            2016-11-18
// PURPOSE:
// This program will read a file called a portable pixel map (PPM). A portable pixel map is a color 
// picture that has a text format, making it easy to use input file streams to read from. The 
// program will read from this file, making a series of adjustments, and then outputting the
// transformed picture to an output file.
// =================================================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


// PIXEL STRUCTURE =================================================================================
// A structure that stores information about a pixel.

struct Pixel {

    // ***** DECLARATIONS ************************

    // Three public integers: red, green, and blue
    int _red;
    int _green;
    int _blue;

    // ***** CONSTRUCTOR PROTOTYPES **************

    // A public 3-argument constructor that takes three integers: red, green, and blue. This
    // constructor will set the red, green, and blue member variables to the red, green, and blue 
    // parameters.
    Pixel(int r, int g, int b);

    // A public 0-argument constructor. This constructor will call the 3-argument constructor and 
    // pass 0 for red, green, and blue.
    Pixel();

};


// PICTURE CLASS ===================================================================================
// A class that stores pixel information in a "vector of vectors."

class Picture {

    // ***** DECLARATIONS ************************

    // A private vector of vector of pixels
    vector<vector<Pixel>> picture_data;
    
    // Three integers for size and intensity
    int width = 0;
    int height = 0;
    int intensity = 0;

public:

    // ***** PUBLIC MEMBER FUNCTION PROTOTYPES ***

    // A public function that takes an input file stream and reads a given PPM file into the private
    // vector. This function will return true if the file was able to be fully read, or false
    // otherwise.
    bool input_ppm(ifstream &fin);

    // A public function that takes an output file stream and writes to a PPM file. This function 
    // will return false if the number of rows to write is 0, or true otherwise.
    bool output_ppm(ofstream &fout);

    // A public function that flips the PPM vector around the Y axis. The resulting PPM file will be 
    // "backwards."
    void y_flip_ppm();

    // A public function that flips the PPM vector around the X axis. The resulting PPM file will be
    // "upside-down."
    void x_flip_ppm();

    // A public function that inverts the intensity of each R, G, and B values in the vector. This 
    // is essentially the maximum intensity minus the given intensity for R, G, and B.
    void invert_ppm();

};



// MAIN FUNCTION ===================================================================================

int main(int argc, char *argv[]) {

    // ***** DECLARATIONS ************************

    // Declare new Picture class instance
    Picture pic;

    // Declare char for user option
    char userCommand = 'N';

    // ***** ERROR CHECK COMMAND LINE ARGUMENTS **

    // If the user doesn't specify enough arguments output error message and return an error code:
    // Note: there could be either 2 or 3 user supplied command line arguments.
    if (argc < 3 || argc > 4){
        cout << "Usage: inputfile outputfile [XYI]" << endl;
        return 1;
    }

    // If the user specifies a third command argument, but it is not an X, Y, or I, output error 
    // message (replace Z with whatever command the user specified), and return an error code: 
    if (argc == 4) {
        userCommand = *argv[3];        

        if (userCommand != 'X' && userCommand != 'Y' && userCommand != 'I'){
            cout << "Error: " << userCommand << " is an invalid command. Use either X, Y, or I" << endl;
            return 2;
        }
    }

    // ***** INPUT FILE **************************

    // If the result of reading the input file is false (either the file could not be opened or is 
    // not valid), output error message, and return an error code:

    // Initialize ifstream
    ifstream fin;

    // Open input file
	fin.open(argv[1]);

    // Check if input file can be opened
	if (fin.fail()) {
        cout << "Error: unable to read PPM file " << argv[1] << endl;
        return 3;
    }

    // Call function to read PPM file to class
    pic.input_ppm(fin);

    // Close input file
    fin.close();

    // ***** CLASS MANIPULATION ******************

    // Call function to manipulate Picture class based on user command
    switch(userCommand){
        case 'X':{
            pic.x_flip_ppm();
            break;
        }
        case 'Y':{
            pic.y_flip_ppm();
            break;
        }
        case 'I':{
            pic.invert_ppm();
        }
    }

    // ***** OUTPUT FILE *************************

    // If the output file could not be opened for writing, output error message, and return an 
    // error code:

    // Initialize ofstream
    ofstream fout;

    // Open output file
    fout.open(argv[2]);

    // Check if input file can be opened
	if (fout.fail()) {
        cout << "Error: unable to write PPM file " << argv[2] << endl;
        return 4;
    }    

    // Call function to output PPM file
    if(pic.output_ppm(fout) == false){
        cout << "Error: tried to output an uninitialized PPM picture" << endl;
    }

    // Close output file
    fout.close();

    // ***** END MAIN ****************************
    return 0;

}



// DEFINE PIXEL (STRUCT) MEMBER FUNCTIONS ==========================================================

// A public 3-argument constructor that takes three integers: red, green, and blue. This
// constructor will set the red, green, and blue member variables to the red, green, and blue 
// parameters.
Pixel::Pixel(int r, int g, int b){
    _red = r;
    _green = g;
    _blue = b;
}

// A public 0-argument constructor. This constructor will call the 3-argument constructor and 
// pass 0 for red, green, and blue.
Pixel::Pixel(){
    Pixel(0,0,0);
}


// DEFINE PICTURE (CLASS) MEMBER FUNCTIONS =========================================================


// A public function that takes an input file stream and reads a given PPM file into the private
// vector. This function will return true if the file was able to be fully read, or false
// otherwise.
bool Picture::input_ppm(ifstream &fin){
    
    // Declare string for Magic Number
    string mn;

    // Declare integers for R,G,B values
    int r,g,b;
    
    // Get Magic Number
    fin >> mn;
    
    // Ensure Magic Number is P3
    if(mn == "P3"){
        
        // Get width, height, and intensity
        fin >> width >> height;
        fin >> intensity;

        // Set outside vector to size of height
        picture_data.resize(height);

        // Loop through rows
        for(int i=0;i<height;i++){

            // Set inside vector to size of width
            picture_data[i].resize(width);

            // Loop through columns
            for(int j=0;j<width;j++){

                // Get R,G,B data for given location
                fin >> r >> g >> b;

                // Set vector location to given pixel data
                picture_data[i][j] = Pixel(r,g,b);
            }
        }

        // Return true if the file was able to be fully read
        return true;

    } else {

        // Return false if the file was not able to be fully read
        return false;

    }
}

// A public function that takes an output file stream and writes to a PPM file. This function 
// will return false if the number of rows to write is 0, or true otherwise.
bool Picture::output_ppm(ofstream &fout){

    if(height == 0){

        // Return false if the number of rows to write is 0
        return false;

    } else {

        // Output 'P3' Magic Number
        fout << "P3" << endl;

        // Output width, height, and intensity
        fout << width << " " << height << endl;
        fout << intensity << endl;

        // Loop through rows
        for(int i=0;i<height;i++){

            // Loop through columns
            for(int j=0;j<width;j++){

                // Output R,G,B data for given location
                fout << picture_data[i][j]._red << " " << picture_data[i][j]._green << " " << picture_data[i][j]._blue << endl;
            }
        }

        // Return true if the number of rows to write is not 0
        return true;

    }
}

// A public function that flips the PPM vector around the Y axis. The resulting PPM file will be 
// "backwards."
void Picture::y_flip_ppm(){

    // Declare temporary Pixel
    Pixel tmp;

    // Loop through rows
    for(int i=0;i<height;i++) {

        // Loop through columsn divided in half
        for(int j=0;j<width/2;j++) {

            // Set temporary pixel to current location pixel data
            tmp = picture_data[i][j];

            // Set current location pixel to corresponding Y axis pixel data
            picture_data[i][j] = picture_data[i][width - 1 - j];

            // Set corresponding Y axis pixel to temporary pixel data
            picture_data[i][width - 1 - j] = tmp;
        }
    }

}

// A public function that flips the PPM vector around the X axis. The resulting PPM file will be
// "upside-down."
void Picture::x_flip_ppm(){

    // Declare temporary Pixel
    Pixel tmp;

    // Loop through rows divided in half
    for(int i=0;i<height/2;i++) {

        // Loop through rows
        for(int j=0;j<width;j++) {

            // Set temporary pixel to current location pixel data
            tmp = picture_data[i][j];

            // Set current location pixel to corresponding X axis pixel data
            picture_data[i][j] = picture_data[height - 1 - i][j];

            // Set corresponding X axis pixel to temporary pixel data
            picture_data[height - 1 - i][j] = tmp;

        }
    }

}

// A public function that inverts the intensity of each R, G, and B values in the vector. This 
// is essentially the maximum intensity minus the given intensity for R, G, and B.
void Picture::invert_ppm(){

    // Declare integers for R,G,B values
    int r,g,b;

    // Loop through rows
    for(int i=0;i<height;i++){

        // Loop through columns
        for(int j=0;j<width;j++){

            // Set R,G,B values to maximum intensity minus the given intensity
            r = intensity - picture_data[i][j]._red;
            g = intensity - picture_data[i][j]._green;
            b = intensity - picture_data[i][j]._blue;

            // Set vector location to given pixel data
            picture_data[i][j] = Pixel(r,g,b);

        }
    }
}



// =================================================================================================
// END OF PROGRAM