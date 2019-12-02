#include "ConsoCPU.h"
#include "SigHandler.h"
#include "TimeSpec.h"
#include <limits.h>
#include <iostream>
using namespace std;
int main() {

	/***********Test Function Calib Precise**********/
	int nTest=5;
	long int time_s=3;
	line lineValue=calibPrecision(nTest);
	double error=get_error(lineValue, time_s);
	cout <<" [main] Error between estimated nLoops and nLoops after precision calibration "
		<< error<<"%"<< endl;
}
