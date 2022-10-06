#include "TextGame.hpp"
#include "dialogues.hpp"
#include "../Mobs_and_Persos/Entity.hpp"

int menu() {

	void game();
    
    unsigned int choice;
    bool valid = false;

    do {
        terminal::draw::titleScreen();
        terminal::draw::titleSelectMenu(choice);
        
        switch (choice) {
            case 0:
                game();
				break;

            case 1:
				//tqt
                break;

			case 2:
				exit(0);
				break;
        
            default:
                break;
        }
    } while (!valid);
    


    terminal::terminal term;
    term.clear();
    
    return 0;
}

void faireChoix(Perso personnage_principal) {
	std::vector<std::string> lesChoix = {"1. Avancer", "2. Details du personnage", "3. Sauvegarder",
	 "4. Quitter"};

	std::cout << terminal::mid <<"Que voulez vous faire ?" << std::endl;

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
			personnage_principal.getStats();
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

	terminal::terminal term;
	term.clear();
	std::cout << std::endl;
	bool booleen = true;

	while (booleen == true) {
		Perso perso_principal = creerPersonnage();

		std::cout << std::endl;

		if (booleen == true){
			Dialogues::Narration(perso_principal, 0, 1);
		}
		else
			booleen = false;

		Dialogues::Chikha(perso_principal, 0, 0);

		terminal::draw::mobApparition("cat");

		faireChoix(perso_principal);
	}

}