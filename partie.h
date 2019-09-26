#ifndef PARTIE
#define PARTIE

#include "jeu.h"
#include "joueur.h"

class Partie
{
	private:
		Jeu jeuComplet;
		vector <Joueur> vectJoueur;
		
	public:
		Partie();
		void distribuer();
		void jouer();
		bool partieTerminee();
		void tour();
};
#endif
