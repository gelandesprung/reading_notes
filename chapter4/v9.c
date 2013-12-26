#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
int
main (int argc, char *argv[])
{
  struct stat mstat;
  if (argc != 2)
    return -1;
  if (stat (argv[1], &mstat) == -1)
    printf ("文件可能不存在.\n");
  printf ("%s\t %d/%d  ",argv[1], major (mstat.st_dev), minor (mstat.st_dev));
  if (S_ISCHR (mstat.st_mode))
    printf ("(charactor) ");
  if (S_ISBLK (mstat.st_mode))
    printf ("(block) ");
  printf ("%d-%d", major (mstat.st_rdev), minor (mstat.st_rdev));
  printf ("\n");
  return 0;
}
