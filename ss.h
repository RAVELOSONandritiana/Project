#ifndef SS_h
#define SS_H
typedef struct Etudiant{
	char nom[50];
	char prenom[20];
	char age[10];
	char git[100];
	char email[100];
	char addresse[100];
	char sexe[20];
	char numero[11];
}Etudiant;
/////////////////////////////////////////////////////////
void triage(Etudiant *ma,int taille){
	for(int i = 0;i < taille;i++)
	{
		for(int j = i+1;j < taille;j++)
		{
			if(strcmp((ma+i)->nom,(ma+j)->nom)>0)
			{
				Etudiant tmp = ma[i];
				ma[i] = ma[j];
				ma[j] = tmp;
			}
		}
	}
}
///////////////////////////////////////////////////////




#endif
