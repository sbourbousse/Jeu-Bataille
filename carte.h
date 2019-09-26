#ifndef CARTE
#define CARTE

#include <string>
using namespace std;
class Carte
{
	private:
		string nom;
		string couleur;
		int valeur;
	public:
		Carte(string leNom,string laCouleur,int laValeur);
		Carte();
		void affiche();
		bool superieur(Carte autreCarte);
		bool egal(Carte autreCarte);
		int getValeur();
		string toString();
};
#endif
