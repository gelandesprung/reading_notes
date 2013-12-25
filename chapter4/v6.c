#include<stdio.h>
#include<unistd.h>

int
main (int argc, char *argv[])
{
  char buf[1024];
  int size = 0;
  if (argc != 2)
    {
      printf ("Usage:\n\t ./a.out link.\n");
      return -1;
    }
  size = readlink (argv[1], buf, 1024);
  if (size == -1)
    {
      printf ("read link %s fail.\n", argv[1]);
    }
  buf[size] = '\0';
  printf ("%s\n", buf);
  /*remove file */
  if (remove (argv[1]) == -1)
    printf ("delete file %s fail.\n", argv[1]);
  return 0;
}
