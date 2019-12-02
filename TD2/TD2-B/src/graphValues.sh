#bash 

for nLoops in 10000000 20000000 30000000 40000000 
do	
	for nTasks in 1 2 3 4 5 6
	do
			./a.out $nLoops $nTasks SCHED_RR	
	done
done
