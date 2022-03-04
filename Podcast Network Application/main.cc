#include <iostream>
#include "Podcast.h"
#include "TestControl.h"

using namespace std;

//main function used to test code
int main()
{

	//TestControl object used to launch tester methods for code
	TestControl* control = new TestControl();

	//calling launch to test code.
	control->launch();

	//deleting object to prevent memory leaks.
	delete control;
	return 0;

}
