#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
/**
*创建的方式打开一个文件，我要看它创建的文件权限是什么样的，并且要调用fwide查看它的访问序列
*/
int
main (int argc, char *argv[])
{
  FILE *fp;
  int ret;
  if ((fp = freopen ("tmp.txt", "w", stdout)) == NULL)
    {
      printf ("creat file tmp.txt fail.\n");
      return -1;
    }
  printf ("kao\n");
  ret = fwide (fp, 5);
  if (ret < 0)
    printf ("byte-oriented\n");
  else if (ret > 0)
    printf ("wide-oriented\n");
  else
    printf ("no orientation.\n");
  fclose (fp);
  return -1;
}
