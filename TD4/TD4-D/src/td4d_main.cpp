#include <iostream>
#include "TakeFifo.h"
#include "GiveFifo.h"
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;



int main(int argc, char* argv[]) 
{
	unsigned int counter=0;
	unsigned int taken=0;
	unsigned int given=0;
	double execTimeGive=0;
	double execTimeTake=0;
	
 	timespec begin=timespec_now();
 	
	if (argc < 4)	//Avoids segmentation faults, if the arguments 
								//needed by the program are not give
	{
		cout << "No arguments, needs argument nCons, nProds, nTokens"<<endl;
		return 1;
	}

	unsigned int nCons=stoul(argv[1]);
	unsigned int nProds=stoul(argv[2]);
	unsigned int nTokens=stoul(argv[3]);	
	Fifo<int> fifo;
	Mutex mutex;

	vector<TakeFifo> takingFifos(nCons,TakeFifo(&fifo, &mutex));
	
	vector<GiveFifo> givingFifos(nProds, GiveFifo(nTokens, &fifo));
	
	
		
	for (auto &thread : givingFifos) 
	{
		thread.start(); 
	}

	for (auto &thread : takingFifos) 
	{

		thread.start(); 
	}
  
	for (auto &thread : givingFifos)
	{
			
			thread.join();	
			given+=thread.getGiven();		
			execTimeGive += thread.execTime_ms();
	}	

	for (auto &thread : takingFifos)
	{
			
			thread.join();
		    taken+=thread.getTaken();
			execTimeTake += thread.execTime_ms();
	}	
	
	 cout << "2"<<endl;
	counter=fifo.get_FifoSize();
	timespec end= timespec_now(); 
	cout<<" [main] Time to run (total time): "<<timespec_to_ms(timespec_subtract(end,begin))/1000<<endl;
	cout<<" [main] nCons: "<<nCons<< "\n [main] nProds: "<<nProds<< endl;
	cout<<" [main] nTokens: " << nTokens << "\n [main] taken: "<<taken<<"\n [main] given: "<<given<<endl;
	cout << " [main] Counter final value: " << counter <<"\n [main] Execution Time Give (ms): "
	<< execTimeGive << "\n [main] Execution Time Take (ms): "<<execTimeTake<<std::endl;
	return 0;
}
