#pragma once
#include <fstream>
#include <sstream>
#include <string>

enum Checkpoints {
	check1 = 1,
	check2,
	check3,
	check4,
	check5
};

void save(Perso);

void loadSave(Perso&, int&);