#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ss.h"
int main(){
	FILE *fichier=NULL;
	char dossier[50];
	int taille = 0;
	printf("Entrer le nom du fichier(.csv) : ");
	scanf("%s",dossier);
	printf("Taille : ");
	scanf("%d",&taille);
	fichier = fopen(dossier,"w+");
	
	if(fichier == NULL)
	{
		printf("Erreur de fichier\n");
		exit(0);
	}
	Etudiant *ma;
	ma = (Etudiant*)malloc(sizeof(Etudiant)*taille);
	fprintf(fichier,"Nom,Prenom,Age,Git,Email,Addresse,Sexe,Numero\n");
	for(int i = 0;i < taille;i++)
	{
		printf("Nom    [%d]    : ",i);
		scanf("%s",(ma+i)->nom);
		
		printf("Prenom [%d]    : ",i);
		scanf("%s",(ma+i)->prenom);
		
		printf("Age    [%d]    : ",i);
		scanf("%s",(ma+i)->age);
		
		printf("Git    [%d]    : ",i);
		scanf("%s",(ma+i)->git);
		
		printf("Email    [%d]  : ",i);
		scanf("%s",(ma+i)->email);
		
		printf("Addresse [%d]  : ",i);
		scanf("%s",(ma+i)->addresse);
		
		printf("Sexe    [%d]   : ",i);
		scanf("%s",(ma+i)->sexe);
		
		printf("Numero    [%d] : ",i);
		scanf("%s",(ma+i)->git);
		
	}
	
//Triage de Machine
	triage(ma,taille);
	for(int i = 0;i < taille;i++)
	{
		fprintf(fichier,"%s,",(ma+i)->nom);
		fprintf(fichier,"%s,",(ma+i)->prenom);
		fprintf(fichier,"%s,",(ma+i)->age);
		fprintf(fichier,"%s",(ma+i)->git);
		fprintf(fichier,"%s,",(ma+i)->email);
		fprintf(fichier,"%s,",(ma+i)->addresse);
		fprintf(fichier,"%s,",(ma+i)->sexe);
		fprintf(fichier,"%s\n",(ma+i)->numero);
	}
	fclose(fichier);
	return 0;
}
