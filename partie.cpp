#include "partie.h"
#include <cstdlib>
#include <time.h>  
Partie::Partie()
{
	//intitialisation de générateur de nombre aléatoire
	srand (time(NULL));

	//intitialisation du jeu avec 32 cartes
	jeuComplet.init();
	//test
	jeuComplet.affiche();
	//mélange
	jeuComplet.melange();
	//test
	jeuComplet.affiche();
	//création de deux joueurs
	//le premier
	cout<<"Tapez le nom du premier joueur: ";
	string nom1;
	getline(cin,nom1);
	vectJoueur.push_back(Joueur(nom1));
	//le deuxième
	cout<<"Tapez le nom du deuxième joueur: ";
	string nom2;
	getline(cin,nom2);
	vectJoueur.push_back(Joueur(nom2));
	//distribution
	distribuer();
	//tests
	//affichage des jeux des deux joueurs
	for(int noJoueur=0;noJoueur<vectJoueur.size();noJoueur++)
	{
		vectJoueur[noJoueur].afficheJeu();
	}
	//lancement du jeu
	cout<<"On demarre la partie"<<endl;
	jouer();





}
void Partie::distribuer()
{
	cout<<"void Partie::distribuer()"<<endl;
	int noCarte=0;
	//obtention du nombre de joueur normalement 2 joueurs
	int nombreDeJoueur=vectJoueur.size();
	//tant que le jeu n'est pas vide
	while(!jeuComplet.empty())
	{
		//je donne la carte du dessus au joueur dont c'est le tour
		vectJoueur[noCarte%nombreDeJoueur].ajouteCarte(jeuComplet.pop());
		//je passe au joueur suivant
		noCarte++;
	}
}
bool Partie::partieTerminee()
{	int nbJoueurRestant=vectJoueur.size();
	for(int noJoueur=0;noJoueur<vectJoueur.size();noJoueur++)
	{
		//Si le joueur n'a plus de carte
		if(vectJoueur[noJoueur].nAPlusDeCarte())
		{
			//On enleve 1 au nombre de joueur restant
			nbJoueurRestant--;
		}
	}

	//Si il reste un joueur
	return(nbJoueurRestant==1);
}
void Partie::tour()
{
	cout<<"void Partie::tour()"<<endl;
	vector <Carte> vectCartesSurTables;
	bool bataille;
	do
	{
		bataille=false;
		int valeurMax=-1;
		int indiceWinnerTour=-1;
		int nbDeWinner=0;

		for(int noJoueur=0;noJoueur<vectJoueur.size();noJoueur++)
		{
			if(!(vectJoueur[noJoueur].nAPlusDeCarte()))
			{
				//Le joueur renvoie la derniere carte du dessus de son paquet
				Carte carteJouee=vectJoueur[noJoueur].jouer();
				//On ajoute La carte sur la table
				vectCartesSurTables.push_back(carteJouee);
				
				cout<<"le joueur "<<vectJoueur[noJoueur].toString()<<" sort le "<<carteJouee.toString()<<endl;

				//Calcul du joueur ayant la valeur max
				if(carteJouee.getValeur()>valeurMax)
				{
					valeurMax=carteJouee.getValeur();
					indiceWinnerTour=noJoueur;
					nbDeWinner=1;
				}
				else
				{
					if(carteJouee.getValeur()==valeurMax)
					{
						nbDeWinner++;//nb de Winner=2
					}
				}
			}

		}
		if(nbDeWinner==1)//un joueur remporte
		{
			//Le joueur qui a l'indice du gagnant remporte les cartes sur la tables
			vectJoueur[ indiceWinnerTour].remporter(vectCartesSurTables);
			cout<<	vectJoueur[ indiceWinnerTour].toString()<<" remporte "<<vectCartesSurTables.size()<<" cartes"<<endl;
			//vider vectCartesSurTables
			//vectCartesSurTables.resize(0);
		}
		else//Autrement (si nbDeWinner == 2)
		{
			//il y a bataille
			bataille=true;
			cout<<"*****************bataille***********************"<<endl;
			//chaque joueur ajoute une carte(tour blanc)
			for(int noJoueur=0;noJoueur<vectJoueur.size();noJoueur++)
			{
				if(!(vectJoueur[noJoueur].nAPlusDeCarte()))
				{
					//Le joueur donne la carte du dessus de son paquet
					Carte carteJouee=vectJoueur[noJoueur].jouer();
					//On ajoute la carte sur la table
					vectCartesSurTables.push_back(carteJouee);
					cout<<"Le joueur pose une carte a blanc"<<endl;
				}

			}


		}

		//affichage des jeux des deux joueurs
		for(int noJoueur=0;noJoueur<vectJoueur.size();noJoueur++)
		{
			vectJoueur[noJoueur].afficheJeu();
		}
		cin.get();


	}
	//Rester dans la boucle tant que bataille est vrai
	// -OU que la partie est termine
	while(bataille);
}

void Partie::jouer()
{
	do
	{
		tour();

	}
	while(!partieTerminee());
}
