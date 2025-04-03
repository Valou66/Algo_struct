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
    Pile p1,p2;
    init_pile(&p1);
    init_pile(&p2);
    link_bin courant;
    empiler(&p1,root);
    while(!pile_vide(&p1)){
        courant=depiler(&p1);
        empiler(&p2,courant);
        if(courant->g!=NULL){
            empiler(&p1,courant->g);
        }
        if(courant->d!=NULL){
            empiler(&p1,courant->d);
        }
    }
    while(!pile_vide(&p2)){
        courant=depiler(&p2);
        printf("%d ",courant->info);
    }
}


//--------------------
//-------Arbre--------
//------Binaire-------
//-----Charactère-----
//--------------------

link_bin_char creerNoeud_bin_char(char c){
    link_bin_char temp=(link_bin_char)malloc(sizeof(Noeud_bin_char));
    temp->c=c;
    temp->g=temp->d=NULL;
    return temp;
}
void imprimer_arbre_bin_char(link_bin_char r,int niveau){
    //imprimer l'arbrea avec indentation niveau
    if(r!=NULL){
        imprimer_arbre_bin_char(r->d,niveau+1);
        //afficher indentation niveau
        for(int i=0;i<niveau;++i){
            printf("   ");
        }
        printf("%c\n",r->c);
        imprimer_arbre_bin_char(r->g,niveau+1);
    }
}
link_bin_char parse(char *t,int *i){
    char c=t[(*i)++];
    link_bin_char p=creerNoeud_bin_char(c);

    if(c=='+' || c=='*'){
        p->g=parse(t,i);
        p->d=parse(t,i);
    }
    return p;
}

link_bin_char parsepost(){
    link_bin_char t;
    char c;
    Pile_char p;
    init_pile_char(&p);
    for(pile_vide_char(&p);scanf("%s",&c)!=EOF;){
        t=creerNoeud_bin_char(c);
        if(c=='+' || c=='*'){
            t->d=depiler_char(&p);
            t->g=depiler_char(&p);
        }
        empiler(&p,t);
        
    }
    return t;
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

File* enfiler(File *f,link_bin i){
    struct File *n=NULL,*t=f;
    n=(struct File*)malloc(sizeof(struct File));
    n->info=i;
    n->next=NULL;

    while(t!=NULL && t->next!=NULL){
        t=t->next;
    }

    if(f!=NULL){
        n->next=t->next;
        t->next=n;
        return f;
    }
    else{
        return n;
    }
}

void defiler(File **f,link_bin *r){
    File *tmp=(*f)->next;
    *r=(*f)->info;
    free(*f);
    *f=tmp;
}

int file_vide(File *f){
    if(f==NULL){
        return 1;
    }
    return 0;
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

void init_pile_char(Pile_char *p){
    p->head=0;
}

void empiler_char(Pile_char *p,link_bin_char e){
    p->t[p->head]=e;
    p->head++;
}

link_bin_char depiler_char(Pile_char *p){
    if(p->head == 0) exit(1);
    return p->t[--p->head];
}

int pile_vide_char(Pile_char *p){
    return p->head==0;
}


//autre fonction
int compare(int *a,int *b){
    return *a - *b;
}


int tester_tas(int tab[],int n){
    //notons que t[(n/2)+1..n]
    for(int i=1; i<n/2; ++i){//si i=0, il se vérifie lui meme
        if(tab[i]<tab[2*i] || tab[i]<tab[2*i+1]){
            return 0;
        }
    }
    //en faite si il y a 10 élement, c'est de 1 à 10, 0 on l'utilise pas car 2*0 = 0 donc c'est """redondant"
    if (n%2 == 0 && tab[n/2]<tab[n]) return 0;
    return 1;
}

void monter_tas(int t[],int n,int i,int valeur){
    // t[1..n] un tas
    // on augment t[i]=t[i]+valeur
    //restructurons en un tas
    //le papa de l'indice i = i/2
    int x=t[i]+valeur;
    int papa;
    while(i>1){
        papa=i/2;
        if(t[papa]>=x) 
            break;
        t[i]=t[papa];
        i=papa;
    }
    t[i]=x;

}

void descendre_tas(int t[],int n,int i){//i<=n/2
    //t[1..n] un tableau d'entiers
    //notons que t[((n/2)+1)..n] sont les feuilles d'arbres pas besoin de descendre
    // depuis les feuilles car elles n'ont pas denfants. ajouter t[i] et descendre_tas
    int x = t[i];
    int j=2*i; // l'enfant gauche
    while(j<n){
        if(j+1<n){
            if(t[j+1]>t[j]){
                j=j+1;//j=l'indice d'enfants + grand
            }
        }
        if(x>=t[j]) 
            break;
        t[i]=t[j];
        i=j;
        j=2*i;
    }
    t[i]=x;
}

void tri_par_tas(int t[],int n){
    int temp;
    int k = n-1;
    for(int i=n-1;i>=1;i--){
        temp=t[i];
        t[i]=t[1];
        t[1]=temp;
        descendre_tas(t,k,1);
        k=k-1;
    }
}

void print_tab(int t[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}
void bfs_bin(link_bin root){
    if(root == NULL) return;
    
    File *s=NULL;
    link_bin x;
    s=enfiler(s,root);

    
    while(file_vide(s)==0){
        defiler(&s,&x);
        printf("%d ",x->info);
        if(x->g!=NULL) s=enfiler(s,x->g);
        if(x->d!=NULL) s=enfiler(s,x->d);
    }
}

int* remplir_random(int n){
    int *res=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        res[i]=rand();
    }
    return res;
}

float eval(int *i,char t[],float alpha[]){
    int negatif;
    if(t[*i]=='#'){
        (*i)=(*i)+1;
    }
    if(t[*i]=='+'){
        (*i)=(*i)+1;
        return eval(i,t,alpha)+eval(i,t,alpha);
    }
    if(t[*i]=='-'){
        (*i)=(*i)+1;
        if(t[*i]=='#'){
            return eval(i,t,alpha)-eval(i,t,alpha);
        }
        else{
            negatif=1;
        }
    }
    if(t[*i]=='*'){
        (*i)=(*i)+1;
        return eval(i,t,alpha)*eval(i,t,alpha);
    }
    if(t[*i]=='/'){
        (*i)=(*i)+1;
        float a=eval(i,t,alpha);
        float b=eval(i,t,alpha);
        if(b!=0){
            return a/b;
        }
    }
    if(t[*i]=='$'){
        (*i)=(*i)+1;
        float a=eval(i,t,alpha);
        float b=eval(i,t,alpha);
        if(b!=0){
            return fmod(a,b);
        }
    }
    if(t[*i]=='^'){
        (*i)=(*i)+1;
        float a=eval(i,t,alpha);
        float b=eval(i,t,alpha);
        if(b==0){
            return 1;
        }
        else if(b>0){
            float s=1;
            for(int j=0;j<b;j++){
                s=s*a;
            }
            return s;
        }
        else{
            float s=1;
            for(int j=0;j<-b;j++){
                s=s*a;
            }
            return 1/s;
        }
    }

    float x=0;

    if(isalpha(t[*i])){
        x=alpha[t[*i]-'a'];
    }
    else{
        while(t[*i]>='0' && t[*i]<='9'){
            x=10*x+(t[*i]-'0');
            (*i)=(*i)+1;
        }
        if(t[*i]=='.'){
            float p=1;
            while(t[*i]>='0' && t[*i]<='9'){
                x=x+(t[*i]-'0')*(p*1/10);
                (*i)=(*i)+1;
                p=p*1/10;
            }
        }
    }
    if(negatif==1)return -x;
    return x;
}