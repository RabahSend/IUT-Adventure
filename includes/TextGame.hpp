#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include "../Mobs_and_Persos/Entity.hpp"

namespace Functionnality {
	terminal::terminal term;
	Checkpoints check;
};

void demarrage();

void printASCII(std::string);

int menu();

void choisirMenu(int, bool&);

void faireChoix(Perso, int, int);

void game();