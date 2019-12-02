#include <iostream>

#include "PosixThread.h"

#include "CpuLoopThread.h"

#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol
#include <vector>
#include <thread>
#include <string.h>
#include <stdio.h>

using namespace std;



int main() 
{
	
	
	Mutex mutex(true);	

 	timespec begin=timespec_now();
	
	
	

	//Policy and priority definition for each task
	int schedPolicy(SCHED_RR);
	
	int schedPriorityA=99;
	int schedPriorityB=40;
	int schedPriorityC=10;
	
	//Executing time for each task and locking time
	int ticsLockA=10000;
	int	ticsLockB=0;
	int ticsLockC=20000;
	
	int beforeExeA_ms=10000;
	int beforeExeB_ms=10000;
	int beforeExeC_ms=10000;
	
	int afterExeA_ms=0;
	int afterExeB_ms=0;
	int afterExeC_ms=20000;
	
	//Calibrator and CpuLoop Creation, CpuLoop will be the shared variable between threads(tasks)
	Calibrator calibrator(10000,10);
	CpuLoop loop(calibrator);
	CpuLoop loop1(calibrator);
		
	//Tasks Creation
	CpuLoopThread tacheA(&loop, schedPolicy, schedPriorityA, &mutex, beforeExeA_ms, afterExeA_ms,ticsLockA);
	CpuLoopThread tacheB(&loop, schedPolicy, schedPriorityB, &mutex, beforeExeB_ms, afterExeB_ms,ticsLockB);
	CpuLoopThread tacheC(&loop, schedPolicy, schedPriorityC, &mutex, beforeExeC_ms, afterExeC_ms,ticsLockC );
	
	//Definition of Activation time for task A and B
	//timespec wait_tspec=timespec_from_ms(200);
	
	//Tasks Activation
	tacheC.start();
	loop.runTime(30000);
	//timespec_wait(wait_tspec);
	cout<<" [main] start A and B"<<endl;
	tacheA.start();
	tacheB.start();
		
	//Task ends
	tacheC.join();
	tacheA.join();
	tacheB.join();
	

		
		
	timespec end= timespec_now(); 
	//cout<<" [main] Time to run: "<<timespec_to_ms(timespec_subtract(end,begin))/1000<<endl;
	//cout<<" [main] Time to run: "<<(timespec_to_ms(end)-timespec_to_ms(begin))/1000<<endl;
	
	cout<<" [main] Time to run (total time): "<<timespec_to_ms(timespec_subtract(end,begin))/1000<<endl;
	cout<<" [main] Task A execTime: "<<tacheA.execTime_ms()/1000<<endl;
	cout<<" [main] Task B execTime: "<<tacheB.execTime_ms()/1000<<endl;
	cout<<" [main] Task C execTime: "<<tacheC.execTime_ms()/1000<<endl;
	return 0;
}
