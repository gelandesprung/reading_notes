#include<stdio.h>
#include<utime.h>
#include<unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int
main (int argc, char *argv[])
{
  struct stat mStat;
  struct utimbuf mTimebuf;
  int fd;
  if (argc != 2)
    {
      printf ("Usage:\n\t./a.out file.\n");
      return -1;
    }
  if (stat (argv[1], &mStat) == -1)
    printf ("get stat info from %s fail.\n", argv[1]);
  if ((fd = open (argv[1], O_RDONLY | O_TRUNC)) == -1)
    printf ("truncate file %s fail.\n", argv[1]);
  close (fd);
  mTimebuf.actime = mStat.st_atime;
  mTimebuf.modtime = mStat.st_mtime;
  if (utime (argv[1], &mTimebuf) == -1)
    printf ("recover time fail.\n");
  return 0;
}
