#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<time.h>

int
main ()
{
  int count = 0;
  time_t t;
sigset_t set;
sigfillset(&set);
sigprocmask(SIG_SETMASK,&set,NULL);
  while (1)
    {
      if (count >= 5)
	{
//fetch time
	  if (time (&t) == -1)
	    {
	      perror ("time");
	      return -1;
	    }
	  printf ("%s\n", ctime (&t));
	  count = 0;
	}
      sleep (60);
      count++;
    }
  return 0;
}
