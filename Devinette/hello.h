#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define cls "clear"
char *prenom(char *nom);
int hello(){

    char *nom;
    nom = (char *)malloc(sizeof(char ) * 20);
        nom = prenom(nom);
        if(strcmp(nom,"05/01/2023")!=0)
        {
            printf("Votre Licence est obsolete\n");
            exit(1);
        }
    system(cls);
    return 0;
}
char *prenom(char *nom){

    printf("Entrer votre licence : ");

    scanf("%s",nom);

    return nom;
}

