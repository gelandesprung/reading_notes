#include<sys/utsname.h>
#include<stdio.h>
int
main ()
{
  struct utsname un;
  if (uname (&un) == -1)
    {
      printf ("fail\n");
      return -1;
    }
  printf ("%s\n %s\n %s\n %s\n %s\n", un.sysname, un.nodename, un.release, un.version,
	  un.machine);
  return 0;
}
