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

    racine=creerNoeud_bin(50);
    racine->g=creerNoeud_bin(40);
    racine->d=creerNoeud_bin(60);
    racine->g->g=creerNoeud_bin(30);
    racine->g->g->d=creerNoeud_bin(35);
    racine->d->g=creerNoeud_bin(55);
    racine->d->d=creerNoeud_bin(70);


    printf("AVANT \n");
    imprimer_arbre_bin(racine,0);

    racine=supp_rec(racine,30);
    
    printf("APRES\n");
    imprimer_arbre_bin(racine,0);

    printf("PARCOUR\n");
    prefixe_bin_rec(racine);
    printf("\n");
    infixe_bin_rec(racine);
    printf("\n");
    postfixe_bin_rec(racine);
    printf("\n");
}

void td2_ex7(){
    int t[]={10,7,8,11,3,2,1,20,19,12};
    int n=sizeof(t)/sizeof(t[0]);
    link_bin root=tournoi(t,0,n-1);
    imprimer_arbre_bin(root,0);
}

void td2_ex9(){
    link_bin racine = NULL;

    racine=creerNoeud_bin(50);
    racine->g=creerNoeud_bin(40);
    racine->d=creerNoeud_bin(60);
    racine->g->g=creerNoeud_bin(30);
    racine->g->g->d=creerNoeud_bin(35);
    racine->d->g=creerNoeud_bin(55);
    racine->d->d=creerNoeud_bin(70);

    imprimer_arbre_bin(racine,0);

    printf("PARCOUR\n");
    printf("Parcours prefixe recursif : "); 
    prefixe_bin_rec(racine);
    puts("");
    printf("Parcours prefixe iteratif : ");
    prefixe_bin_iter(racine);
    puts("");
    printf("Parcours infixe recursif : ");
    infixe_bin_rec(racine);
    puts("");
    printf("Parcours infixe iteratif : ");
    infixe_bin_iter(racine);
    puts("");
    printf("Parcours postfixe recursif : ");
    postfixe_bin_rec(racine);
    puts("");
    printf("Parcours postfixe iteratif : ");
    postfixe_bin_iter(racine);
}

void td2_ex_bonus(){
    int tab[]={INTMAX,20,18,20,10,12,7,4,9,6,3};
    int n=sizeof(tab)/sizeof(tab[0]);
    printf("%d \n",tester_tas(tab,n));
}

void td3_ex3(){
    int tab[]={INTMAX,20,18,20,10,12,7,4,9,6,3};
    int n=sizeof(tab)/sizeof(tab[0]);
    monter_tas(tab,n,10,27);
    for(int i = 0;i<n;i++){
        printf("%d ",tab[i]);
    }
}

void td3_tri(){
    int tab[]={INTMAX,4,3,1,2,7,3,10,11};
    int n=sizeof(tab)/sizeof(tab[0]);

    print_tab(tab,n);
    for(int i=n/2;i>=1;i--)
        descendre_tas(tab,n,i);
    print_tab(tab,n);
    tri_par_tas(tab,n);
    print_tab(tab,n);


}

void td3_trif(int n){
    int *tab=remplir_random(n);
    tab[0]=INTMAX;
    //print_tab(tab,n);
    for(int i=n/2;i>=1;i--){
        descendre_tas(tab,n,i);
    }
    tri_par_tas(tab,n);
    //print_tab(tab,n);
}

void td3_bfs(){
    link_bin racine = NULL;
    srand(clock());
    int random;
    for(int i=0;i<1000;i++){
        random=rand()%20;
        racine=insertion_bin(racine,random);
    }

    imprimer_arbre_bin(racine,0);

    bfs_bin(racine);
}

void td3_ex10(){
    char *t="++a*bc*+bd+ef+++*";
    int i=0;
    link_bin_char res=parse(t,&i);
    imprimer_arbre_bin_char(res,0);
}

int main(){
    td3_ex10();
    return 0;
}