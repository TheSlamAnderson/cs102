//COSC 102 - Debug A
//
//Stephen Marz
//1 Aug 2016


//S: How do I include iostream again?
#include <iostream>

//S: I know something goes here, but can't remember.
//S: I want to make sure std:: is implied rather than me
//S: typing it out all of the time.
//S: i.e., std::cout << std::endl  =>  cout << endl
using namespace std;


//S: Something doesn't work here either. I know it is int main
//S: but for some reason it won't compile.
int main()
{
	//S: I need three variables: volts, amps, and watts
	//S: but the compiler doesn't like how I did it.
	int volts, amps, watts;

	//S: Ok, something is wrong here. The compiler is complaining about
	//S: the "arrows" that I supplied here. >>, I want to cout "Enter volts: ", right?
	cout << "Enter volts: ";
	cin >> volts;

	//S: The cout works, but for some reason the cin doesn't. I want a new line after
	//S: the user makes their input, but the compiler doesn't like endl?
	cout << "Enter amps: ";
	cin >> amps;
    cout << endl;

	//S: I actually got this to work!
	watts = volts * amps;

	
	//S: This at least outputs, but for some reason all of the
	//S: words and numbers are put together:
	//S: 8volts and7amps =22watts.
	
	//S: What did I do wrong?
	cout << volts << " volts and " << amps << " amps = " << watts << " watts." << endl;

	//S: Why do I care about return 0. I know it goes here, but who cares, right??
	return 0;
}
