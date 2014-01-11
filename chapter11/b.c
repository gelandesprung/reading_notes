#include<pthread.h>
#include<stdio.h>

struct foo{
int id;
pthread_mutex_t mutex;
int count;
};
int foo_init(int id){
struct foo* p;
if((p=malloc(sizeof(struct foo)))==NULL){
perror("malloc");
return -1;
}
p->id=id;
if(pthread_mutex_init(&p->mutex)){
free(p);
return -1;
}
p->count=1;
return 0;
}

int foo_hold(struct foo *p){
pthread_mutex_lock(p);
p->count++;
pthread_mutex_unlock(p);
return 0;
}

int foo_release(struct foo *p){
pthread_mutex_lock(p);
p->count--;
if(p->count<0){
pthread_mutex_unlock(p);
free(p);
return 0;
}
pthread_mutex_unlock(p);
}

