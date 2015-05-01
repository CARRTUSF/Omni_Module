
#include <iostream>
#include <string>
#include "omni_lib.h"

using namespace std;
using namespace WMRA;

int main()
{
	omni o;

	// Omni Initialization check
	cout << "Checking if Omni is initialized..." << endl;
	if(o.isInitialized())
		cout << "\t...Omni is initialized\n" << endl;
	else
		cout << "\t...Omni is NOT initialized\n" << endl;
	

	// Button 1 check
	cout << "Waiting for button 1 to be pressed..." << endl;
	while(!o.checkButton1()) {}
	cout << "\t...Button 1 pressed\n" << endl;

/*
	// Button 2 check
	cout << "Waiting for button 2 to be pressed..." << endl;
	while(!o.checkButton2()) {}
	cout << "\t...Button 2 pressed\n" << endl;
	
	
	// Force to origin choice
	cout << "Force to origin position? 1=yes 0=no" << endl;
	int choice;
	cin >> choice;
	if(choice == 1)
	{
		o.forceToOrigin();
		cout << "\t...Omni forced to origin position\n" << endl;
	}
	else
	{
		o.setForceFeedback(0.0,0.0,0.0);
		cout << "\t...Omni NOT forced to origin\n" << endl;
		cout << "\t...Omni X,Y,Z forces set to zero" << endl;
	}

	// Force Magnitude
	double mag = 0.1;
	while(mag != 0.0)
	{
		cout << "What force magnitude would you like to use? (Default: 0.1)" <<  endl;
		cin >> mag;
		o.setForceFeedback(mag);
	}
*/
	o.forceToOrigin();
	vector<double> p;
	int count = 0;
	while(count < 2000)
	{
		count++;
		p = o.getPositionData();
		std::cout << "Omni Position: [ " << p[0] << ", " << p[1] << ", " << p[2] << " ]" << std::endl;
	}
	return 1;
}