#include<stdio.h>
#include<signal.h>

void
sig_handler (int signo)
{
  printf ("x\n");
}

int
main ()
{
  int ret;
  if (signal (SIGQUIT, sig_handler) == SIG_ERR)
    {
      perror ("signal");
      return -1;
    }
  ret = sleep (10);
  printf ("%d\n", ret);
return 0;
}
