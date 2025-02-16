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


//ecrire une fonction permettant
typedef struct File{
    int info;
    struct File *next;
}File;

File* enfiler(File *f,int i){
    File *tmp;
    if(f==NULL){
        f=(File*)malloc(sizeof(File));
        f->info=i;
        f->next=NULL;
    }
    else{
        tmp=f;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=(File*)malloc(sizeof(File));
        tmp->next->info=i;
    }
    return f;
}

File* defiler(File *f ,int *r){ // *r est un pointeur vers une variable pour stocker defiler
    *r=f->info;
    File *tmp=f;
    tmp=tmp->next;
    free(f);
    return tmp;
}

int file_vide(File *f){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void afficher_file(File *f){
    File *aff=f;

    while(aff!=NULL){
        printf("%d ",aff->info);
        aff=aff->next;
    }
    printf("\n");
}

int main(){
    
    File *test=NULL;

    for(int i=0;i<15;i++)
        test=enfiler(test,i);
    
    afficher_file(test);

    int res;
    while(!file_vide(test)){
        test=defiler(test,&res);
        printf("%d ",res);
    }

    


    //saisie();
    //imprimer_enfants();
    
}