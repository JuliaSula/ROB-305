#include "TimeSpec.h"
#include <iostream>
using namespace std;
int main() {
	struct timespec timeNow;
    struct timespec time_ts;
    struct timespec timeNot;
    double time_ms;
	
	
	timeNow=timespec_now();
	cout<<" [main] Time now: "<< "sec "<<timeNow.tv_sec 
		<<" nsec " << timeNow.tv_nsec<<endl;
	
	time_ms=timespec_to_ms(timeNow);
	cout<<" [main] Time now in ms: "<<time_ms<<endl;
	
	time_ts=timespec_from_ms(time_ms);
	cout<<" [main] Time now: "<< "sec "<<time_ts.tv_sec 
		<<" nsec " << time_ts.tv_nsec<<endl;

	timeNot=timespec_negate(time_ts);
	cout<<" [main] Time now negated: "<< "sec "<<timeNot.tv_sec 
		<<" nsec " << timeNot.tv_nsec<<endl;
     

	struct timespec time1_ts;
	time1_ts.tv_sec=9;		
	time1_ts.tv_nsec=3.e8;
	struct timespec time2_ts;
	time2_ts.tv_sec=5;		
	time2_ts.tv_nsec=7.e8;
	
	cout<<" [main] Time 1: "<< "sec "<<time1_ts.tv_sec 
		<<" nsec " << time1_ts.tv_nsec<<endl;
	cout<<" [main] Time 2: "<< "sec "<<time2_ts.tv_sec 
		<<" nsec " << time2_ts.tv_nsec<<endl;
	
	struct timespec timeAdded;
	timeAdded=time1_ts+time2_ts;
	cout<<" [main] Time Added: "<< "sec "<<timeAdded.tv_sec 
		<<" nsec " << timeAdded.tv_nsec<<endl;

	struct timespec timeSubtracted;
	timeSubtracted=time1_ts-time2_ts;
	cout<<" [main] Time Subtracted: "<< " sec "<<timeSubtracted.tv_sec 
		<< " nsec " << timeSubtracted.tv_nsec<<endl;
	
	time2_ts=-time2_ts;
	cout<<" [main] Time2 negated: "<< "sec "<<time2_ts.tv_sec 
		<<" nsec " << time2_ts.tv_nsec<<endl;
	timespec_wait(timeAdded);
	
	//timer prototype based in timespec
	timer(0.5);

}
