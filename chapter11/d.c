#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

struct msg
{
  struct msg *msg_next;
  time_t msg_time;
};
struct msg *head;

pthread_cond_t qcond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mlock = PTHREAD_MUTEX_INITIALIZER;

void *
process (void *arg)
{
  struct msg *mp;
  for (;;)
    {
      pthread_mutex_lock (&mlock);
      while (head == NULL)
	pthread_cond_wait (&qcond, &mlock);
      mp = head;
      head = mp->msg_next;
      pthread_mutex_unlock (&mlock);
      printf ("%s\n", ctime (&mp->msg_time));
      free (mp);
    }
}

void
enquene_msg (struct msg *mp)
{
  pthread_mutex_lock (&mlock);
  mp->msg_next = head;
  head = mp;
  pthread_mutex_unlock (&mlock);
  pthread_cond_signal (&qcond);
}

int
main ()
{
  pthread_t tid;
  struct msg *tmp;
  head = NULL;
  pthread_create (&tid, NULL, process, NULL);
  while (1)
    {
      tmp = malloc (sizeof (struct msg));
      if (tmp == NULL)
	return -1;
      memset (tmp, 0, sizeof (struct msg));
      tmp->msg_next = NULL;
      time (&tmp->msg_time);
      enquene_msg (tmp);
      sleep(2);
    }
  return 0;
}
