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

Perso creerPersonnage() {
	std::string nomPerso;

	std::cout << std::endl;

	std::cout << "que sera le prenom de votre etudiant a l'iut ?" << std::endl << ": ";
	std::cin >> nomPerso;


	Perso Perso_principal(nomPerso);

	int choixClasse = 1;

		system("cls");
		
		std::cout << nomPerso << " ? pas ouf le prenom.. bref, sera-t-il : " << std::endl;

		std::cout << "1. Guerrier ?" << std::endl;
		std::cout << "2. Mage ?" << std::endl;
		std::cout << "3. Arab..euh, Voleur ?" << std::endl;
		std::cout << "4. Archer ?" << std::endl;

		std::cout << "votre choix ? (en fonction du numero)" << std::endl;
		std::cout << ": ";
		std::cin >> choixClasse;

		while(!(choixClasse < 5 && choixClasse > 0)) {
			std::cout << "pas un bon chiffre tocard, lis mieux ou je te tabasse" << std::endl;
			std::cin >> choixClasse;
		}

	/*switch (choixClasse) {
	case 1:
		Perso_principal.Guerrier = true;
		Perso_principal.equipement.push_back("Baton en bois");
		break;
	case 2:
		Perso_principal.Mage = true;
		Perso_principal.equipement.push_back("Baton de majissien");
		break;
	case 3:
		Perso_principal.Voleur = true;
		Perso_principal.equipement.push_back("Schlasse(couteau ahah)");
		break;
	case 4:
		Perso_principal.Archer = true;
		Perso_principal.equipement.push_back("sarbacane(du college)");
		break;
	}*/

	return Perso_principal;
};

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