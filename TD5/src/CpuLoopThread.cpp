#include "CpuLoopThread.h"
#include <iostream>
using namespace std;
CpuLoopThread::CpuLoopThread( CpuLoop *loop_, int schedPolicy, int schedPriority, Mutex *m, int waitBefore_ms,int waitAfter_ms, int tics ): 
 loop(loop_), m(m), schedPriority(schedPriority), waitBefore_ms(waitBefore_ms),waitAfter_ms(waitAfter_ms),  tics(tics)
{
	setScheduling(schedPolicy, schedPriority);

}

CpuLoopThread::~CpuLoopThread()
{}


void CpuLoopThread::run()
{
	//Execution time before locking R (loop)
	timespec wait_tspec=timespec_from_ms(waitBefore_ms);
	
	cout<<" [cpuLoopThread] executing "<< schedPriority <<endl;
	timespec_wait(wait_tspec);
	
	//Locking R (loop)
	//cout<<" [cpuLoopThread] Lock "<< schedPriority <<endl;
	Mutex::Lock Lock(*m, schedPriority);
	loop->runTime(tics);
	std::cout << " [cpuLoopThread] Unlock " << schedPriority<<std::endl;
	Lock.~Lock();
	
		
	//Execution time after unlocking R (loop)
	wait_tspec=timespec_from_ms(waitAfter_ms);
	cout<<" [cpuLoopThread] executing "<< schedPriority <<endl;
	timespec_wait(wait_tspec);
	
	std::cout << " [cpuLoopThread] Done: Task " << schedPriority <<std::endl;
}

