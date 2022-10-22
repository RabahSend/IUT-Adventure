#include "Entity.hpp"
#include "../includes/dialogues.hpp"

//Creation of objects...

Perso creerPersonnage() {
	std::string nomPerso;

	std::cout << std::endl;

	std::cout << "que sera le prenom de votre etudiant a l'iut ?" << std::endl << ": ";
	std::cin >> nomPerso;

	int choixClasse = 1;

	terminal::terminal term;
	term.clear();
		
		std::cout << nomPerso << " ? pas ouf le prenom.. bref, sera-t-il : " << std::endl;

		Perso Perso_principal(nomPerso);

		std::cout << "1. Guerrier ?" << std::endl
				  << "2. Mage ?" << std::endl
				  << "3. Arab..euh, Voleur ?" << std::endl
				  << "4. Archer ?" << std::endl;

		std::cout << "votre choix ? (en fonction du numero)" << std::endl;
		std::cout << ": ";
		std::cin >> choixClasse;

		if (choixClasse == 1)
			Guerrier Perso_principal(nomPerso);
		else if (choixClasse == 2)
			Mage Perso_principal(nomPerso);
		else if (choixClasse == 3)
			Voleur Perso_principal(nomPerso);
		else
			Archer Perso_principal(nomPerso);

		while(!(choixClasse < 5 && choixClasse > 0)) {
			std::cout << "pas un bon chiffre tocard, lis mieux ou je te tabasse" << std::endl;
			std::cin >> choixClasse;
		}

	Perso_principal.getClasse(choixClasse);

	return Perso_principal;
};