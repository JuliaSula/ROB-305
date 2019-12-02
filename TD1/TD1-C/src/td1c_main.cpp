#include "ConsoCPU.h"
#include "TimeSpec.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	/**The counter value will only be correct if
	* the nLoops value is smaller or equal to uint max (4294967295)
	*/
	
	
    double		 counter(0);
	struct timespec timeStart_ts;
	struct timespec timeEnd_ts;

	if (argc == 1)
	{
		cerr << "No arguments, needs argument nLoops";
		return 1;
	}

	unsigned int nLoops = stoul(argv[1]);
	clock_gettime(CLOCK_REALTIME, &timeStart_ts);
	incr(nLoops, &counter);
	clock_gettime(CLOCK_REALTIME, &timeEnd_ts);

	
	cout << "Execution time: "
			  << -timespec_to_ms(timeStart_ts)+timespec_to_ms(timeEnd_ts) << 1000 << endl;

	cout << "Execution time (ms) : "
			  << timespec_to_ms(timeEnd_ts-timeStart_ts) << endl;
	cout << "Counter Final Value: "<< counter << endl;

	
	return 0;
}
