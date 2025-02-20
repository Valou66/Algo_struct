#include "../include/algo_struct.h"
void tb_papa(){
    printf("TABLEAU DE PAPA\n");

    int n;
    int papa[20],feuille[20];
    int nf;

    printf("entre n l'entier \n");
    scanf("%d",&n); //12
    saisie_papa(n,papa);
    nf=feuilles_arbre(n,papa,feuille,&nf);
    printf("le nombre de feuille de l'arbre est %d \n",nf);
    int h=hauteur_arbre(feuille,papa,&nf);
    printf("la hauteur de l'arbre est : %d \n",h);

    //affichage feuille
    printf("voici les feuilles");
    for(int i=0;i<nf;i++){
        printf("%d ",feuille[i]);
    }
    printf("\n");
}

void arbre_binaire(){
    printf("ARBRE BINAIRE \n");
    printf("ex 2 ,3,4,5 \n");
    link_bin racine=NULL;
    racine=insertion_bin(racine,1);
    racine=insertion_bin(racine,2);
    racine=insertion_bin(racine,3);
    racine=insertion_bin(racine,6);
    racine=insertion_bin(racine,7);
    racine=insertion_bin(racine,5);
    racine=insertion_bin(racine,54);
    racine=insertion_bin(racine,11);
    racine=insertion_bin(racine,45);
    racine=insertion_bin(racine,64);
    racine=insertion_bin(racine,17);
    

    imprimer_arbre_bin(racine,0);

    printf("T %d \n",lookup_rec(racine,3)->info);
    printf("T %d \n",lookup_iter(racine,3)->info);
    printf("nb_noeud %d \n",nb_noeud(racine));
    printf("hauteur:%d \n",hauteur(racine));
}

void td1_ex4(){

    Noeud_gen *fils[15];
    int n=9;
    saisie(fils,n);
    imprimer_enfants(fils,n);
    printf("\n");
    prefixe(0,fils);
    printf("\n");
    printf("\n");
    infixe(0,fils);
    printf("\n");
    printf("\n");
    postfixe(0,fils);
}

void td1_ex7(){
    int n;
    link_bin racine;
    printf("lecture de n ");
    scanf("%d",&n);
    racine=arbre_pe(n);

    printf("\n");
    imprimer_arbre_bin(racine,0);
}

void td1_ex7bis(){
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
    link_bin racine=bstPE(t,0,n-1);

    imprimer_arbre_bin(racine,0);

}

void td1_ex8(){
    int x;
    link_bin racine=NULL;

    printf("entre\n");
    while(scanf("%d",&x)!=EOF){
        racine=insertion_bin(racine,x);
    }

    imprimer_arbre_bin(racine,0);
}

void td2_ex5bis(){
    link_bin racine=NULL;

    printf("entre\n");
    
    racine =insertion_bin(racine,8);
    racine =insertion_bin(racine,6);
    racine =insertion_bin(racine,15);
    racine =insertion_bin(racine,4);
    racine =insertion_bin(racine,7);
    racine =insertion_bin(racine,14);
    racine =insertion_bin(racine,17);
    racine =insertion_bin(racine,2);
    racine =insertion_bin(racine,5);
    racine =insertion_bin(racine,10);
    racine =insertion_bin(racine,16);
    racine =insertion_bin(racine,18);
    racine =insertion_bin(racine,1);
    racine =insertion_bin(racine,3);
    racine =insertion_bin(racine,9);
    racine =insertion_bin(racine,12);
    racine =insertion_bin(racine,11);
    racine =insertion_bin(racine,13);

    imprimer_arbre_bin(racine,0);
    printf("\nmax=%d \n",find_max(racine)->info);
}

int main(){
    td2_ex5bis();

    

    
}