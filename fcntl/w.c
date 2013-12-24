#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024
int
main (int argc ,char *argv[])
{
  int ret;
  int fd_s, fd_d;
  char buf[BUFSIZE];
  int flags;

  if (argc != 3){
    printf ("Usage:\n\t ./a.out srcfile dstfile.\n");
    goto exit2;
    }

  if ((fd_s = open (argv[1], O_RDONLY, 0)) < 0)
    {
      printf ("open file %s fail.\n", argv[1]);
    }

  if ((fd_d = open (argv[2], O_WRONLY | O_TRUNC, 0)) < 0)
    {
      printf ("open file %s fail.\n", argv[2]);
      close (fd_s);
      exit (127);
    }
  if ((flags = fcntl (fd_d, F_GETFL, 0)) == -1)
    {
      printf ("fcntl get %s fail.\n", argv[2]);
      goto exit2;
    }
  flags &= ~O_SYNC;
#ifdef DEBUG_SYNC
  flags |= O_SYNC;
#endif
  if (fcntl (fd_d, F_SETFL, flags) == -1)
    {
      printf ("fcntl set %s fail.\n", argv[2]);
      goto exit2;
    }

  while ((ret = read (fd_s, buf, BUFSIZE)) > 0)
    {
      if (write (fd_d, buf, ret) < 0)
	{
	  perror ("write file:");
	  goto exit2;
	}
    }
exit2:
  close (fd_s);
  close (fd_d);
  exit (127);

exit1:
  close (fd_s);
  close (fd_d);
  return 0;

}
