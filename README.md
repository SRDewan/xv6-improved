How To Run:
	1. make clean
	2. make SCHEDULER=<RR, FCFS, PBS, MLFQ>
	3. make qemu

	NOTE: If no argument given to second command, ie, if 2nd command simply run as "make" then by default RR scheduler is used.

Extra commands:
	1. time - runs the argument given as a command and prints out the pid, wait time(all the time spent not running) and run time
	NOTE: wait and run times are in terms of number of ticks
	2. ps - print process details of all
	3. setPriority - sets priority of given process(pid given) to given priority(must be in range [0, 100]) irrespective of scheduling algorithm used
	4. benchmark - produces and runs various processes for performance testing

Extra systemcalls:
	1. waitx - used in time
	2. procdetails - used in ps
	3. set_priority - used in setPriority
	4. push - used for updating concerned process queue when MLFQ scheduler used
	5. pop - used for updating concerned process queue when MLFQ scheduler used

Scheduling Algorithms:
Performances mentioned are for 40 processes, 100 ticks IO time and CPU time with 10^6 loop constraint in the given benchmark program.
	1. RR - default
	   wtime = 1645, rtime = 257
	2. FCFS
	   wtime = 3870, rtime = 123
	3. PBS 
	   wtime = 1228, rtime = 164
	4. MLFQ(non-preemptive, ie, preemption only occurs when time slice of current process(based on process queue number) is used up) - The return of recently woken up processes back to the queue they were running in before going to sleep can be exploited by processes to avoid demotion to lower priority queues by simply switching back and forth between SLEEPING and RUNNING states
	   wtime = 768, rtime = 120

	NOTE: Ageing limit is set to 10 ticks in MLFQ, ie, queue promotion occurs when a process wait time reaches 10 ticks.

Files changed:
	1. Makefile
	2. defs.h
	3. proc.c
	4. proc.h
	5. syscall.c
	6. syscall.h
	7. sysproc.c
	8. user.h
	9. usys.S
