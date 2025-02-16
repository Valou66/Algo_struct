#include <stdio.h>
#define MAX_NOEUDS 20

int papa[MAX_NOEUDS],feuille[MAX_NOEUDS];
int n,nf;//n<=max_noeuds

//saisie d'un arbre par le tableau de papa

void saisie(int n){
    for(int i=0;i<n;i++){
        printf("entre papa de %d \n",i);
        scanf("%d",&papa[i]);
    }
}

int feuilles_arbre(int n){
    nf=0; //initialisation de nf
    int est_feuille;
    int j;
    for(int i=0;i<n;i++){
        //tester si i est une feuille 
        est_feuille=1;
        j=0;
        while(j<n && est_feuille==1){
            //tester si i est present
            if(papa[j]==i){
                est_feuille=0;
            }
            j++;
        }
        if(est_feuille==1){
            feuille[nf]=i;
            nf=nf+1;
        }
    }
    return nf;
}

int monter_arbre(int f){
    //f une feuille  monter de f jusqu'a racine
    int h=0;
    while(f!=0){
        f=papa[f];
        h++;
    }
    return h;
}

int hauteur_arbre(){
    //utilisions le tableau feuille
    int h=0;
    int p;
    // parcourir le tableau feuille
    for(int i=0;i<nf;i++){
        p=monter_arbre(feuille[i]);
        if(p>h){
            h=p;
        }
    }
    return h;
}



int main(){
    //lecture de n
    printf("entre n l'entier \n");
    scanf("%d",&n); //12
    saisie(n);
    nf=feuilles_arbre(n);
    printf("le nombre de feuille de l'arbre est %d \n",nf);
    int h=hauteur_arbre();
    printf("la hauteur de l'arbre est : %d \n",h);

    //affichage feuille
    printf("voici les feuilles");
    for(int i=0;i<nf;i++){
        printf("%d ",feuille[i]);
    }

    
    return 0;
}