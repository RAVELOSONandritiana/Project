/*
* 
* 
* PROGRAMME QUI FAIT DES TRIAGES 
* MIT - MACHINE - STRUCTURE
* 
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structDevCsv.h"
#define MAX 200
int main(){
	FILE *fichier = NULL;
	char dossier[90];
	printf("Entrer le nom du fichier(.csv) : ");
	scanf("%s",dossier);
	fichier = fopen(dossier,"w+");
	if(fichier == NULL)
	{
		printf("Erreur de fichier\n");
		exit(0);
	}
	Machine *ma;
	int taille = 0;
	printf("Taille : ");
	scanf("%d",&taille);
	ma = (Machine*)malloc(sizeof(Machine)*taille);
	fprintf(fichier,"Nom,Marque,MAC,Github\n");
	for(int i = 0;i < taille;i++)
	{
		printf("Nom    [%d] : ",i);
		scanf("%s",(ma+i)->nom);
		printf("Marque [%d] : ",i);
		scanf("%s",(ma+i)->marque);
		printf("MAC    [%d] : ",i);
		scanf("%s",(ma+i)->mac);
		printf("Git    [%d] : ",i);
		scanf("%s",(ma+i)->git);
	}
	
//Triage de Machine
	triage(ma,taille);
	for(int i = 0;i < taille;i++)
	{
		fprintf(fichier,"%s,",(ma+i)->nom);
		fprintf(fichier,"%s,",(ma+i)->marque);
		fprintf(fichier,"%s,",(ma+i)->mac);
		fprintf(fichier,"%s\n",(ma+i)->git);
	}
	
	return 0;
}
