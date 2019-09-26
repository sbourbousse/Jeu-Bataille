#ifndef JEU
#define JEU

#include "carte.h"
#include <vector>
#include <iostream>

class Jeu
{
	private:
		vector<Carte> vectCarte;
	public:
		void init();
		void affiche();
		void melange();
		void ajoute(Carte uneCarte);
		bool empty();
		Carte pop();//renvoie la carte du dessus en la retirant du vecteur
		void ajouteDessous(Carte uneCarte);
};
#endif
