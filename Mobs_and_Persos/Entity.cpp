#include "Entity.hpp"
#include "../includes/dialogues.hpp"

//Creation of objects...

Perso creerPersonnage() {
	std::string nomPerso;

	std::cout << std::endl;

	std::cout << "que sera le prenom de votre etudiant a l'iut ?" << std::endl << ": ";
	std::cin >> nomPerso;


	Perso Perso_principal(nomPerso);

	int choixClasse = 1;

	terminal::terminal term;
	term.clear();
		
		std::cout << nomPerso << " ? pas ouf le prenom.. bref, sera-t-il : " << std::endl;

		std::cout << "1. Guerrier ?" << std::endl
				  << "2. Mage ?" << std::endl
				  << "3. Arab..euh, Voleur ?" << std::endl
				  << "4. Archer ?" << std::endl;

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