#include "../include/algo_struct.h"

int main(){
    link_bin racine=NULL;
    racine=insertion(racine,1);
    racine=insertion(racine,2);
    racine=insertion(racine,3);
    racine=insertion(racine,6);
    racine=insertion(racine,7);
    racine=insertion(racine,5);
    racine=insertion(racine,54);
    racine=insertion(racine,11);
    racine=insertion(racine,45);
    racine=insertion(racine,64);
    racine=insertion(racine,17);
    

    imprimer_arbre_bin(racine,0);

    printf("T %d \n",lookup_iter(racine,3)->info);
    printf("nb_noeud %d \n",nb_noeud(racine));
    printf("hauteur:%d \n",hauteur(racine));
}