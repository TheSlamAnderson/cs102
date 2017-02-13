//Debug F
//A program that implements classes
//Johnny A. Student

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Generator
{
	int _high, _low;

    public:
	//I want to be able to use these from int main(),
	//but I get an error!!
	void generateNumber(int &num);
	void setLow(int low);
	void setHigh(int high);
};

int main()
{
	Generator gen;
	int rd;
	int low, high;

	cout << "Enter the low number: ";
	cin >> low;

	cout << endl;
	cout << "Enter the high number: ";
	cin >> high;

	srand(low + high);

	//All of these say that setLow and setHigh are not declared
	gen.setLow(low);
	gen.setHigh(high);

	cout << endl;
	cout << "How many numbers to generate? ";
	cin >> rd;

	cout << endl;
	for (int i = 0; i < rd; i++) {
		int k;
		//I can't get this to give me a number. k is by reference
		//so it should take the value, right? Why doesn't this print?
        gen.generateNumber(k);
		cout << k << endl;
	}

	return 0;
}

//setLow and setHigh don't seem to take the appropriate
//value.
void Generator::setLow(int low)
{
	_low = low;
}

void Generator::setHigh(int high)
{
	_high = high;
}

void Generator::generateNumber(int &num)
{
	num = _low + rand() % (_high - _low + 1);
}