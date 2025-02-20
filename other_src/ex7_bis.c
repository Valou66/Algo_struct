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

lien bstPE(int t[],int debut ,int fin){
    //construire un bstPEde t[debut..fin]
    //Divide and conquer
    if(debut>fin){
        return NULL;
    }
    int millieu = (debut+fin)/2;
    lien racine=creerNoeud(t[millieu]);
    racine->g=bstPE(t,debut,millieu-1);
    racine->d=bstPE(t,millieu+1,fin);
    return racine;
}

//                          la fonction de comparaison                          
//                                   ^
//                                   |
//qsort(t,taille_du_t,sizeof(int),compare)

//ecrivions la fonction de comparaison

int compare(int *a,int *b){
    return *a - *b;
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

int main(){
    int n; // le nombre d'entier
    printf("entre n \n");
    scanf("%d",&n);

    int t[n];
    //saisie du tab
    for(int i=0;i<n;i++){
        printf("entre entier numero %d\n",i+1);
        scanf("%d",&t[i]);
    }
    qsort(t,n,sizeof(int),compare);
    lien racine=bstPE(t,0,n-1);

    imprimer_arbre(racine,0);

    


    return 0;
}
