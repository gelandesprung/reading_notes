#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int
main ()
{
  sigset_t set;
  sigemptyset (&set);
  sigaddset (&set, SIGUSR1);
  if (sigprocmask (SIG_SETMASK, &set, NULL) == -1)
    {
      perror ("sigprocmask 1");
      return -1;
    }
  if (sigprocmask (0, NULL, &set) == -1)
    {
      perror ("sigprocmask");
      return -1;
    }
  if (sigismember (&set, SIGINT))
    {
      printf ("sigint\n");
    }
  if (sigismember (&set, SIGQUIT))
    {
      printf ("sigquit\n");
    }
  if (sigismember (&set, SIGUSR1))
    {
      printf ("sigusr1\n");
    }
  if (sigismember (&set, SIGALRM))
    {
      printf ("sigalrm\n");
    }
  return 0;
}
