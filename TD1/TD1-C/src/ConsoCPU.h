/**@file ConsoCPU.h
 * @brief Implements function increment
 */

#ifndef ConsoCPU_h_INCLUDED
#define ConsoCPU_h_INCLUDED

/**@brief Increments a counter nLoops times
 * 
 * @param nLoop: number of timer the counter should be incremented
 * @param pCounter: pointer to the counter to be incremented
 */
void incr(unsigned int nLoops, double* pCounter);

#endif
