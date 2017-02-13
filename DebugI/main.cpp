#include <iostream>
#include <fstream>
#include <string>
//S: I don't remember what to include for a string stream, but I keep getting
//S: an error!
#include <sstream>

using namespace std;

int main()
{
	string input_file;
	string line;
	istringstream sin;
	ifstream fin;

	int i, j, k;

	cout << "Enter input filename: ";
	cin >> input_file;
	cout << endl;

	fin.open(input_file);
	if (fin.fail()) {
		cout << "Unable to open input file.\n";
		return -1;
	}

	while (getline(fin, line)) {
		//S: For some reason, sin gives me the first line with no problems, afterward
		//S: I don't get any more information!
        sin.clear();
		sin.str(line);
        
		//S: Fields A, B, C are all optional, so I only print out those fields that
		//S: exist in the line, however when I do sin >> i >> j >> k, how do I differentiate those
		//S: fields that got data and those that did not.
		if (sin >> i) {
			cout << "Field A = " << i;
			if (sin >> j) {
				cout << ", Field B = " << j;
				if (sin >> k) {
					cout << ", Field C = " << k;
				}
			}
			cout << endl;
		}
	}

	return 0;
}