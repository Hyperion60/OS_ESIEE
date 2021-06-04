#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        printf("Je m'endors\n");
        sleep(10);
        printf("Mon PID (fils) est %d\n", getpid());
        printf("Je me reveille, mon code de sortie est : %d\n", 42);
        exit(42);
    } else {
        printf("Mon PID (pere) est %d\n", getpid());
        // signal(SIGCHLD, SIG_IGN);
        // sleep(10);
        wpid = wait(&status);
        if (wpid != -1) {
            printf("mon fils est mort ; son code de sortie est : %d\n",
                    WEXITSTATUS(status));
        }
    }
    return 0;
}
