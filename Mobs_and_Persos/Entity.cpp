#include "Entity.hpp"

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

	/*if (Guerrier == true)
		std::cout << "guerrier" << std::endl;
	else if (Mage == true)
		std::cout << "mage" << std::endl;
	else if (Voleur == true)
		std::cout << "voleur" << std::endl;
	else
		std::cout << "archer" << std::endl;*/

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