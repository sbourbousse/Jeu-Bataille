#include "joueur.h"
Joueur::Joueur(string sonNom)
{
	nom=sonNom;
}
Joueur::Joueur()
{
	nom="nobody";
}
void Joueur::ajouteCarte(Carte laCarte)
{
	monJeu.ajoute(laCarte);
}
void Joueur::afficheJeu()
{
	affiche();
	monJeu.affiche();
}
void Joueur::affiche()
{
	cout<<"Hello my name is "<<nom<< " :; I'm glad to meet you :)"<<endl;
}
bool Joueur::nAPlusDeCarte()
{
	return monJeu.empty();
}
Carte Joueur::jouer()
{
	//renvoie la carte du dessus de son ensemble de carte(jeu)
	return monJeu.pop();
}
void Joueur::insereDessous(Carte uneCarte)
{
	monJeu.ajouteDessous(uneCarte);
}
void Joueur::remporter(vector<Carte> lesCartes)
{
	for(int noCarte=0;noCarte<lesCartes.size();noCarte++)
	{
		insereDessous(lesCartes[noCarte]);
	}
}
string Joueur::toString()
{
	return  nom;
}
