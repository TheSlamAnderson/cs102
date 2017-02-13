//Debug E
//A program that implements functions
//Johnny A. Student

#include <iostream>
#include <iomanip>
#include <cstdlib>
//S: My compiler doesn't seem to be able to find the rand() function
//S: and I can't remember what to include for it

using namespace std;

int getNumber(int min, int max);
//S: My compiler is telling me that getNumber isn't defined, but
//S: I have it below!?

int main()
{
	char ans = 'n';
	int seed = 0;

	cout << "Enter seed: ";
	cin >> seed;

	srand(seed);

	do {
		int min, max = 0;
		cout << endl;
		cout << "Enter minimum: ";
		cin >> min;
		cout << "Enter maximum: ";
		cin >> max;

		cout << endl << endl;

		//S: The number printed below seems to always be the same and is
		//S: garbage!
		cout << "Random number = " << getNumber(min, max) << endl;
		cout << "New random number? ";
		cin >> ans;

		//S: This do/while loop never quits!
	} while (ans != 'n' && ans != 'N');

	return 0;
}

int getNumber(int min, int max)
{
	//S: This seems to return numbers that are too low by
	//S: exactly 1, what was the formula again?
	return min + (rand() % (max - min + 1));
}