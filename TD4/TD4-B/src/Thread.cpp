
#include <iostream>
#include "TimeSpec.h"
#include "Thread.h"
#include <signal.h>
using namespace std;
Thread::Thread(): chrono(), started(false) {}

Thread::~Thread()
{
}

void Thread::start()
{
	PosixThread::start(callrun, this);
}

bool Thread::starts()
{
	if(!started)
	{
		started=true;
		PosixThread::start(callrun, this);
		return true;
	}
	else
	{
		return false;
	}
}

void *Thread::callrun(void* v_thread)
{

	Thread *thread= (Thread *) v_thread;
	thread->chrono.restart();
	thread->run();
	thread->chrono.stop();
	return nullptr;
	
}

	
void Thread::sleep_ms(double delay_ms)
{
	timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
	 return chrono.startTime();
}
double Thread::stopTime_ms()
{
	 return chrono.stopTime();
}


double Thread::execTime_ms()
{
	return stopTime_ms() - startTime_ms();
}
