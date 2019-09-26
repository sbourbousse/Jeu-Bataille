#include "carte.h"
#include <iostream>
using namespace std;

//deux constructeurs
Carte::Carte()
{
}

Carte::Carte(string leNom,string laCouleur, int laValeur)
{
	nom=leNom;
	couleur=laCouleur;
	valeur=laValeur;
}

//affiche la carte
void Carte::affiche()
{
  cout<<"*       "<<nom<<"  de "<<couleur<<endl;
}

bool Carte::superieur(Carte autreCarte)
{
	return valeur>autreCarte.valeur;
}

bool Carte::egal(Carte autreCarte)
{
	return valeur==autreCarte.valeur;
}
int Carte::getValeur()
{
	return valeur;
}
string Carte::toString()
{
	return nom+" de "+couleur;
}
