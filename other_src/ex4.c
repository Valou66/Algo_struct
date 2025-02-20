#include <stdio.h>
#include <stdlib.h>
#define MAX_NOEUDS 15
//definition d'un noeud
typedef struct Noeud{
    int info;
    struct Noeud *suivant;
}Noeud;
// info  suivant
// [    |       ]

Noeud *fils[MAX_NOEUDS];
int n;//le nombre actuel de noeud
//crees un noeud avec info donnée

Noeud * creer_noeud(int info){
    Noeud *temp=(Noeud*)malloc(sizeof(Noeud));//effet = temp est un pointeur vers le Noeud
    temp->info=info;
    temp->suivant=NULL;
    return temp;
}

void saisie(){
    Noeud *t;
    Noeud *temp;
    //initialisation de tableau fils

    for(int i=0;i<n;i++){
        fils[i]=NULL;
    }
    //saisie des enfant de chaque noeud
    int ne,e; //nombre d'enfant et enfant
    for(int i=0;i<n;i++){
        printf("entre nb enfant de %d \n",i);
        scanf("%d",&ne);
        for(int j=0;j<ne;j++){
            //les enfants sont entrès dans l'ordre inverse
            printf("entres l-enfant %d \n",j+1);
            scanf("%d",&e);
            //creer un noeud pour stocker e
            temp=creer_noeud(e);
            //attacher terme a la tête de fils[j]
            temp->suivant=fils[i];
            fils[i]=temp;
        }
    }
}

void imprimer_enfants(){
    Noeud *temp;
    for(int i=0;i<n;i++){
        temp=fils[i];
        if(temp==NULL){
            printf("pas d'enfant de %d \n",i);
        }
        else{
            for(;temp!=NULL;temp=temp->suivant){
                printf("%d  ",temp->info);
            }
            printf("\n");
        }
    }
}

void prefixe(int i){
    printf("%d ",i);
    //parcourir la liste de fils de i
    //c'est a dire fils[i]
    for(Noeud *temp=fils[i];temp!=NULL;temp=temp->suivant){
        prefixe(temp->info);
    }
}

void postfixe(int i){
    //parcourir la liste de fils de i
    //c'est a dire fils[i]
    for(Noeud *temp=fils[i];temp!=NULL;temp=temp->suivant){
        postfixe(temp->info);
    }
    printf("%d ",i);
}

void infixe(int i){
    //parcour infixe de l'arbre de racine i
    if(fils[i]==NULL){
        printf("%d ",i);
    }
    int j=0;
    for(Noeud *temp=fils[i];temp!=NULL;temp=temp->suivant){
        if(j==1){
            printf("%d ",i);
        }
        infixe(temp->info);
        j++;
    }
    
}
int main(){
    
    n=9;
    saisie();
    imprimer_enfants();
    printf("\n");
    prefixe(0);
    printf("\n");
    printf("\n");
    infixe(0);
    printf("\n");
    printf("\n");
    postfixe(0);
    return 0;
}