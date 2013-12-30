#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>

int
main ()
{
  char *p, *tmp;
  int fd;
  FILE *fp;
  char contents[1024];
int ret;
  if ((tmp = tmpnam (NULL)) == NULL)
    {
      perror ("creat tmp file name.");
      return -1;
    }
  printf ("tmp file name =%s\n", tmp);
  if ((p = malloc (strlen (tmp))) == NULL)
    {
      perror ("creat tmp file name.");
      return -1;
    }
  memset (p, 0, sizeof (p));
  memcpy (p, tmp, strlen (tmp));
  p = realloc (p, strlen (p) + 8);
  tmp = p + strlen (p);
  strncpy (tmp, "_XXXXXX", 7);
  printf ("%s\n", p);
  if ((fd = mkstemp (p)) == -1)
    {
      free (p);
      perror ("mskstemp fail.");
      return -1;
    }
  if ((fp = fdopen (fd, "w+")) == NULL)
    {
      perror ("fdopen fail");
      close (fd);
      free (p);
      return -1;
    }
  if ((ret = fputs ("this is a test string.", fp))<=0 )
    {
      perror ("wirte fail");
      fclose (fp);
      free (p);
      return -1;
    }
  if (fgets (contents, 1024, fp) <= 0)
    {
      perror ("read file fail.");
    }
  else
    {
      printf ("read from file %s\n", contents);
    }
  fclose (fp);
  free (p);
  return 0;
}
