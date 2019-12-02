/**@file TakeFifo.h
 * @brief Implements TakeFifo class
 */
#ifndef TAKEFIFO_INCLUDED
#define TAKEFIFO_INCLUDED
#include "Fifo.hpp"
#include "Thread.h"

/**@brief Class takes elements out of a fifo class
 */
class TakeFifo : public Thread
{

	private:
		
		/**@brief Pointer to fifo object
		 * from each elements will be taken
		 */
		Fifo<int> *fifo;
		
		/**@brief Mutex that'll allow different threads to 
		 * divide fifo access
		 */
		Mutex *m;
		
		/**@brief Number of elements taken
		 */
		unsigned int taken;

	public:
		
		/**@brief TakeFifo Constructor
		 * 
		 * @param *fifo: fifo object
		 * @param *m : mutex
		 */
		TakeFifo(Fifo<int> *fifo, Mutex *m);
		
		/**@brief TakeFifo Destructor
		 */
		~TakeFifo();

		/**@brief Takes elements out of fifo
		 */
		void run();

		/**@brief Returns number of elements popped
		 *
		 * @return taken
		 */
		int unsigned getTaken();
};

#endif
