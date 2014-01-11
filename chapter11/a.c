#include<pthread.h>
#include<signal.h>
#include<stdio.h>

static int count = 0;
static int flag=0;
void
handler (int signo)
{
  printf ("handler\n");
  flag=1;
}

void *
func (void *arg)
{
  while (1)
    {
      printf ("child %d\n", count++);
    }
}

int
main ()
{
  struct sigaction act, oact;
  pthread_t tid;
  sigemptyset (&act.sa_mask);
  act.sa_flags = 0;
  act.sa_handler = handler;
  sigaction (SIGALRM, &act, &oact);

pthread_create(&tid,NULL,func,NULL);
  while (1)
    {
printf("main\n");
    }
  sigaction (SIGALRM, &oact, &act);
  return 0;
}
