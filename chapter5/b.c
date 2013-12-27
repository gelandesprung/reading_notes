#include<stdio.h>
int
main (int argc, char *argv[])
{
  FILE *fp;
  int c;

  if (argc != 2)
    return -1;
  if ((fp = fopen (argv[1], "r")) == NULL)
    {
      putchar ('x');
      return -1;
    }
  while (1)
    {
      c = fgetc (fp);
      if (feof(fp))
	break;
      if (c == '\n')
	{
	  ungetc ('-', fp);
	  continue;
	}
      putchar (c);
    }
close(fp);
  return 0;
}
