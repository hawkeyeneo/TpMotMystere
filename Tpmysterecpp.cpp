#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Tpmystereett.h"

using namespace std;

int main()
{
	int rejouer(0);

	cout << " Bienvenue dans le jeux Mot Mystere\n" << endl;

	do
	{
		main1();
		cout << "Voulez-vous faire une autre partie ?  (1) oui (0) Non\n" << endl;
		cin >> rejouer;

	} while (rejouer == 1);
	
	return 0;
}

string melangerLettres(string mot)
{
	string melange;
	int position(0);

	while (mot.size() != 0)
	{

		position = rand() % mot.size();

		melange += mot[position];

		mot.erase(position, 1);
	}

	return melange;
}

int main1()
{
	string motMystere, motMelange, motUtilisateur;
	int tour(0);
	int cache(0);
	int chiffre(0);
	int ttour(0);
	srand(time(0));

	ifstream motflux("dico.txt"); // On est dans le dossier ou il y a le cpp et on recul d'un dossier pour accéder a celui du dico

	chiffre = rand() % 323577;

	if (motflux)
	{
		for (int i = 0; i <= chiffre; i++)
		{
			getline(motflux, motMystere);

		}
	}
	else
	{
		cout << " ERREUR FICHIER NON OUVERT" << endl;

	}
		
	cout << "Veuillez patienter" << endl;
	cout << "Le mot ce melange" << endl;

	motMelange = melangerLettres(motMystere);

	for (tour = 4; tour >= 0; tour--)
	{
		cout << endl << "Player : Quel est ce mot ? :  " << motMelange << endl;
		cin >> motUtilisateur;

		if (motUtilisateur == motMystere)
		{
			cout << "Bravo ! \n" << endl;
		}
		else
		{
			cout << "Ce n'est pas le mot !\n" << endl;
			cout << "Il vous reste " << tour << " de tour pour trouver le mot\n" << endl;
		}
	}

	cout << "Le Mot Mystere est : " << motMystere <<"\n" << endl;
	

	return 0;
}

