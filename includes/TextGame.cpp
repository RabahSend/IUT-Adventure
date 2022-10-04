#include "TextGame.hpp"
#include "dialogues.hpp"
#include "../Mobs_and_Persos/Entity.hpp"


int menu() {
	int choixMenu = 0;
	std::string list[] = { "1. Demarrer une nouvelle partie", "2. Ouvrir une sauvegarde", "3. Quitter le jeu" };

	std::string fileName = "ASCII.txt";
	printASCII(fileName);

	std::cout << std::endl;

	for (std::string& i : list)
		std::cout << "							" << i << std::endl;

	std::cout << "	--------------" <<
	"---------------------------------------" <<
	"------------------------------------" <<
	"-----------------------------------" <<
	"--------------" << std::endl;

	std::cout << "							";
	std::cin >> choixMenu;

	return choixMenu;
}

void demarrage() {
	system("cls");

	std::string list[] = { "Bienvenue dans la belle aventure de L'IUT !", "Veuillez creer votre personnage." };

	for (std::string& i : list)
		std::cout << "		" << i << std::endl;
}

void choisirMenu(int choix, bool& booleen) {
	switch (choix) {
	case 1:
		demarrage();
		break;

	case 2:
		return;
		break;
	case 3:
		booleen = false;
		break;
	}
}

//void Inventaire()

void faireChoix(Perso personnage_principal) {
	std::vector<std::string> lesChoix = {"1. Avancer", "2. Details du personnage", "3. Sauvegarder",
	 "4. Quitter"};

	std::cout << "		Que voulez vous faire ?" << std::endl;

	for (long long unsigned i = 0; i < lesChoix.size(); ++i){
		std::cout << "		" << lesChoix[i];
	}

	std::cout << std::endl;

	int choixUtilisateur = 0;

	std::cin >> choixUtilisateur;

	switch(choixUtilisateur){
		case 1:
			Dialogues::Narration(personnage_principal, 2, 3);
			break;
		case 2:
			personnage_principal.dropInfos();
			break;
		case 3:
			return;
		case 4:
			menu();
			break;
		default:
			std::cout << "erreur: pas le bon chiffre tocard" << std::endl;
	}
	
	
}

void game() {

	system("cls");

	std::cout << std::endl;

	bool booleen = true;

	int choixMenu = menu();
	if (choixMenu == 3)
		booleen = false;
	else
		choisirMenu(choixMenu, booleen);

	system("cls");

	while (booleen == true) {
		Perso perso_principal = creerPersonnage();

		std::cout << std::endl;

		if (booleen == true){
			Dialogues::Narration(perso_principal, 0, 1);
		}
		else
			booleen = false;

		Dialogues::Chikha(perso_principal, 0, 0);

		faireChoix(perso_principal);
	}

}