#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void) {
    struct rusage my_sys, my_end;
    if (getrusage(RUSAGE_SELF, &my_sys) < 0)
        return 1;

    printf("Taille résidente maximale : %ld octets\n", my_sys.ru_maxrss);
    printf("Taille de la mémoire partagée : %ld octets\n", my_sys.ru_ixrss);
    printf("Taille de la mémoire non partagée : %ld octets\n", my_sys.ru_idrss);
    printf("Taille de la pile : %ld octets\n", my_sys.ru_isrss);
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

    if (getrusage(RUSAGE_SELF, &my_end) < 0)
        return 1;

    printf("Temps CPU utilisé par l'utilisateur : %ld microsecondes\n",
            my_end.ru_utime.tv_usec - my_sys.ru_utime.tv_usec);
    printf("Temps CPU utilisé par le système : %ld microsecondes\n",
            my_end.ru_stime.tv_usec - my_sys.ru_stime.tv_usec);
}
