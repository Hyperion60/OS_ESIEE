#include <stdio.h>

int main(int argc, char **argv)
{
    printf("OSTP1 : Exercice n°1\n\n");
    printf("Nombre d'argument : %d\n\n", argc - 1);
    printf("Liste des arguments :");
    for (int i = 1; i < argc; ++i)
        printf(" %s", argv[i]);
    printf(".\n");
    return 0;
}
