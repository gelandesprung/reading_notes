#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int
main (int argc, char *argv[])
{
  int flags;
  if (argc != 2)
    printf ("we need two arguments\n");

  if ((flags = fcntl (atoi (argv[1]), F_GETFL)) == -1)
    {
      printf (" get file status flag fail.\n");
    }
  switch (flags & O_ACCMODE)
    {
    case O_RDONLY:
      printf ("read only\n");
      break;
    case O_WRONLY:
      printf ("write only\n");
      break;
    case O_RDWR:
      printf ("read write \n");
      break;
    default:
      printf ("access error \n");
      exit (127);

    }
  if (flags & O_APPEND)
    {
      printf ("append.\n");
    }
  if (flags & O_NONBLOCK)
    {
      printf ("non block .\n");
    }
#ifdef O_SYNC
  if (flags & O_SYNC)
    {
      printf ("sync.\n");
    }
#endif
  if (flags & O_RSYNC)
    {
      printf ("read after write--- rsync.\n");
    }
  if (flags & O_DSYNC)
    {
      printf ("write wait data sync only -- dsync.\n");
    }
  return 0;
}				//end of main
