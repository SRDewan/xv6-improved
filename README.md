# README

This project builds upon the [xv6 operating system](https://github.com/mit-pdos/xv6-public) developed by MIT.  

## How To Run:
1. git clone https://github.com/SRDewan/xv6-improved.git && cd xv6-improved
2. make clean
3. make SCHEDULER=<RR, FCFS, PBS, MLFQ>
4. make qemu

NOTE: If no argument given to second command, ie, if 2nd command simply run as "make" then by default RR scheduler is used.


## Additional Features
* System calls: 
	1. waitx - used in time
	2. procdetails - used in ps
	3. set_priority - used in setPriority
	4. push - used for updating concerned process queue when MLFQ scheduler used
	5. pop - used for updating concerned process queue when MLFQ scheduler used

* User commands:
   1. ```time <command>```
   - Prints the total run time of the command and the total time it spent waiting for a CPU.
   - Uses the ```waitx``` system call.
   - Example: ```time ls```

   2. ```ps```
   - Prints details of all processes in the system.
   - Uses the ```procdetails``` system call.

   3. ```setPriority <new_priority> <pid>```
   - For a priority based scheduler, sets the priority of the process with process id ```pid``` to ```new_priority```. 
   - Uses the ```set_priority``` system call.


* Scheduling Algorithms:<br />
NOTE: Performances mentioned are for 40 processes, 100 ticks IO time and CPU time with 10^6 loop constraint in the given benchmark program.
	1. RR(Round Robin) - default
	   wtime = 1645, rtime = 257
	2. FCFS(First Come First Serve)
	   wtime = 3870, rtime = 123
	3. PBS(Priority Based Scheduling) 
	   wtime = 1228, rtime = 164
	4. MLFQ(Multi Level Feedback Queue)(non-preemptive, ie, preemption only occurs when time slice of current process(based on process queue number) is used up)
	   wtime = 768, rtime = 120

NOTE: Ageing limit is set to 10 ticks in MLFQ, ie, queue promotion occurs when a process wait time reaches 10 ticks.

## Files changed:
1. Makefile
2. defs.h
3. proc.c
4. proc.h
5. syscall.c
6. syscall.h
7. sysproc.c
8. user.h
9. usys.S