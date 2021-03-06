/**
       @brief Fichier C pour Table


       gere la table du jeu

       @author Tristan James
       @file Table.C
       @version 1.1
       @date 2008/04/11
*/


#include "MainCarte.h"
#include "PileCarte.h"
#include "Joueur.h"
#include "Table.h"
#include <stdlib.h>
#include <stdio.h>

/*
struct Table
{
	int nJoueur;
	Joueur** joueur;
	int nMaxJoueur;
	MainCarte* carteDecouverte;
	PileCarte* pileCarte;
	int positionDealer;
	int petiteBlind;
};
*/


void reinitialisationMainJoueurTable(Table & t)
{
    for (int i=0;i<getMaxJoueurTable(t);i++)
    {
        if (t.joueur[i]!=NULL)
        {
            reinitialisationMainJoueur(*getIemeJoueur(t,i));
        }
    }

}

void initTable (Table & table)
{
    table.nJoueur = 0;
    setMaxJoueurTable(table,0);
    table.joueur = new Joueur*[10];
    memset(table.joueur,0,sizeof(*table.joueur)*10);

    table.carteDecouverte=new MainCarte;
    initialisationMain(*(table).carteDecouverte);

    table.pileCarte = NULL;
    table.positionDealer = 0;
    table.petiteBlind = 0;
    table.pot=0;

}

int getTablePot(const Table & t)
{
    return t.pot;
}
void setTablePot(Table & t,int n)
{
    t.pot=n;
}


Table* creeTable()
{
    Table* t = new Table;
    initTable(*t);
    return t;
}


void tableLibere(Table & table)
{
    delete[] table.joueur;
//      table.joueur = NULL;
    delete table.carteDecouverte;
    table.carteDecouverte = NULL;
    table.pileCarte = NULL;
}


void tableDetruit(Table* & table)
{
    tableLibere(*table);
    delete table;
    table = NULL;
}


void ajoutJoueurTable (Table & table,Joueur* joueur)
{
//      assert(getNJoueurTable(table)  < getMaxJoueurTable(table));
    int i =0;
    while (table.joueur[i] != NULL)
    {
        i++;
    }
    table.joueur[i] = joueur;
    setNJoueurTable(table,getNJoueurTable(table)+1);
    setIdJoueur(*joueur,i);
    setStatutJoueur(*joueur,SIT);
}


void supprimeJoueurTable (Table & table,Joueur* joueur)
{

    setNJoueurTable(table,getNJoueurTable(table)-1);
    table.joueur[joueur->idJoueur]=NULL;
    setIdJoueur(*joueur,-1);
    setStatutJoueur(*joueur,SIT_OUT);
}


void setMaxJoueurTable (Table & table, int n)
{
//      assert(n<=10&&n>0&&n>table.nJoueur);

    table.nMaxJoueur = n;
}


int getMaxJoueurTable (const Table & table)
{
    return table.nMaxJoueur;
}


PileCarte* getTablePileCarteTable(const Table & table)
{
    return table.pileCarte;
}

void setNJoueurTable (Table & table, int n)
{
//      assert(n<=10 && n>=0 && n <= getMaxJoueur(table));
    table.nJoueur=n;
}


int getNJoueurTable (const Table & table)
{
    return table.nJoueur;
}

int placeVide (const Table & table)
{
    int i=0;
    for (i=0;i<table.nJoueur;i++)
    {
        if (table.joueur[i] != 0)
            return i;
    }
    return -1;

}


void changeDealerTable(Table & table)
{
    bool continuer=true;
    while (continuer)
    {
        printf("cest la\n");
        table.positionDealer++;
        if (table.positionDealer >= getNJoueurTable(table))
            table.positionDealer =0;
        if(getIemeJoueur(table,getPositionDealerTable(table))!=NULL)
        {
            if(getStatutJoueur(*getIemeJoueur(table,getPositionDealerTable(table)))!=SIT_OUT)
            {
                continuer = false;
            }
        }

    }
}


Joueur* getIemeJoueur(const Table & table,int n)
{
    return table.joueur [n];
}


MainCarte* getMainCarteTable (const Table & table)
{
    return table.carteDecouverte;
}


void setPetiteBlindTable (Table & table, int n)
{
//    assert(n>0 && n<99999);
    table.petiteBlind = n;
}



int getPetiteBlindTable (const Table & table)
{
    return table.petiteBlind;
}



int getJoueurSuivant(const Table & table,int i)
{
    i++;
    if (i >= getMaxJoueurTable(table))
        i =0;
    while (table.joueur[i] == NULL && (*table.joueur[i]).statut == SIT_OUT)
    {
        i++;
        if (i >= getMaxJoueurTable(table))
            i =0;
    }
    return i;
}



int getPositionDealerTable(const Table & table)
{
    return table.positionDealer;
}
