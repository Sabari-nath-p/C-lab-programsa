#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int  p = fork();
    if(p==-1)
    {
        printf("There is an error while calling fork()\n");
    }
    if(p==0)
    {
        printf("CHILD ID OF PROCESS IS : %d \n", getpid() );
    }
    else
    {
        printf("parent  ID OF PROCESS IS : %d ", getppid());
    }
    return 0;
}
