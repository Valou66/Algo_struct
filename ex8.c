#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int info;
    struct Noeud *g;
    struct Noeud *d;
}Noeud;
typedef Noeud* lien;

lien creerNoeud(int info){
    lien temp=(lien)malloc(sizeof(Noeud));
    temp->info=info;
    temp->g=NULL;
    temp->d=NULL;
    return temp;
}

void imprimer_arbre(lien r,int niveau){
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

//construire un BST en lisant
//les entier un par un depuis le clavier
lien insertion(lien racine,int info){
    if(racine==NULL){
        racine=creerNoeud(info);
    }
    else{
        if(info < racine->info){
            racine->g=insertion(racine->g,info);
        }
        else if(info>racine->info){
            racine->d=insertion(racine->d,info);
        } // les entier egaux inserer
    }
    return racine;
}

int main(){
    int x;
    lien racine=NULL;
    while(scanf("%d",&x)!=EOF){
        racine=insertion(racine,x);
    }

    imprimer_arbre(racine,0);
    return 0;
}