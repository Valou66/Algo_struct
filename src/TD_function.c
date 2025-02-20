#include "../include/algo_struct.h"

//--------------------
//-------Arbre--------
//------Binaire-------
//--------------------

link_bin creerNoeud_bin(int info){
    link_bin temp=(link_bin)malloc(sizeof(Noeud_bin));
    temp->info=info;
    temp->g=NULL;
    temp->d=NULL;
    return temp;
}

void imprimer_arbre_bin(link_bin r,int niveau){
    //imprimer l'arbrea avec indentation niveau
    if(r!=NULL){
        imprimer_arbre_bin(r->d,niveau+1);
        //afficher indentation niveau
        for(int i=0;i<niveau;i++){
            printf("   ");
        }
        printf("%d\n",r->info);
        imprimer_arbre_bin(r->g,niveau+1);
    }
}

link_bin insertion(link_bin racine,int info){
    if(racine==NULL){
        racine=creerNoeud_bin(info);
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

link_bin lookup_rec(link_bin root,int data){
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
        return lookup_rec(root->d,data);
    }

    if(root->info>data){
        return lookup_rec(root->g,data);
    }
}

link_bin lookup_iter(link_bin root,int data){
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

link_bin bstPE(int t[],int debut ,int fin){
    //construire un bstPEde t[debut..fin]
    //Divide and conquer
    if(debut>fin){
        return NULL;
    }
    int millieu = (debut+fin)/2;
    link_bin racine=creerNoeud_bin(t[millieu]);
    racine->g=bstPE(t,debut,millieu-1);
    racine->d=bstPE(t,millieu+1,fin);
    return racine;
}

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int nb_noeud(link_bin root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1+nb_noeud(root->g)+nb_noeud(root->d);
    }
}

int hauteur(link_bin root){
    if(root == NULL){
        return -1;
    }
    else{
        return 1+max(hauteur(root->g),hauteur(root->d));
    }
}

//--------------------
//-------Arbre--------
//------General-------
//--------------------

//--------------------
//-------File---------
//--------------------

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