#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void print_info(struct rusage my_sys) {
    printf("Taille résidente maximale : %ld\n", my_sys.ru_maxrss);
    printf("Taille de la mémoire partagée : %ld\n", my_sys.ru_ixrss);
    printf("Taille de la mémoire non partagée : %ld\n", my_sys.ru_idrss);
    printf("Taille de la pile : %ld\n", my_sys.ru_isrss);
    printf("Demande de pages : %ld\n", my_sys.ru_minflt);
    printf("Nombre de fautes de pages : %ld\n", my_sys.ru_majflt);
    printf("Nombre de swaps : %ld\n", my_sys.ru_nswap);
    printf("Nombre de lecture de blocs : %ld\n", my_sys.ru_inblock);
    printf("Nombre d'écriture de blocs : %ld\n", my_sys.ru_oublock);
    printf("Nombre de messages émis : %ld\n", my_sys.ru_msgsnd);
    printf("Nombre de messages reçus : %ld\n", my_sys.ru_msgrcv);
    printf("Nombre de signaux reçus : %ld\n", my_sys.ru_nsignals);
    printf("Changements de contexte volontaires : %ld\n", my_sys.ru_nvcsw);
    printf("Changements de contexte involontaires : %ld\n", my_sys.ru_nivcsw);
    printf("Temps CPU utilisé par l'utilisateur : %ld\n",
            my_sys.ru_utime.tv_usec);
    printf("Temps CPU utilisé par le système : %ld\n",
            my_sys.ru_stime.tv_usec);
}


int main(int argc, char **argv) {
    struct rusage my_sys;
    pid_t wpid;
    int status;

    if (argc == 1) {
        if (getrusage(RUSAGE_SELF, &my_sys) < 0)
            return 1;
        print_info(my_sys); // Affiche les statistiques concernant le processus
        return 0;
    }
    if (argc != 2)
        return 1;

    FILE *fp;
    char buff[16384];

    char cmd[1024] = {0};
    strcpy(cmd, "/usr/bin/man ");
    strcpy(&(cmd[13]), argv[1]);

    fp = popen(cmd, "r");
    if (fp == NULL)
        exit(1);
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
    }
    pclose(fp);
    return 0;
}

