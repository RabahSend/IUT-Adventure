#include "checkpoint.hpp"
#include "../includes/TextGame.hpp"
#include "../Mobs_and_Persos/Entity.hpp"

void save(Perso perso_principal) {
    std::fstream file;

    file.open("saves.csv");

    if (file.is_open()) {
        file << Functionnality::check << ',' <<
        perso_principal.afficherNom() << ','  <<
        perso_principal.displayClasse() << ',' <<
        perso_principal.displayLevel();
    }

    file.close();
}

void loadSave(Perso& perso_principal, int& check) {
    std::fstream file;
    std::string line;

    file.open("saves.csv");

    if (file.fail())
        std::cerr << "aucune sauvegarde a restaurer.." << std::endl;
    else if (file.is_open()) {
        while(getline(file, line)) {
            std::stringstream inputString(line);
            std::string tempString;

            getline(inputString, tempString, ',');
            check = atoi(tempString.c_str());

            getline(inputString, tempString, ',');
            perso_principal.getName(tempString);

            getline(inputString, tempString, ',');
            int classe = atoi(tempString.c_str());
            perso_principal.getClasse(classe);

            getline(inputString, tempString, ',');
            int level = atoi(tempString.c_str());
            perso_principal.getLevel(level);

            line = "";

            file.close();
        }
    }
}