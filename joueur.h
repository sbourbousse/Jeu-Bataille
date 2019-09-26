#ifndef JOUEUR
#define JOUEUR

#include "jeu.h"
#include <string>
using namespace std;
class Joueur
{
	private:
		string nom;
		Jeu monJeu;
	public:
		//les constructeurs
		Joueur(string sonNom);
		Joueur();
		void ajouteCarte(Carte laCarte);
		void insereDessous(Carte uneCarte);
		void afficheJeu();
		void affiche();
		bool nAPlusDeCarte();
		Carte jouer();
		void remporter(vector<Carte> lesCartes);
		string toString();
};
#endif
