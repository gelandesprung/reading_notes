#include<stdio.h>
int
main ()
{
  FILE *fp;
float l;
  if ((fp = fopen ("/tmp/t.txt", "w+")) == NULL)
    {
      printf ("creat file /tmp/t.txt fail\n");
    }
fscanf(fp,"%5f",&l);
  printf ("%05.1f\n",l); 
  fclose (fp);
  return 0;
}
