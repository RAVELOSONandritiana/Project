#ifndef STRUCT_DEV_CSV_H
#define STRUCT_DEV_CSV_H
////////////////////////////////////////////
typedef struct Machine{
	char nom[200];
	char marque[200];
	char mac[200];
	char git[200];
}Machine;
////////////////////////////////////////////
void triage(Machine *ma,int taille){
	for(int i = 0;i < taille;i++)
	{
		for(int j = i+1;j < taille;j++)
		{
			if(strcmp((ma+i)->nom,(ma+j)->nom)>0)
			{
				Machine tmp = ma[i];
				ma[i] = ma[j];
				ma[j] = tmp;
			}
		}
	}
}
////////////////////////////////////////////
#endif
