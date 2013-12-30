#include<unistd.h>
#include<stdio.h>

int
main ()
{
  int fd;
  FILE *fp;
  pid_t pid;
  int ret;
  char buf[] = "befor fork\n";
  char tmp[1024]={0};
  if ((fp = tmpfile ()) == NULL)
    {
      perror ("tmpfile fail.\n");
      return -1;
    }
  if ((fd = fileno (fp)) == -1)
    {
      perror ("fileno fail.\n");
      fclose (fp);
      return -1;
    }
  if ((ret = write (fd, buf, strlen (buf))) < 0)
    {
      perror ("write fail\n");
      fclose (fp);
      return -1;
    }
  if ((ret = lseek (fd, 0, SEEK_SET)) == -1)
    {
      perror ("lseek fail.");
      fclose (fp);
      return -1;
    }
  if ((ret = read (fd, tmp, 1024)) == -1)
    {
      perror ("lseek read.");
      fclose (fp);
      return -1;
    }
  if (write (STDOUT_FILENO, tmp, strlen (tmp)) < 0)
    {
      perror ("write to stdout fail");
      fclose (fp);
      return -1;
    }
printf("haha\n");
  if ((pid = fork ()) < 0)
    {
      perror ("fork fail\n");
      fclose (fp);
      return -1;
    }
  if (pid == 0)
    {
      puts ("this is child.");
      exit (0);
    }
  if (pid > 0)
    {
      puts ("this is parent");
    }
  fclose (fp);
  return 0;
}
