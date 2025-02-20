#include "../include/algo_struct.h"

int main(){
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