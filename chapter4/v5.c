#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int
main (int argc, char *argv[])
{
  int ret;
  struct stat mStat;
  if (argc != 2)
    {
      printf ("Usage:\n\t ./a.out file.\n");
      return -1;
    }

  if (access (argv[1], F_OK) == -1)
    {
      printf ("file %s not exit.\n", argv[1]);
      return -1;
    }
  if (lstat (argv[1], &mStat) == -1)
    {
      printf ("can't get file %s's stat.\n", argv[1]);
      return -1;
    }
  if (S_ISDIR (mStat.st_mode))
    printf ("%s is dir   ", argv[1]);
  if (mStat.st_mode & S_ISVTX)
    printf ("set text.\n");
/*  else
    {
      if (chmod (argv[1], mStat.st_mode|S_ISVTX ) == -1)
	{
	  printf ("set text mode fail.\n");
	}
    }
*/
  printf ("link count = %d uid=%d \n", mStat.st_nlink, mStat.st_uid);
  return 0;
}
