#include "GiveFifo.h"
#include <iostream>
using namespace std;
GiveFifo::GiveFifo( unsigned int nProds, Fifo<int> *fifo) : nProds(nProds), fifo(fifo),  given(0)
{}

GiveFifo::~GiveFifo()
{}

void GiveFifo::run()
{
	for (unsigned int k = 0; k < nProds; ++k)
		{
				fifo->push(k);
				++given;
		}
}
	

unsigned int GiveFifo::getGiven()
{
	return given;
}
