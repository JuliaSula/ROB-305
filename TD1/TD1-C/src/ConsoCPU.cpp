
#include "ConsoCPU.h"
#include <iostream>
using namespace std;

void incr(unsigned int nLoops, double* pCounter)
{
	
	for(unsigned int i=0; i<nLoops; i++)
	{
		(*pCounter)++;
	}
}

