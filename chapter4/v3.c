#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)
int
main ()
{
  int ret;
  umask (0);
  if ((ret = creat ("foo1", RWRWRW)) == -1)
    printf ("creat file foo1 fail.\n");
  umask (S_IRUSR | S_IRGRP | S_IROTH);
  if ((ret = creat ("foo2", RWRWRW)) == -1)
    printf ("creat file foo2 fail.\n");
  return 0;
}
