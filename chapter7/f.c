#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<setjmp.h>


static sigjmp_buf jmpbuf;
void
handler (int signo)
{
  printf ("handler\n");
}

void
squit (int signo)
{
  printf ("squit\n");
  siglongjmp (jmpbuf, 1);
}

int
main ()
{
  sigset_t set;
  printf ("pid=%d\n", getpid ());
  if (signal (SIGUSR1, handler) == SIG_ERR)
    {
      perror ("signal");
      return -1;
    }
  if (signal (SIGQUIT, squit) == SIG_ERR)
    {
      perror ("signal");
      return -1;
    }
  if (sigsetjmp (jmpbuf, 1))
    {
      perror ("sigsetjmp");
      return -1;
    }
  for (;;)
    pause ();

  return 0;
}
