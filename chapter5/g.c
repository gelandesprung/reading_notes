#include<time.h>
#include<stdio.h>
int main()
{
time_t btime;
struct tm *mtm;
/*
if(time(&btime)==-1){
printf("get time fail.\n");
return -1;
}
mtm=localtime(&btime);
printf("%s\n",asctime(mtm));
*/
btime=time(NULL);
printf("%s\n",ctime(&btime));
return 0;
}
