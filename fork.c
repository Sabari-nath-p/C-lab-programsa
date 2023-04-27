#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    fork();
    fork();
    printf("Using fork() system call\n");
    return 0;
}
