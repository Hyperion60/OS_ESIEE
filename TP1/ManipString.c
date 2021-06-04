#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int concat(int argc, char *argv[])
{
/*
    int len = strlen(argv[2]);
    char *out = realloc(out, len * sizeof(char));
    strcpy(out, argv[2]);
    for (int i = 3; i < argc; ++i)
    {
	len += strlen(argv[i]);
	out = realloc(out, len * sizeof(char));
	strcpy(&(out[len - strlen(argv[i])]), argv[i]);
    }
    printf("%s\n", out);
    free(out);
    return 0;
*/
    for (int i = 2; i < argc; ++i)
	printf("%s", argv[i]);
    printf("\n");
    return 0;
}

int coupe(char **argv)
{
    char *str1, *token;
    char *saveptr1;
    int j;

    for (j = 1, str1 = argv[2]; ; j++, str1 = NULL)
    {
	token = strtok_r(str1, argv[3], &saveptr1);
	if (token == NULL)
	    break;
	printf("%s\n", token);
    }
    return 0;
}

static void print_blue(char str)
{
    printf("\033[1;34m\033[1;4m%c\033[0m", str);
}

int cherche(char **argv)
{
    int len = strlen(argv[2]);
    int nb = 0;
    int *list = NULL;
    for (int i = 0; argv[3][i] != 0; ++i)
    {
	int out = strncmp(&(argv[3][i]), argv[2], len);
	if (!out)
	{
	    ++nb;
	    list = realloc(list, (nb + 1) * sizeof(int));
	    list[nb - 1] = i;
	}
    }
    printf("Nombre d'occurrence trouvé : %d.\n\n", nb);
    printf("Position des occurrences : ");
    if (nb)
    {
        printf("%d", list[0] + 1);
        for (int i = 1; i < nb; i++)
	    printf(",%d", list[i] + 1);
        printf(".\n\n");

        int j = 0;
        for (int i = 0; argv[3][i] != 0; ++i)
        {
	    if (i == list[j])
	    {
	        for (int k = 0; k < len; ++k)
		    print_blue(argv[3][i++]);
	        --i;
	        j++;
	    } else {
	        printf("%c", argv[3][i]);
	    }
        }
        printf("\n");
    } else {
	printf("0.\n\n%s\n", argv[3]);
    }
    free(list);
    return 0;
}

int remplace(char **argv)
{
    int len = strlen(argv[4]);
    char *out = calloc(len, sizeof(char));
    for (int i = 0; i < len; ++i)
    {
	if (argv[4][i] == argv[2][0])
	    out[i] = argv[3][0];
	else
	    out[i] = argv[4][i];
    }
    printf("\n%s\n", out);
    free(out);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
	if (strcmp(argv[1], "concat") && strcmp(argv[1], "remplace"))
	{
            printf("Erreur de syntaxe, nombre d'arguments incorrects.\n");
  	    return 1;
	}
    }

    if (!strcmp(argv[1], "remplace") && argc != 5)
    {
	printf("Erreur de syntaxe, nombre d'arguments incorrects.\n");
	return 1;
    }

    if (!strcmp(argv[1], "concat"))
    {
	printf("Fonction concat choisie\n");
	return concat(argc, argv);
    } if (!strcmp(argv[1], "coupe"))
    {
	printf("Fonction coupe choisie\n");
	return coupe(argv);
    } if (!strcmp(argv[1], "cherche"))
    {
	printf("Fonction cherche choisie\n");
	return cherche(argv);
    } if (!strcmp(argv[1], "remplace"))
    {
	printf("Fonction remplace choisie\n");
	return remplace(argv);
    } else {
	printf("Erreur de syntaxe, fonction %s introuvable.\n", argv[1]);
	return 4;
    }
}
