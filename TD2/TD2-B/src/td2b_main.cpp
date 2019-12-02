#include <fstream>
#include <iostream>
#include "TimeSpec.h"
#include "SigHandler.h"
#include "ConsoCPU.h"
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol



using namespace std;

int main(int argc, char* argv[]) 
{

	int schedPolicy=0;	
 	if (argc < 4)	//Avoids segmentation faults, if the arguments 
								//needed by the program are not give
	{
		cout << "No arguments, needs argument nLoops, nTask and schedPolicy"<<endl;
		return 1;
	}
	/****************Variables initialization***********************************/
	unsigned int nLoops= stoul(argv[1]);
	unsigned int nTasks= stoul(argv[2]);
	std::string arg3(argv[3]);
	Data data={false, 0.0, nLoops};
	
	/****************Checks SchedPolicy chosen *********************************/
	if(arg3=="SCHED_RR")
		schedPolicy=1;
	else if(arg3=="SCHED_FIFO")
		schedPolicy=2;
	else if(arg3=="SCHED_OTHER")
		schedPolicy=0;
	else	
		cout<<"Error reading scheduler type"<<endl;	
			
				
	cout<<" [main] schedPolicy: " <<schedPolicy<<endl;
	cout<<" [main] nTasks: " <<nTasks<<endl;
	cout<<" [main] nLoops: " <<nLoops<<endl;
		
	/*****************Sets  sched Params****************************************/
	sched_param schedParam;
	schedParam.sched_priority = sched_get_priority_max(schedPolicy);
	pthread_setschedparam(pthread_self(), schedPolicy, &schedParam);

	pthread_attr_t attr;
	sched_param	schedParams;
	schedParams.sched_priority = (schedPolicy == SCHED_OTHER) ? 0 : 9;
	
	pthread_t incrementThread[nTasks];
	pthread_attr_init(&attr);
	pthread_attr_setschedpolicy(&attr, schedPolicy);
	pthread_attr_setschedparam(&attr, &schedParams);
	
	/****************************Deploys Tasks******************************/
	struct timespec timeStart_ts;
	struct timespec timeEnd_ts;
	clock_gettime(CLOCK_REALTIME, &timeStart_ts);

	for(unsigned int i=0; i<nTasks;i++)
	{
		pthread_create(&incrementThread[i], NULL, call_incr, &data);
		cout<<" [main] Thread "<<i<< " created \n"<<flush;
	}
	for(unsigned int i=0; i<nTasks;i++)
	{
		pthread_join(incrementThread[i], NULL); // Le main attend le thread pour finir.
		cout<<" [main] Thread "<<i<< " joined \n"<<flush;
	}
	clock_gettime(CLOCK_REALTIME, &timeEnd_ts);

	pthread_attr_destroy(&attr);
	std::cout<<"Counter value=  "<<data.counter<<"\n"<<std::flush;	
	
	

	double timeExec_s=timespec_to_ms(timespec_subtract(timeEnd_ts,timeStart_ts))/1000;
	
	/**Writes values into a file -used to obtained execution time easily******/
	ofstream myfile;
	myfile.open ("example.txt", ofstream::app);
	myfile << "nTasks: "<< nTasks<< " nLoops: "<< nLoops << " time: "<<timeExec_s<<"\n";
	myfile.close();
	cout<<"Time to run: "<<timeExec_s<<endl;
	return 0;
}
