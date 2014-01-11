#include<stdio.h>
#include<signal.h>
void sig_quit(int signo){}
int main()
{
sigset_t set,oset;
signal(SIGQUIT,sig_quit);
sigfillset(&set);
sigemptyset(&oset);
sigdelset(&set,SIGQUIT);
sigsuspend(&set);
sigpending(&oset);
if(!sigismember(&oset,SIGCONT)){
psignal(SIGCONT,NULL);
}
if(!sigismember(&oset,SIGSTOP)){
psignal(SIGSTOP,NULL);
}
if(!sigismember(&oset,SIGTTIN)){
psignal(SIGTTIN,NULL);
}
if(!sigismember(&oset,SIGTTOU)){
psignal(SIGTTOU,NULL);
}
if(!sigismember(&oset,SIGTSTP)){
psignal(SIGTSTP,NULL);
}
return 0;
}
