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

link lookup_iter(link root,int data){
    while(root != NULL){
        if(root->info==data){
            return root;
        }
        if(root->info<data){
            root=root->d;
        }
        else{
            root=root->g;
        }
    }
    return NULL;
}

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int nb_noeud(link root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1+nb_noeud(root->g)+nb_noeud(root->d);
    }
}

int hauteur(link root){
    if(root == NULL){
        return -1;
    }
    else{
        return 1+max(hauteur(root->g),hauteur(root->d));
    }
}



int main(){
    int x;
    link racine=NULL;
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
    

    imprimer_arbre(racine,0);

    printf("T %d \n",lookup_iter(racine,3)->info);
    printf("nb_noeud %d \n",nb_noeud(racine));
    printf("hauteur:%d \n",hauteur(racine));
    return 0;
}


