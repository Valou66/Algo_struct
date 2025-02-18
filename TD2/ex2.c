#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int info;
    struct Noeud *g;
    struct Noeud *d;
}Noeud;
typedef Noeud* link;

link creerNoeud(int info){
    link temp=(link)malloc(sizeof(Noeud));
    temp->info=info;
    temp->g=NULL;
    temp->d=NULL;
    return temp;
}

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

link insertion(link racine,int info){
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

link lookup(link root,int data){
    /*
    lookup retourne un pointeur d'un noeud 
    contenant x s'il exister, NULL sinon
    */
    
    //La Base de la reccurence
    if(root == NULL){
        return NULL;
    }

    if(root->info == data){
        return root;
    }

    if(root->info<data){
        return lookup(root->d,data);
    }

    if(root->info>data){
        return lookup(root->g,data);
    }


}

int main(){
    int x;
    link racine=NULL;
    while(scanf("%d",&x)!=EOF){
        racine=insertion(racine,x);
    }

    imprimer_arbre(racine,0);

    printf("T %d",lookup(racine,64)->info);
    return 0;
}


