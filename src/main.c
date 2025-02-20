#include "../include/algo_struct.h"

int main(){

    printf("TABLEAU DE PAPA\n");

    int n;
    int papa[20],feuille[20];
    int nf;

    printf("entre n l'entier \n");
    scanf("%d",&n); //12
    saisie_papa(n,papa);
    nf=feuilles_arbre(n,papa,feuille,&nf);
    printf("le nombre de feuille de l'arbre est %d \n",nf);
    int h=hauteur_arbre(feuille,papa,&nf);
    printf("la hauteur de l'arbre est : %d \n",h);

    //affichage feuille
    printf("voici les feuilles");
    for(int i=0;i<nf;i++){
        printf("%d ",feuille[i]);
    }
    printf("\n");


    printf("ARBRE BINAIRE \n");
    link_bin racine=NULL;
    racine=insertion_bin(racine,1);
    racine=insertion_bin(racine,2);
    racine=insertion_bin(racine,3);
    racine=insertion_bin(racine,6);
    racine=insertion_bin(racine,7);
    racine=insertion_bin(racine,5);
    racine=insertion_bin(racine,54);
    racine=insertion_bin(racine,11);
    racine=insertion_bin(racine,45);
    racine=insertion_bin(racine,64);
    racine=insertion_bin(racine,17);
    

    imprimer_arbre_bin(racine,0);

    printf("T %d \n",lookup_iter(racine,3)->info);
    printf("nb_noeud %d \n",nb_noeud(racine));
    printf("hauteur:%d \n",hauteur(racine));

    
}