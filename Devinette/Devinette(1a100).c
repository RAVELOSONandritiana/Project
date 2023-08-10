//Sur windows , Vous pouvez activer les commentaires des bibliotheques et des fonctions pour avoir plus de fonctionnalites
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//#include <conio.h>
//#include <windows.h>
#include "hello.h"
#define cls "clear"

void affichage(char *titre);
void affichage2(char *titre2);
void afficheAide(char *colonne,int tailleDeChaine);
int choixDepart(int choix,char *titre,char *colonne,int tailleDeChaine);
int nombreMystere(int nombreRand,const int max,const int min);
void traitement(int nombre,int nombreRand,char *titre2,int *score);
void unParun(char *colonne,int tailleDeChaine);
void charge();
void depllc(int li,int co);
void Avicii();              //dessine le drapeau
void andry();               //fait l'animation apart le drapeau
/*************************************************************************/
int main(){
    int nombre=0;
    int nombreRand=0;
    const int max=100,min=1;
    char titre[]="JEUX DE DEVINETTE";
    char titre2[]="GAME OVER";
    int choix=0;
    int score=0;
    int tailleDeChaine=0;
    char colonne[1000];

    //hello();

        andry();

    while(1){
            system(cls);
            printf("\n\n");

            Avicii();
            depllc(3,1);
            choix=choixDepart(choix,titre,colonne,tailleDeChaine);

            system(cls);
//si le choix c'est de jouer
            if(choix==1)
            {
                nombreRand=nombreMystere(nombreRand,max,min);

                //printf("%d\n",nombreRand);

                charge();
                printf("\n\n");
                Avicii();
                depllc(3,1);

                traitement(nombre,nombreRand,titre2,&score);
            }
//si le choix est de voir l'aide
            else if(choix==2)
            {
                charge();
                printf("\n\n");
                Avicii();
                depllc(3,1);
                afficheAide(colonne,tailleDeChaine);
            }
//si on veut quitter
            else if(choix==3)
            {
                printf("\n\n");
                Avicii();
                depllc(3,1);
                sprintf(colonne,"\e[36mvotre score total est  %d\n\e[0m",score);
                unParun(colonne,tailleDeChaine);
                exit(1);
            }
            //getch();

    }

    return 0;
}
/*************************************************************************/
int nombreMystere(int nombreRand,const int max,const int min){

    srand(time(NULL));

    nombreRand=rand()%(max-min)+1;

    return nombreRand;
}
/*************************************************************************/
void affichage(char *titre){

    printf("=============================================\n"
           "               %s             \n"
           "=============================================\n",titre);
    printf("\n");
}
/*************************************************************************/
void traitement(int nombre,int nombreRand,char *titre2,int *score){
    int i=0;
    int cpt=1;      ///compter le nombre de vie
    const int max = 8;
    static char *good="Bravo,vous avez trouver le nombre ";

    printf("C'est partit\n\n");
    printf("\e[1;31mscore :\e[0m %d\n\n",*score);
    for(i=max;i>1;i--)
    {

            printf("\e[1;31mPV    :\e[0m ");
///Afficher une couleur designant le nombre de coups restant
            for(int j=cpt;j<=7;j++)
            {
                printf("\e[45m  \e[0m ");
                usleep(500000);
            }
            cpt++;
            printf("\n\n");
            printf("votre nombre    : ");
            scanf("%d",&nombre);
            printf("\nCaracteristique : ");
            sleep(2);
            if(nombre > nombreRand)
            printf("\e[41m  \e[0m");
            else if(nombre < nombreRand)
            printf("\e[46m  \e[0m");
            else if(nombre == nombreRand)
            printf("\e[42m  \e[0m");
            printf("\n\n");
                if(i>1  && nombre==nombreRand)
                {
                    printf("\n");
                    printf( "\e[44;33m\t\t\t\t\t\t\t=============================================\e[0m\n"
                            "\e[44;36m\t\t\t\t\t\t\t      %s     \e[0m\n"
                            "\e[44;33m\t\t\t\t\t\t\t=============================================\e[0m\n",good);
                    //for(int i=0;i<3;i++)
                    //{
                    //    MessageBeep(MB_ICONEXCLAMATION);
                    //    sleep(1);
                    //}
                    printf("\n");
                    *score+=10;
                    printf("vous avez gagnez 10 pts\n>>>>Votre score actuel %d\n",*score);
                        break;
                }
//Aide venant de l'ordinateur
        if(i==(max/2))
        {
            printf("\nVous obtenez une astuce   ");
                if(nombreRand%2==0)
                    printf("\e[32mC'est pair\e[0m\n");
                else
                    printf("\e[32mC'est impair\e[0m\n");
        }

    }
        if(i==1){
            printf("\n");

            printf( "\t\t\t\t=============================================\n"
                    "\t\t\t\t               %s             \n"
                    "\t\t\t\t=============================================\n",titre2);
            printf("\n");
            *score+=-10;
            printf("[Vous avez perdu 10 pts]\n>>>>Votre score actuel est : %d\n",*score);
        }
}
/*************************************************************************/
int choixDepart(int choix,char *titre,char *colonne,int tailleDeChaine){
    affichage(titre);
    sprintf(colonne,"\t[1]-Jouer\n\n"
           "\t[2]-Voir aide\n\n"
           "\t[3]-Quitter\n\n\n"
           "votre choix : ");
    unParun(colonne,tailleDeChaine);
    do{
    scanf("%d",&choix);
    printf("\n");
    }while(choix>3 ||choix<1);

    return choix;
}
/*************************************************************************/
void afficheAide(char *colonne,int tailleDeChaine){

    sprintf(colonne,"\e[2;34mSALUT\n\nBienvenue dans Devinette\n\n"
           "il n'y a q'une seule regle dans le jeu\n\n"
           "->Il faut deviner le nombre mystere en moins de 7 coups,\n\n"
           "si vous y arrivez vous obtiendrez 10 pts\n\ndans le "
           "cas contraire,ce sera -10\n\n"
           "Il faut aussi savoir qu'a la moitie du coups , vous obtenez une astuce\n\n"
           "En faisant votre nombre , 3 couleurs vont vous aider :\e[0m\n\n"
           ">>\e[31mLe rouge si votre nombre est plus grand\e[0m\n\n"
           ">>\e[36mLe bleu  si votre nombre est plus petit\e[0m\n\n"
           ">>\e[32mLe vert  si vous  l'avez trouver\n\n\e[0m");
    unParun(colonne,tailleDeChaine);
}
void charge(){
    printf("\nchargement ");
                for(int i=1;i<=35;i++)
                {
                    printf("\e[42m   \e[0m");
                    usleep(50000);
                }
                printf("\n\n");
    system(cls);
}

void unParun(char *colonne,int tailleDeChaine){

    tailleDeChaine = strlen(colonne);

    for(int i=0;i<tailleDeChaine;i++)
    {
        printf("%c",colonne[i]);
        usleep(50000);
    }

}
//La fconction qui me permet de se deplacer comme dans CSS
void depllc(int li,int co){
    printf("\e[%d;%dH",li,co);
}
//Pour afficher notre drapeau
void Avicii(){

int max=20;

    for(int i=0;i<max;i++)
    {
        printf("\t\t\t\t\t\t\t\t\t\t\t");
        for(int j=0;j<max/2;j++)
        {

            printf("\e[47m  \e[0m");
        }
        printf("\n");
        usleep(50000);
    }

int n=3;
    for(int i=0;i<max/2;i++)
    {
        depllc(n,109);
        n++;

        for(int j=0;j<max;j++)
        {
            printf("\e[41m  \e[0m");
        }
        printf("\n");
        usleep(50000);
    }

int m=13;
    for(int i=0;i<max/2;i++)
    {
        printf("\t");
        depllc(m,109);
        m++;
        for(int j=0;j<max;j++)
        {
            printf("\e[42m  \e[0m");
        }
        printf("\n");
        usleep(50000);
    }

}
//Pour afficher le petit dialogue
void andry(){
    for(int i=1;i<110;i++)              //Principale boucle d'animation
    {
        //for(int f=0;f<110;f++)
        //{
                for(int c=0;c<159;c++){
                    depllc(1,c);
                    printf("\e[41m \e[0m");
                }
                for(int c=0;c<159;c++){
                    depllc(100,c);
                    printf("\e[42m \e[0m");
                }
                for(int c=0;c<159;c++){
                    depllc(c,0);
                    printf("\e[43m \e[0m");
                }
                for(int c=0;c<159;c++){
                    depllc(c,159);
                    printf("\e[44m \e[0m");
                }

        //}



        depllc(17,2);
        for(int p=0;p<150;p++)
        {
            printf("=");
        }
        for(int e=0;e<150;e++)
        {
               if(e==20 || e==40 || e== 50 || e==80)
                {
                    depllc(16,e);
                    printf(" ||");
                    depllc(15,e);
                    printf(" ||");
                    depllc(14,e);
                    printf(" ||");
                    depllc(13,e);
                    printf("\e[32m{  }\e[0m");
                    depllc(12,e);
                    printf("\e[32m____\e[0m");
                }
                if(e==100)
                {
                    depllc(16,e);
                    printf(" ||");
                    depllc(15,e);
                    printf(" ||");
                    depllc(14,e);
                    printf(" ||");
                    depllc(13,e-1);
                    printf("\e[41;32mIANTSO\e[0m");
                }

        }


        depllc(20,3);
        depllc(14,i);
        printf(" __________");
        depllc(15,i);
        printf("*|\e[46m_______\e[0m |");
        depllc(16,i);
        printf(" 0-------0'");

        for(int j=10;j<17;j++)
        {
            for(int z=10;z<13;z++)
            {
                depllc(j,120);
                printf("\e[45m          \e[0m");
            }
        }

        for(int j=13;j<17;j++)
        {
            for(int z=10;z<13;z++)
            {
                depllc(j,130);
                printf("\e[43m      \e[0m");
            }
        }
        depllc(14,120);
        printf("\e[45;30mIantso ADV\e[0m\e[43;30mENTURE\e[0m");
        if(i==90)
        {
            depllc(20,3);
            printf("Natolotra  : Fa misy ina ndray ry Prezeee ?\n");
            sleep(3);
            depllc(21,3);
            printf("Andry      : Adino lty Faneva !");
            sleep(3);
            depllc(22,3);
            printf("Fandresena : Mbola mianatra mijery dimension ana Matrice lesy izy ah !");
            sleep(3);
        }


        usleep(50000);
        system(cls);
    }
    printf("Veuillez appuyer au clavier ");
    //getch();
}
