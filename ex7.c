//arbre binaire parfaitement equilibré

#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int info;
    struct Noeud *g;
    struct Noeud *d;
}Noeud;
typedef Noeud* link;

link arbre_pe(int n){
    int ng,nd; //ng= nombre de noeud de arbre gauche / nombre de noeud de arbre droit
    link t;
    if(n==0){ //la base
        return NULL;
    }
    ng=n/2;
    nd=n-ng-1;

    // lire un entier x
    int x;
    printf("entre x entier ");
    scanf("%d ",&x);
    //creer un noeud pour stocker;
    t=(link)malloc(sizeof(Noeud));
    /*
          t
        [  ] --> t -> [info]
        [  ]          [g| d]
    */
   t->info=x;
   t->g=arbre_pe(ng);
   t->d=arbre_pe(nd);

   return t;
}

//imprimer l'arbre

void imprimer_arbre(link r,int niveau){
    //imprimer l'arbrea avec indentation niveau
    if(r!=NULL){
        imprimer_arbre(r->d,niveau+1);
        //afficher indentation niveau
        for(int i=0;i<niveau;i++){
            printf("   ");
        }
        printf("%d\n",r->info);
        imprimer_arbre(r->g,niveau+1);
    }
}

//ecrire une fonction pour creer un bst parfaitement equilibre


int main(){
    int n;
    link racine;
    printf("lecture de n ");
    scanf("%d",&n);
    racine=arbre_pe(n);

    printf("\n");
    imprimer_arbre(racine,0);
    return 0;
}
