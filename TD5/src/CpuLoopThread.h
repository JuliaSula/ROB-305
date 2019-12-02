/**@file CpuLoopThread.h
 * @brief Implements  threads which behavior can be defined
 */
#ifndef CPULOOPTHREAD_INCLUDED
#define CPULOOPTHREAD_INCLUDED

#include "Calibrator.h"
#include "CpuLoop.h"
#include "Thread.h"
#include "Mutex.h"

/**@brief CpuLoopThread class run a nLoops depending on the acess time
 * to object loop of each thread and its executing time can be chosen
 */
class CpuLoopThread: public Thread
{
private:

	/**@brief  CpuLoop object that allows to create concurrency access to a 
	 * same ressource*/
	CpuLoop *loop;
	
	/**@brief Mutex that'll allow different threads to 
	 * divide access Cpuloop object
	*/
	Mutex *m;
	
	/**@brief Thread priority
	 */
	int schedPriority;
	
	/**@brief Time the task should wait/execute before demanding acess to 
	 * the object Cpuloop
	 */
	int waitBefore_ms;
	
	/**@brief Time the task should wait/execute after demanding acess to 
	 * the object Cpuloop
	 */
	int waitAfter_ms;
	
	/**@brief Time the task will demand acess to object Cpuloop
	 */
	int tics;
	
	
public:

	/**@brief CpuLoopThread Constructor
	 * 
	 * @param *loop: pointer to cpuloop object
	 * @param schedPolicy: how the CPU should manage thread when he has access to it
	 * @param schedPriority: how important is the task being performed
	 * @param *m: Mutex that'll allow different threads to divide access Cpuloop object
	 * @param before_ms:Time the task should wait/execute before demanding to acquire Mutex
	 * @param after_ms:Time the task should wait/execute after demanding to acquire Mutex
	 * @param tics: Time the task should use/lock the mutex
	 */
	CpuLoopThread(CpuLoop *loop, int schedPolicy, int schedPriority, Mutex *m, int before_ms, int after_ms, int tics);
	
	/**@brief CpuLoopThread Destructor
	 */
	~CpuLoopThread();
	
	/**@brief Runs executing/waiting time, demands mutex access, runs executing/waiting time
	 */
	void run();

};

#endif
