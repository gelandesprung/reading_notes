#include<sys/stat.h>
#include<string.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
  int i,ret;
  struct stat mStat;
  if (argc < 2)
    {
      printf ("Usage:\n\t./a.out file.\n");
      return 0;
    }

  for (i = 1; i < argc; i++)
    {
      if ((ret = lstat (argv[i], &mStat)) == -1)
	{
	  printf ("fetch stat of %s fail.\n", argv[i]);
	  continue;
	}
      else
	printf ("%s is :", argv[i]);
      if (S_ISREG (mStat.st_mode))
	printf ("regular file.\n");
      if (S_ISDIR (mStat.st_mode))
	printf ("directory .\n");
      if (S_ISLNK (mStat.st_mode))
	printf ("link file.\n");
      if (S_ISBLK (mStat.st_mode))
	printf ("block special file.\n");
      if (S_ISCHR (mStat.st_mode))
	printf ("charactor special file.\n");
      if (S_ISSOCK (mStat.st_mode))
	printf ("socket file.\n");
      if (S_ISFIFO (mStat.st_mode))
	printf ("PIPO file.\n");
if(S_ISUID&mStat.st_mode)
printf("uid is set.\n");
    }
  return 0;
}
