#include <stdio.h>
#include <stdlib.h>

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