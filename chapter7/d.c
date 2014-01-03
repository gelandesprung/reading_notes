#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void
my_alarm (int signo)
{
  printf ("haha\n");
}

int
main ()
{
  signal (SIGALRM, my_alarm);
  alarm (2);
  pause ();
  printf ("i am back\n");
  return 0;
}
