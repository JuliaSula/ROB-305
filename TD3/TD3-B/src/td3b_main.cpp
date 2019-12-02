
#include "CountDown.h"
#include <iostream>
#include <unistd.h>
using namespace std;
int main(int argc, char* argv[]) 
{	
	if (argc < 2)	//Avoids segmentation faults, if the arguments 
								//needed by the program are not give
	{
		cout << "No arguments, needs argument n"<<endl;
		return 1;
	}
	unsigned int n= stoul(argv[1]);
	double frequency=1;
	double timeInterval_ms= 1/frequency*1000;
	Countdown countdown(n);
		
	countdown.start(timeInterval_ms);
		
	cout << " [main] CountDown Start" << endl;
	while (countdown.counter > 0)
	{

	}

	cout << " [main] CountDown Stop" << endl;

	return 0;
}
