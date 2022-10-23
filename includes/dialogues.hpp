#pragma once
#include "TextGame.hpp"

namespace Dialogues {
    
    void passerDialogue();

	void Narration(Perso, int, int=0);

	void Chikha(Perso, int, int);

	void Professors(Perso, int, int, std::string);

	void Mobs(int indexDebut, int indexFin, std::string mob);

}