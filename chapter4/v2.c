#include<unistd.h>
#include<stdio.h>
int
main (int argc, char *argv[])
{
  int ret;

  if (argc != 2)
    {
      printf ("Usage:\n\t./a.out file\n");
      return -1;
    }
  if ((ret = access (argv[1], R_OK)) == -1)
    printf ("no read priviledge.\n");
  else
    printf ("ok\n");
  return 0;
}
