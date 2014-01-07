#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void
mytest (int signo)
{
  printf ("x\n");
}

int
main ()
{
  sigset_t set, oset;

  signal (SIGQUIT, mytest);
  sigemptyset (&set);
  sigemptyset (&oset);
  sigaddset (&set, SIGQUIT);
  if (sigprocmask (SIG_BLOCK, &set, &oset) == -1)
    {
      perror ("sigprocmask");
      return -1;
    }
  printf ("pid=%d\n", getpid ());
  sleep (10);
  sigemptyset (&set);
  if (!sigpending (&set))
    {
      if (sigismember (&set, SIGQUIT))
	{
	  printf ("sigquit\n");
	}
    }
  if (sigprocmask (SIG_SETMASK, &oset, NULL) == -1)
    {
      perror ("sigprocmask");
      return -1;
    }
  printf ("end\n");
  return 0;
}
