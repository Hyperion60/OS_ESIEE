#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
    pid_t self = getpid();
    printf("PID du processus courant : %d\n", self);

    pid_t pid;
    if ((pid = fork()) == 0)
    {
        printf("PID du processus fils : %d\n", getpid());
    } else {
        printf("PID du processus pere : %d\n", getpid());
    }

    return 0;
}

