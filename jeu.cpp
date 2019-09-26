#include "jeu.h"
#include<string>
#include <cstdlib>
using namespace std;

/**
 * initialise le jeu avec 32 cartes
 */
void Jeu::init()
{
	//pour les 4 couleurs
	string tabCoul[4]={"coeur","carreau","trêfle","pique"};
	string tabNom[8]={"7","8","9","Valet","Dame","Roi","10","As"};
	//pour chaque couleur
	for(int couleur=0;couleur<4;couleur++)
	{
		//pour chaque nature de carte
		for(int valeur=0;valeur<8;valeur++)
		{
			//on ajoute la carte au jeu
			vectCarte.push_back(Carte(tabNom[valeur],tabCoul[couleur],valeur));
		}
	}
}
void Jeu::ajouteDessous(Carte uneCarte)
{
	cout<<"void Jeu::ajouteDessous(Carte uneCarte)"<<endl;
	vectCarte.insert(vectCarte.begin(),uneCarte);
}

void Jeu::affiche()
{
	cout<<"***********************************************"<<endl;
	for (int noCarte=0;noCarte<vectCarte.size();noCarte++)
	{
		vectCarte[noCarte].affiche();
	}
}
void Jeu::melange()
{
	//125 permutations on verra bien ce que ça donne
	for(int noPermutation=0;noPermutation<1200;noPermutation++)
	{	  
		//je tire deux numéros au hazard
		int noCarte1=rand()%32;
		int noCarte2=rand()%32;
		//je permute les deux cartes
		Carte temporaire=vectCarte[noCarte1];
		vectCarte[noCarte1]=vectCarte[noCarte2];
		vectCarte[noCarte2]=temporaire;
	}
}
void Jeu::ajoute(Carte laCarte)
{
	vectCarte.push_back(laCarte);
}

bool Jeu::empty()
{
  return(vectCarte.size()==0);
}
Carte Jeu::pop()
{
	Carte laCarte=vectCarte.back();
	//supression de la dernière carte
	vectCarte.pop_back();
	return laCarte;
}
