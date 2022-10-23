#include "TextGame.hpp"
#include "dialogues.hpp"
#include "../Mobs_and_Persos/Entity.hpp"


void Dialogues::passerDialogue() {
	std::string space;
	std::cout << "Pressez entrer pour continuer..." << std::endl;
	std::getline(std::cin, space);
}

void Dialogues::Narration(Perso perso_principal, int indexDebut, int indexFin) {

	if (indexDebut == 0 && indexFin == 1) {
		std::cout << perso_principal.afficherNom() << " se promene tranquillement en quete de connaissances(glander dans la salle des poufs).." << std::endl;
	}
	std::vector<std::string> narrateur = { "..Quand, soudain, une grande ombre apparait en face de lui, discernable entre toutes..",
		"OMG, c'etait monsieur Chikhaoui !!",
		 "Vous decidez courageusement d'avancer en vous confrontant a Monsieur Chikhaoui, mais vous remarquez quelque chose...",
		 "		CETTE AURA QUI SE DEGAGE DE LUI... PHENOMENALE..."};

	if (indexFin < indexDebut)
		std::cout << narrateur[indexDebut] << std::endl;
	else {
		for (int i = indexDebut; i <= indexFin; ++i){
			std::cout << narrateur[i] << std::endl; 
			std::cout << std::endl;
		}
	}

	passerDialogue();
}

void Dialogues::Chikha(Perso perso_principal, int indexDebut, int indexFin) {

	std::vector<std::string> paroles = { "Vous m'suivez ?", "hein ? hein ?", "ca c'est de l'economie et de la gestion",
	"je ne suis pas raciste, mais realiste !" };

	for (int i = indexDebut; i <= indexFin; ++i)
		std::cout << paroles[i] << std::endl;
}

void Dialogues::Professors(Perso perso_principal, int indexDebut, int indexFin, std::string prof) {
	std::vector<std::string> parolesDesbenois = { "ce code ? je le fais en 2 lignes..", "ah oui, pue la merde ton code arrete l'informatique stp",
	"tu n'arrivera pas a me battre, j'utilise la decrementation je suis forcement superieur a toi." };

	std::vector<std::string> parolesRicardo = { "Hola Chica !", "Soy mexicano !", "Te vencere, con mi acento estalla su madre!" };

	std::vector<std::string> parolesGuilherme = { "Linoux.", "Le Linoux.", "j'outilise Linoux !" };

	for (int i = indexDebut; i <= indexFin; ++i) {
    	if (prof == "desbenois")
			std::cout << parolesDesbenois[i] << std::endl;
			
		else if (prof == "ricardo")
			std::cout << parolesRicardo[i] << std::endl;
		else if (prof == "guilherme")
			std::cout << parolesGuilherme[i] << std::endl;
		else
			std::cout << "erreur: pas le bon nom de prof" << std::endl;
		}
}

void Dialogues::Mobs(int indexDebut, int indexFin, std::string mob) {
	std::vector<std::string> parolesBodyPillowMiku = { "nyaa~", "yamete-", "^-^", "kawaiii-neee" };

	for (int i = indexDebut; i <= indexFin; ++i) {
		if (mob == "bodypillowmiku")
			std::cout << "-" << parolesBodyPillowMiku[i] << std::endl;
	}
}