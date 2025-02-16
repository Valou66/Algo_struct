#include <stdio.h>
#include <stdlib.h>
#define MAX_NOEUDS 15
//definition d'un noeud
typedef struct Noeud{
    int info;
    struct Noeud *suivant;
}Noeud;
typedef Noeud* link;
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

File* defiler(File *f ,int *r){ // *r est un pointeur vers une variable pour stocker la valeur defiler
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

typedef struct noeud_f{
    int info;
    struct noeud_f *next;
}noeud_f;

noeud_f *head,*tail;

void init(){
    head=NULL;
}

int empty(){
    return head==NULL;
}

int dequeue(){
    //Tester s;
    //file est vide
    if(!(empty())){
        int x=head->info;
        head=head->next;
        return x;
    }
    else{// file vide
        printf("file vide");
        exit(1);
    }
}

void enqueue(int x){
    noeud_f *t=(noeud_f*)malloc(sizeof(noeud_f));
    t->info=x;
    t->next=NULL;
    if(empty()){
        head=t;
        tail=t;
    }
    else{
        tail->next=t;
        tail=t;
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


void bfs(int i){
    //lister les noeud de t dans l'ordre bfs
    //A est representer par la listes de ses enfants
    int L[n];
    int j;
    enqueue(i);
    while(!empty()){
        j=dequeue();
        //enfiler tout les enfants de j
        for(link t = fils[j];t!=NULL;t=t->suivant){
            enqueue(t->info);
            L[t->info]=L[j]+1; // niveau d'un noeud = niveau de son papa +1
        }
    }
    for(int ii=0;ii<n;ii++){
        printf("voici les noeud au niveau %d:",ii);
        for(int jj=0;jj<n;jj++){
            if(L[jj]==ii)
                printf("%d ",jj);
        }
        printf("\n");
    }
    //affichage des noeud selon niveau

    
}

int main(){
    
    n=9;
    saisie();
    imprimer_enfants();
    printf("\n");

    bfs(0);
    
    return 0;
}