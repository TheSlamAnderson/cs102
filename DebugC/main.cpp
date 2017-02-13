//Debug C
//A program that calculates tax rates based on income
//Johnny A. Student

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double TAX_RATE_LOW = 0.10;
const double INCOME_LOW = 15000.0;

const double TAX_RATE_MED = 0.15;
const double INCOME_MED = 35000.0;

const double TAX_RATE_HI = 0.20;

int main()
{
	double income;
	//S: Something seems to be wrong here.
	//S: Whenever I calculate the tax, it seems to round it down or something
	//S: like that. What is happening?
	double tax;
	char run;

	//S: I'm wondering what I did here. For some reason, this loop sometimes
	//S: doesn't even run!
	//S: Perhaps there is a better loop to use here?
	//S: My thinking is that as long as the user keeps typing y (which goes into run)
	//S: then this loop should keep running, right?
	do {
		cout << "Enter your income for this year: ";
		cin >> income;
		cout << endl;

		//S: There is something seriously wrong here. It appears like the taxes
		//S: aren't applied correctly if my income is low. I end up paying the
		//S: medium rate. Why would that be?
		//S: The only one that works is if my income is high.
		//S: I heard the term "Mutual Exclusion" in class, perhaps I could
		//S: use that here?
		if (income <= INCOME_LOW) {
			tax = income * TAX_RATE_LOW;
		} else if (income <= INCOME_MED) {
			tax = income * TAX_RATE_MED;
		} else if (income > INCOME_MED) {
			tax = income * TAX_RATE_HI;
		}

		//S: I want this to output the normal "dollars" with 2 decimal points of precision
		//S: but for some reason this only outputs two total digits. What gives?
		//S: Do I need the tax * 1.0? This was the only way I could get it to print
		//S: any decimal at all....even though it is still wrong :(
		cout << "You owe $" << fixed << setprecision(2) << tax << " in taxes." << endl;
		cout << "Do you want to run another tax calculation? ";
		cin >> run;
		cout << endl << endl;

	} while (run == 'y');

	return 0;
}