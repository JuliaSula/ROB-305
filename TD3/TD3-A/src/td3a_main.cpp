
#include "Chrono.h"
#include <iostream>
#include <unistd.h>

using namespace std;
int main()
{

	Chrono chrono;
	chrono.restart();
	sleep(10);
	cout << " [main] Time after 10 sec: " << chrono.lap()/1000<< endl;
	chrono.stop();
	sleep(1);
	cout << " [main] Time after 10+1 sec (chrono stopped): " << chrono.lap()/1000<< endl;
	chrono.restart();
	cout << " [main] Time after restart: " << chrono.lap()/1000<< endl;
	sleep(2);
	cout << "  [main] Time after 2 sec: " << chrono.lap()/1000<< endl; 
	//There is a little delay between the sleep value and the chrono lap due to the code execution
}
