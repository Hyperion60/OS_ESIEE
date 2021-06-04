#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Erreur de syntaxe, nombre d'arguments incorrects\n");
        return 1;
    }

    int arg1 = atoi(argv[1]);
    if (arg1 <= 0)
    {
        printf("Erreur de syntaxe, %s n'est pas un nombre entier strictement positif.\n", argv[1]);
        return 2;
    }

    if (strcmp(&(argv[0][2]), argv[2]))
    {
        printf("Erreur de syntaxe, le nom du programme n'est pas %s\n", argv[2]);
        return 3;
    }

    for (int i = 0; i < arg1; ++i)
        printf("%s\n", argv[2]);
    return 0;
}
