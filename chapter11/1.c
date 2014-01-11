#include<pthread.h>
#include<stdio.h>

struct demo
{
  char name[1024];
  int id;
  char desc[1024];
};
pthread_barrier_t b;
void *
thr_fn (void *arg)
{
  struct demo *p = (struct demo *) arg;
  printf ("name=%s id=%d desc=%s\n", p->name, p->id, p->desc);
  pthread_barrier_wait (&b);

  return ((void *) 0);
}

int
main ()
{
  struct demo d;
  pthread_t tid;
  pthread_attr_t attr;
  int detachstat;
  pthread_attr_init (&attr);
  pthread_attr_getdetachstate (&attr, &detachstat);
  if (detachstat != PTHREAD_CREATE_DETACHED)
    {
      detachstat = PTHREAD_CREATE_DETACHED;
      pthread_attr_setdetachstate (&attr, detachstat);
    }

  strcpy (d.name, "yanchao");
  d.id = 100;
  strcpy (d.desc, "this is a demo structure.");

  pthread_barrier_init (&b, NULL, 2);
  pthread_create (&tid, &attr, thr_fn, (void *) &d);
  pthread_attr_destroy (&attr);
  pthread_barrier_wait (&b);

  return 0;
}
