#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void) {
    pid_t child_1, child_2;

    child_1 = fork();

    if (child_1 == 0) {
        printf("Processus %d, groupe %d\n", getpid(), getpgid());
        for (int i = 0; i < 30; ++i)
        {
            printf("%d survis\n", getpid());
            sleep(1);
        }
    } else {
         printf("Processus %d, groupe %d\n", getpid(), getpgrp());
         child_2 = fork();
         if (child_2 == 0) {
             for (int i = 0; i < 30; ++i)
            {
                printf("%d survis\n", getpid());
                sleep(1);
            }
         } else {
            printf("Processus %d, groupe %d\n", getpid(), getpgrp());
            for (int i = 0; i < 30; ++i)
            {
                printf("%d survis\n", getpid());
                sleep(1);
            }
        }
    }
} 
