#include<sys/stat.h>
#include <unistd.h>
#include<stdio.h>
int
main (int argc,char* argv[])
{
/**
*检查参数传入的文件是否存在，如果不存在就创建这个文件并修改权限
*/
  int fd;
  if (argc != 2)
    {
      printf ("Usage:\n\t./a.out file\n");
      return 0;
    }
  umask (S_IROTH);
  if (access (argv[1], F_OK))
    {
      if ((fd = creat (argv[1], S_IRUSR | S_IRGRP | S_IROTH)) == -1)
	{
	  printf ("creat file %s fail.\n", argv[1]);
	  return -1;
	}
      close (fd);
    }
#ifdef DEBUG_CHMOD
  if (chmod
      (argv[1],
       S_IRWXU | S_IRWXG | S_IRWXO | S_ISUID | S_ISGID | S_ISVTX) == -1)
    {
      printf ("chmod file %s fail.\n", argv[1]);
    }
#endif
}
