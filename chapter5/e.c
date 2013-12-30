#include<stdio.h>
#include <errno.h>
#include<string.h>
int
main (void)
{
  char buf[] = "tmp_XXXXXX";
  char content[1024];
  FILE *fp;
  int fd;
  if ((fd = mkstemp (buf)) == -1)
    {
      printf ("open a temp file fail. %s\n", strerror (errno));
      return -1;
    }
  unlink (buf);
  if ((fp = fdopen (fd, "rw")) == NULL)
    {
      printf ("open a temp file fail\n");
      return -1;
    }
  fputs ("this is a test string.", fp);
  rewind (fp);
  fgets (content, 1024, fp);
  return 0;
}
