#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void
sig_int (int signo)
{
  printf ("int\n");
}

void
sig_chld (int signo)
{
  printf ("chld\n");
}

int
main ()
{
  if (signal (SIGINT, sig_int) == SIG_ERR)
    {
      perror ("signal");
      return -1;
    }
  if (signal (SIGCHLD, sig_chld) == SIG_ERR)
    {
      perror ("signal");
      return -1;
    }
  if ((system ("/bin/ed")) < 0)
    {
      perror ("system");
      return -1;
    }
printf("hi\n");
  return 0;
}
