#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>

void
listdir (const char *path)
{
  struct stat mstat;
  struct DIR *mpdir;
  struct dirent *mpdirent;
//check path is a directory
  if (lstat (path, &mstat) == -1)
    printf ("path: %s may no exist.\n", path);
  if (!S_ISDIR (mstat.st_mode))
    {
      printf ("%s is no a directory. exit\n", path);
      exit (127);
    }
  if ((mpdir = opendir (path)) == NULL)
    printf ("open dir %s fail.\n", path);
  if (chdir (path) == -1)
    {
      printf ("chdir fail.\n");
      exit (127);
    }
  while ((mpdirent = readdir (mpdir)) != NULL)
    {
      lstat (mpdirent->d_name, &mstat);
//打开文件类型
      switch (mstat.st_mode & S_IFMT)
	{
	case S_IFREG:
	  printf ("f");
	  break;
	case S_IFDIR:
	  printf ("d");
	  break;
	case S_IFSOCK:
	  printf ("s");
	  break;
	case S_IFLNK:
	  printf ("l");
	  break;
	case S_IFCHR:
	  printf ("c");
	  break;
	case S_IFBLK:
	  printf ("b");
	  break;
	case S_IFIFO:
	  printf ("p");
	  break;
	default:
	  printf ("-");
	  break;
	}
//打开文件权限
      if (mstat.st_mode & S_IRUSR)
	printf ("r");
      else
	printf ("-");
      if (mstat.st_mode & S_IWUSR)
	printf ("w");
      else
	printf ("-");
      if (mstat.st_mode & S_IXUSR)
	printf ("w");
      else
	printf ("-");
      if (mstat.st_mode & S_IRGRP)
	printf ("r");
      else
	printf ("-");
      if (mstat.st_mode & S_IWGRP)
	printf ("w");
      else
	printf ("-");
      if (mstat.st_mode & S_IXGRP)
	printf ("x");
      else
	printf ("-");
      if (mstat.st_mode & S_IROTH)
	printf ("r");
      else
	printf ("-");
      if (mstat.st_mode & S_IWOTH)
	printf ("w");
      else
	printf ("-");
      if (mstat.st_mode & S_IXOTH)
	printf ("x");
      else
	printf ("-");

      printf ("\t%d", mstat.st_nlink);
      printf ("\t%d \t%d \t%s\n", mstat.st_size / 1024,
	      mstat.st_uid, mpdirent->d_name);
    }
  close (mpdir);
}

int
main (int argc, char *argv[])
{
  if (argc != 2)
    return -1;
  listdir (argv[1]);
  return 0;
}
