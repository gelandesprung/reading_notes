#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void
test (int signo)
{
  sigset_t set;
  printf ("x\n");
/*  sigpending (&set);
  if (!sigismember (&set, SIGQUIT))
    {
      printf ("yes\n");
    }
*/
}

int
main ()
{
  struct sigaction act, oact;
  sigemptyset (&act.sa_mask);
sigfillset(&act.sa_mask);
  sigaddset (&act.sa_mask, SIGQUIT);
  act.sa_handler = test;
  if (sigaction (SIGQUIT, &act, &oact) == -1)
    {
      perror ("sigaction");
    }

  for (;;)
    pause ();
  return 0;
}
