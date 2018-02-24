#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;
                         
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

int main()
{
	string motMystere, motMelange, motUtilisateur, ligne;
	int tour(0);
	int cache(0);
	int chiffre(0);
	int ttour(0);
	srand(time(0));

	ifstream motflux("C:\Users\X230\Desktop\dico.txt");
	
	chiffre = rand() % 323577;

	for (int i = 0; i <= chiffre; i++)
	{
		getline(motflux, ligne);
		ligne = motMystere;
	}
	
	motMelange = melangerLettres(motMystere);
	
		for (tour = 4; tour >= 0 ; tour--)
		{
			cout << endl << "Quel est ce mot ? :  " << motMelange << endl;
			cin >> motUtilisateur;

			if (motUtilisateur == motMystere)
			{
				cout << "Bravo !" << endl;
			}
			else
			{
				cout << "Ce n'est pas le mot !\n" << endl;
				cout << "Il vous reste " << tour << " de tour\n" << endl;
			}
		}

		cout << "Le Mot Mystére est : " << motMystere << endl;

	return 0;
}