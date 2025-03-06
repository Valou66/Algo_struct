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

link_bin insertion_bin(link_bin racine,int info){
    if(racine==NULL){
        racine=creerNoeud_bin(info);
    }
    else{
        if(info < racine->info){
            racine->g=insertion_bin(racine->g,info);
        }
        else if(info>racine->info){
            racine->d=insertion_bin(racine->d,info);
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

link_bin arbre_pe(int n){
    int ng,nd; //ng= nombre de noeud de arbre gauche / nombre de noeud de arbre droit
    link_bin t;
    if(n==0){ //la base
        return NULL;
    }
    ng=n/2;
    nd=n-ng-1;

    // lire un entier x
    int x;
    printf("entre x entier ");
    scanf("%d ",&x);
    //creer un noeud pour stocker;
    t=(link_bin)malloc(sizeof(Noeud_bin));
    /*
          t
        [  ] --> t -> [info]
        [  ]          [g| d]
    */
   t->info=x;
   t->g=arbre_pe(ng);
   t->d=arbre_pe(nd);

   return t;
}

link_bin find_max(link_bin t){
    //recherche l'element maximum dans un arbre binaire de recherche
    link_bin temp=t;

    if(t!=NULL){
        while(temp->d != NULL){
            temp=temp->d;
        }
        return temp;
    }
    else{
        return NULL;
    }
}

link_bin supp_rec(link_bin root,int x){
    if(root != NULL){
        if(x<root->info){
            //recursion dans l'arbre gauche
            root->g=supp_rec(root->g,x);
        }

        else if(x>root->info){
            //recursion dans l'arbre droit
            root->d=supp_rec(root->d,x);
        }

        else{
            // on a trouver le bon noeud
            if(root->g == NULL){
                link_bin temp=root->d;
                free(root);
                return temp;
            }

            else if(root->d == NULL){
                link_bin temp=root->g;
                free(root);
                return temp;
            }

            else{
                //le noeud a 2 enfant

                link_bin temp=find_max(root->g);
                //temp pointe vers le noeud maximum de l'arbre gauche de root

                root->info=temp->info;
                /*
                copie le contenue de temp dans root
                Notons que temps a au moins enfants ce cas est déjà considéré
                */

                root->g= supp_rec(root->g,temp->info);
            }

            return root;
        }
    }
    else{
        return NULL;
    }
}

link_bin tournoi(int t[],int g,int d){
    int m =(g+d)/2;
    link_bin p=creerNoeud_bin(t[m]);
    if(g==d){
        return p; // la base
    }
    p->g=tournoi(t,g,m);
    p->d=tournoi(t,m+1,d);
    int u = p->g->info;
    int v = p->d->info;
    if(u>v){
        p->info=u;
    }
    else{
        p->info=v;
    }
    return p;
}

void prefixe_bin_rec(link_bin root){
    if(root!=NULL){
        printf("%d ",root->info);
        prefixe_bin_rec(root->g);
        prefixe_bin_rec(root->d);
    }
}

void prefixe_bin_iter(link_bin root){
    if(root == NULL) return;
    Pile p;
    link_bin courant;
    init_pile(&p);
    courant=root;
    if(courant!=NULL){
        empiler(&p,courant);
    }
    
    while(!pile_vide(&p)){
        courant=depiler(&p);

        printf("%d ",courant->info);
        if(courant->d!=NULL){
            empiler(&p,courant->d);
        }
        if(courant->g!=NULL){
            empiler(&p,courant->g);
        }
    }
}

void infixe_bin_rec(link_bin root){
    if(root!=NULL){
        infixe_bin_rec(root->g);
        printf("%d ",root->info);
        infixe_bin_rec(root->d);
    }
}

void infixe_bin_iter(link_bin root){
    if(root == NULL) return;
    Pile p;
    link_bin courant=root;
    init_pile(&p);

    while(courant!=NULL || !pile_vide(&p)){
        while(courant!=NULL){
            empiler(&p,courant);
            courant=courant->g;
        }
        courant=depiler(&p);
        printf("%d ",courant->info);
        courant=courant->d;
    }
    
    
    
}

void postfixe_bin_rec(link_bin root){
    if(root!=NULL){
        postfixe_bin_rec(root->g);
        postfixe_bin_rec(root->d);
        printf("%d ",root->info);
    }
}

void postfixe_bin_iter(link_bin root){
    if(root == NULL) return;
    Pile p;
    link_bin courant;
    init_pile(&p);
    courant=root;
    if(courant!=NULL){
        empiler(&p,courant);
    }
    
    while(!pile_vide(&p)){
        courant=depiler(&p);
        if(courant->d!=NULL){
            empiler(&p,courant->d);
        }
        if(courant->g!=NULL){
            empiler(&p,courant->g);
        }
        printf("%d ",courant->info);
    }
}
//--------------------
//------Tableau-------
//------de papa-------
//--------------------

void saisie_papa(int n,int papa[]){
    for(int i=0;i<n;i++){
        printf("entre papa de %d \n",i);
        scanf("%d",&papa[i]);
    }
}

int feuilles_arbre(int n,int papa[],int feuille[],int *nf){
    *nf=0; //initialisation de nf
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
            feuille[*nf]=i;
            (*nf)=(*nf)+1;
        }
    }
    return *nf;
}

int monter_arbre(int f,int papa[]){
    //f une feuille  monter de f jusqu'a racine
    int h=0;
    while(f!=0){
        f=papa[f];
        h++;
    }
    return h;
}

int hauteur_arbre(int feuille[],int papa[],int *nf){
    //utilisions le tableau feuille
    int h=0;
    int p;
    // parcourir le tableau feuille
    for(int i=0;i<*nf;i++){
        p=monter_arbre(feuille[i],papa);
        if(p>h){
            h=p;
        }
    }
    return h;
}


//--------------------
//-------Arbre--------
//------General-------
//--------------------

Noeud_gen * creer_noeud(int info){
    Noeud_gen *temp=(Noeud_gen*)malloc(sizeof(Noeud_gen));//effet = temp est un pointeur vers le Noeud
    temp->info=info;
    temp->suivant=NULL;
    return temp;
}

void saisie(Noeud_gen *fils[],int n){
    Noeud_gen *t;
    Noeud_gen *temp;
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

void imprimer_enfants(Noeud_gen *fils[],int n){
    Noeud_gen *temp;
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

void prefixe(int i,Noeud_gen *fils[]){
    printf("%d ",i);
    //parcourir la liste de fils de i
    //c'est a dire fils[i]
    for(Noeud_gen *temp=fils[i];temp!=NULL;temp=temp->suivant){
        prefixe(temp->info,fils);
    }
}

void postfixe(int i,Noeud_gen *fils[]){
    //parcourir la liste de fils de i
    //c'est a dire fils[i]
    for(Noeud_gen *temp=fils[i];temp!=NULL;temp=temp->suivant){
        postfixe(temp->info,fils);
    }
    printf("%d ",i);
}

void infixe(int i,Noeud_gen *fils[]){
    //parcour infixe de l'arbre de racine i
    if(fils[i]==NULL){
        printf("%d ",i);
    }
    int j=0;
    for(Noeud_gen *temp=fils[i];temp!=NULL;temp=temp->suivant){
        if(j==1){
            printf("%d ",i);
        }
        infixe(temp->info,fils);
        j++;
    }
    
}

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

//--------------------
//-------Pile---------
//--------------------

void init_pile(Pile *p){
    p->head=0;
}

void empiler(Pile *p,link_bin e){
    p->t[p->head]=e;
    p->head++;
}

link_bin depiler(Pile *p){
    if(p->head == 0) exit(1);
    return p->t[--p->head];
}

int pile_vide(Pile *p){
    return p->head==0;
}

//autre fonction
int compare(int *a,int *b){
    return *a - *b;
}