#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    printf(2, "usage: time command args\n");
    exit();
  }
  int child = fork();
  if(child == -1)
	  exit();
  else if(!child)
  {
	  exec(argv[1], argv + 1);
	  exit();
  }
  else if(child > 0)
  {
	  int wtime = -1, rtime = -1;
	  int pid = waitx(&wtime, &rtime);
	  printf(1, "pid: %d, wait time: %d, run time: %d\n", pid, wtime, rtime);
  }
  exit();
}
