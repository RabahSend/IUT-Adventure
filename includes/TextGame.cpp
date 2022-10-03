#include "TextGame.hpp"
#include "dialogues.hpp"

//a modifier (c'est un test tqt)

Perso::Perso(std::string nom) {

		Nom = nom;
		pointsDeVie = 10.0;
		degats = 10.0;
		defense = 10.0;
		level = 1;
		barre_xp = 0.0;
}

void Perso::augmenterLevel() {
		level++;
}

void Perso::augmenterBarreXP(double nb) {
	barre_xp += nb;
	if (barre_xp > 10) {
		barre_xp = 0;
		nb = 10 - nb;
		barre_xp = nb;
		augmenterLevel();
	}
	else if (barre_xp == 10) {
		barre_xp = 0;
		augmenterLevel();
	}
}

void Perso::dropInfos() {
	system("cls");
	
	std::vector<std::string> Menu = {"1. Aller a l'inventaire", "2. Voir equipement",
	 "3. Quitter le menu personnage"};
	 std::vector<std::string> stats = {"Defense : ", "Attaque : ", "Pv : ", "Niveau : ",
	 "Barre d'experience : "};
	 std::vector <double> statsPerso = {degats,defense, pointsDeVie, (double)level, barre_xp};

	std::cout << "			" << Nom << std::endl;

	std::cout << std::endl;

	std::cout << "classe : ";

	if (Guerrier == true)
		std::cout << "guerrier" << std::endl;
	else if (Mage == true)
		std::cout << "mage" << std::endl;
	else if (Voleur == true)
		std::cout << "voleur" << std::endl;
	else
		std::cout << "archer" << std::endl;

	std::cout << std::endl;

	std::cout << "stats : " << std::endl;

	for (long long unsigned i = 0; i < stats.size(); ++i){
		std::cout << stats[i] << statsPerso[i] << std::endl;
	}

	std::cout << std::endl;

	for(long long unsigned i = 0; i < Menu.size(); ++i){
		std::cout << "		" << Menu[i];
	}
	std::cout << std::endl;

	int choixMenuPerso;

	std::cin >> choixMenuPerso;

	if (choixMenuPerso == 3) {
		return;
	}
}

void Perso::addInventaire(std::string item) {
	inventaire.push_back(item);
}

void Perso::deleteInventaire(std::string item) {
	for (std::string& i : inventaire) {
		if (i == item){
			i = "None";
		}
	}
}


Monster::Monster(double degs, double def, int pv, int lvl) {
	vivant = true;
	degats = degs;
	defense = def;
	pointsDeVie = pv;
	level = lvl;
}

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

	switch (choixClasse) {
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
	}

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