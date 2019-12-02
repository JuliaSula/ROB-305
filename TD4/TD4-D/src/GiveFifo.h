/**@file GiveFifo.h
 * @brief Implements GiveFifo class
 */

#ifndef GIVEFIFO_INCLUDED
#define GIVEFIFO_INCLUDED

#include "Fifo.hpp"
#include "Thread.h"
/**@brief Class pushes elements in a fifo class
 */
class GiveFifo : public Thread
{

	private:
		/**@brief Number of elements to be pushed in
		 */
		unsigned int nProds;
		
		/**@brief Pointer to fifo object
		 * from each elements will be given
		 */
		Fifo<int> *fifo;
		
		
		/**@brief Number of elements given
		 */
		unsigned int given;		

	public:
	
		/**@brief GiveFifo Constructor
		 * 
		 * @param nProds: number of elements to be given
		 * @param *fifo: fifo object
		 * @param *m : mutex
		 */
		GiveFifo( unsigned int nProds, Fifo<int> *fifo);
		
		/**@brief GiveFifo Destructor
		 */
		~GiveFifo();
		
		/**@brief Pushes elementsinto fifo
		 */
		void run();
		
		/**@brief Returns number of elements pushed
		 *
		 * @return given
		 */
		int unsigned getGiven();
};

#endif
