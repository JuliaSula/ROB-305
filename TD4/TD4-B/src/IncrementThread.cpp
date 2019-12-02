#include "IncrementThread.h"
#include <iostream>
using namespace std;
IncrementThread::IncrementThread(unsigned int nLoops, volatile double *counter, int schedPolicy, int schedPriority) :
	Thread(),nLoops(nLoops), counter(counter)
{
	bool t=setScheduling(schedPolicy, schedPriority);
	cout<<" [IncrementThred] BOOL"<<t<<endl;
}


void IncrementThread::run()
{
	for(unsigned int i=0; i<nLoops; i++)
	{
		cout<<"  [IncrementThred]Toi"<<endl;
		(*counter)++;
		cout<<" [IncrementThred]"<<counter<<endl;
	}
	
}

IncrementThread::~IncrementThread()
{
}
