#ifndef ALGO_STRUCT_H
#define ALGO_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    int info;
    struct File *next;
}File;

File* enfiler(File *f,int i);

File* defiler(File *f ,int *r);

int file_vide(File *f);

void afficher_file(File *f);

//Autre fonction
int compare(int *a,int *b);
#endif //ALGO_STRUCT_H