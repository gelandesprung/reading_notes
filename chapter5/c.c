#include<stdio.h>
int
main (int argc, char *argv[])
{
  FILE *fp;
  char buf[10];
  if (argc != 2)
    return -1;
  if ((fp = fopen (argv[1], "r")) == NULL)
    {
      printf ("open file %s fail\n", argv[1]);
      return -1;
    }

  while (!feof (fp))
    {
      fgets (buf, 10, fp);
      if (ferror (fp))
	break;
      printf ("%s", buf);
      printf ("-");
    }
  close (fp);
  return -1;
}
