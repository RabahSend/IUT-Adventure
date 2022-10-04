#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../includes/terminal.hpp"

struct stats {
	double degats;
	double defense;
	double pointsDeVie;
	int level;
	int barre_xp;
};

class Perso {

protected:

	stats Stats;

private:

	bool vivant = true;
	std::string Nom;

public:

	std::string getName(std::string nom) { return nom; }
	std::string afficherNom() {return Nom;}

	void getStats() {
		std::cout << terminal::mid << Nom << std::endl;

		std::cout << "Defense : " << Stats.defense << std::endl;
		std::cout << "Degats : " << Stats.degats << std::endl;
		std::cout << "PV : " << Stats.pointsDeVie << std::endl;
		std::cout << "level : " << Stats.level << std::endl;
		std::cout << "barre d'xp : " << Stats.barre_xp << std::endl;
	}

	Perso(std::string nom) {

		Nom = nom;
		Stats.pointsDeVie = 10.0;
		Stats.degats = 10.0;
		Stats.defense = 10.0;
		Stats.level = 1;
		Stats.barre_xp = 0.0;
	}

	void augmenterLevel() { Stats.level++; }

	void augmenterBarreXP(double nb) {
	Stats.barre_xp += nb;
	if (Stats.barre_xp > 10) {
		Stats.barre_xp = 0;
		nb = 10 - nb;
		Stats.barre_xp = nb;
		augmenterLevel();
	}
	else if (Stats.barre_xp == 10) {
		Stats.barre_xp = 0;
		augmenterLevel();
	}
}

	void dropInfos();

	void addInventaire(std::string);

	void deleteInventaire(std::string);
};

class Guerrier:public Perso {
	private:
		bool FeuTenebreux = false;
		bool TourbillonDuDesespoir = false;
		bool HacheDeGuerre = false;
		bool DestructionInstantanee = false;
	public:
		Guerrier(std::string nom):Perso(getName(nom)) {
			Stats.pointsDeVie = 15.0;
			Stats.degats = 15.0;
			Stats.defense = 5.0;
		}

		void donnerCompetence() {
			if (Stats.level == 5)
				FeuTenebreux = true;
		}
};

class Monster {
private:
	bool vivant;
	double degats;
	double defense;
	int pointsDeVie;
	int level;

public:

	Monster(double degs, double def, int pv, int lvl) {
	vivant = true;
	degats = degs;
	defense = def;
	pointsDeVie = pv;
	level = lvl;
	}
};

Perso creerPersonnage();