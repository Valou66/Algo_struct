#ifndef ALGO_STRUCT_H
#define ALGO_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define INTMAX 2147483647


//--------------------
//-------Arbre--------
//------Binaire-------
//--------------------

typedef struct Noeud_bin{
    int info;
    struct Noeud_bin *g;
    struct Noeud_bin *d;
}Noeud_bin;
typedef Noeud_bin* link_bin;



link_bin creerNoeud_bin(int info);
/*
    creer un noeud
*/



void imprimer_arbre_bin(link_bin r,int niveau);
/*
    afficher l'arbre binaire
*/



link_bin insertion_bin(link_bin racine,int info);
/*
    insert un noeud dans l'arbre
*/

link_bin lookup_rec(link_bin root,int data);
/*
    Algo recursif
    recherche un noeud et retourne le pointeur vers ce noeud (NULL s'il n'existe pas)
*/

link_bin lookup_iter(link_bin root,int data);
/*
    Algo iteratif
    recherche un noeud et retourne le pointeur vers ce noeud (NULL s'il n'existe pas)
*/

int max(int a,int b);
/*
    return max entre a et b
*/

int nb_noeud(link_bin root);
/*
    return le nombre de noeud de l'arbre
*/

int hauteur(link_bin root);
/*
    return la hauteur de l'arbre
*/


link_bin arbre_pe(int n);
//arbre binaire parfaitement equilibré

link_bin bstPE(int t[],int debut ,int fin);
/*
    construire un bstPE de t[debut..fin]
*/

link_bin find_max(link_bin t);
//recherche d'un entier maximum dans un arbre binaire de recherche

link_bin supp_rec(link_bin root,int x);

link_bin supp_iter(link_bin root,int x);

link_bin tournoi(int t[],int g,int d);

void prefixe_bin_rec(link_bin root);
void infixe_bin_rec(link_bin root);
void postfixe_bin_rec(link_bin root);

void prefixe_bin_iter(link_bin root);
void infixe_bin_iter(link_bin root);
void postfixe_bin_iter(link_bin root);

void bfs_bin(link_bin root);


/*
    transforme le tab t[g..d]
    en un tournoi
*/

//--------------------
//-------Arbre--------
//------Binaire-------
//-----Charactère-----
//--------------------

typedef struct Noeud_bin_char{
    char c;
    struct Noeud_bin_char *g;
    struct Noeud_bin_char *d;
}Noeud_bin_char;
typedef Noeud_bin_char* link_bin_char;

link_bin_char creerNoeud_bin_char(char info);

void imprimer_arbre_bin_char(link_bin_char r,int niveau);

link_bin_char parse(char *t,int *i);

link_bin_char parsepost();
/*
    afficher l'arbre binaire
*/

//--------------------
//------Tableau-------
//------de papa-------
//--------------------

void saisie_papa(int n,int papa[]);
int feuilles_arbre(int n,int papa[],int feuille[],int *nf);
int monter_arbre(int f,int papa[]);
int hauteur_arbre(int feuille[],int papa[],int *nf);

//--------------------
//-------Arbre--------
//------General-------
//--------------------

typedef struct Noeud_gen{
    int info;
    struct Noeud_gen *suivant;
}Noeud_gen;
typedef Noeud_gen* link_gen;

Noeud_gen * creer_noeud(int info);
void saisie(Noeud_gen *fils[],int n);
void imprimer_enfants(Noeud_gen *fils[],int n);
void bfs(int i,Noeud_gen *fils[]);
void prefixe(int i,Noeud_gen *fils[]);
void postfixe(int i,Noeud_gen *fils[]);
void infixe(int i,Noeud_gen *fils[]);

//--------------------
//-------File---------
//--------------------

typedef struct File{
    link_bin info;
    struct File *next;
}File;

File* enfiler(File *f,link_bin i);

void defiler(File **f,link_bin *r);

int file_vide(File *f);

void afficher_file(File *f);

struct list{
    link_bin v;
    struct list *N;
};
struct _file{
    struct list *tete,*queue;
};
typedef struct _file file_t;


//--------------------
//-------Pile---------
//--------------------

typedef struct Pile{
    link_bin t[2048];
    int head;
}Pile;

void init_pile(Pile *p);

void empiler(Pile *p,link_bin e);

link_bin depiler(Pile *p);

int pile_vide(Pile *p);

//--------------------
//-------Pile_char---------
//--------------------

typedef struct Pile_char{
    link_bin_char t[2048];
    int head;
}Pile_char;

void init_pile_char(Pile_char *p);

void empiler_char(Pile_char *p,link_bin_char e);

link_bin_char depiler_char(Pile_char *p);

int pile_vide_char(Pile_char *p);


//Autre fonction
int compare(int *a,int *b);
int tester_tas(int tab[],int n);
void monter_tas(int t[],int n,int i,int valeur);

//tri par tas
void descendre_tas(int t[],int n,int i);
void tri_par_tas(int t[],int n);

void print_tab(int t[],int n);
void bfs_bin2(link_bin root);

int* remplir_random(int n);

float eval(int *i,char t[],float alpha[]);

#endif //ALGO_STRUCT_H