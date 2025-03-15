#ifndef ALGO_STRUCT_H
#define ALGO_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
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

File* defiler(File *f ,link_bin i);

int file_vide(File *f);

void afficher_file(File *f);

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



//Autre fonction
int compare(int *a,int *b);
int tester_tas(int tab[],int n);
void monter_tas(int t[],int n,int i,int valeur);

//tri par tas
void descendre_tas(int t[],int n,int i);
void tri_par_tas(int t[],int n);

void print_tab(int t[],int n);

#endif //ALGO_STRUCT_H