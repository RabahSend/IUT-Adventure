#ifndef TEXTGAME_HPP
#define TEXTGAME_HPP
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include "../Mobs_and_Persos/Entity.hpp"

void demarrage();

void printASCII(std::string);

int menu();

void choisirMenu(int, bool&);

void faireChoix(Perso);

void game();

#endif