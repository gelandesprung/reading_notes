#include<stdio.h>
extern char **environ;
void
test2 (void)
{
  printf ("test2\n");
}

void
test1 (void)
{
  printf ("test1\n");
}

int
main ()
{
  char **ptr = environ;
  while (*ptr!=NULL)
    {
      printf ("%s\n", *ptr++);
    }
  atexit (test1);
  atexit (test2);
  return 0;
}
