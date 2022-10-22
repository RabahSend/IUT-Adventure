#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../includes/terminal.hpp"

struct stats {
	double degats;
	double defense;
	double pointsDeVie;
};

class Perso {

protected:

	stats Stats;
	int level;
	int barre_xp;

private:

	bool vivant = true;
	std::string Nom;
	int choixClasse;

public:

	std::string getName(std::string nom) { return nom; }
	int getClasse(int classe) { return classe; }
	int getLevel(int level) { return level; }

	std::string afficherNom() { return Nom; }
	int displayLevel() { return level; }
	double displayPDV() { return Stats.pointsDeVie; }
	int displayXP() { return barre_xp; }
	double displayDefense() { return Stats.defense; }
	double displayDegats() { return Stats.degats; }
	int displayClasse() { return choixClasse; }

	void getStats() {
		std::cout << terminal::mid << Nom << std::endl;

		std::cout << "Defense : " << displayDefense() << std::endl;
		std::cout << "Degats : " <<	displayDegats() << std::endl;
		std::cout << "PV : " << displayPDV() << std::endl;
		std::cout << "level : " << displayLevel() << std::endl;
		std::cout << "barre d'xp : " << displayXP() << std::endl;
	}

	Perso(std::string nom) {

		Nom = nom;
		Stats.pointsDeVie = 10.0;
		Stats.degats = 10.0;
		Stats.defense = 10.0;
		level = 1;
		barre_xp = 0.0;
	}

	void augmenterLevel() { level++; }

	void augmenterBarreXP(double nb) {
	barre_xp += nb;
	if (barre_xp > 10) {
		barre_xp = 0;
		nb = 10 - nb;
		barre_xp = nb;
		augmenterLevel();
	}
	else if (barre_xp == 10) {
		barre_xp = 0;
		augmenterLevel();
	}
}

	void dropInfos();
	
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
			Stats.degats = 10.0;
			Stats.defense = 10.0;
		}

		void donnerCompetence() {
			if (level == 5)
				FeuTenebreux = true;
		}
};
class Mage:public Perso {
	private:
		bool bouleDeFeu = false;
		bool Soin = false;
		bool bouleDeGlace = false;
		bool Clonage = false;
	public:
		Mage(std::string nom):Perso(getName(nom)) {
			Stats.pointsDeVie = 5.0;
			Stats.degats = 20.0;
			Stats.defense = 5.0;
		}

		void donnerCompetence() {
			if (level == 5)
				bouleDeFeu = true;
		}
};
class Voleur:public Perso {
	private:
		bool lacosteTN = false;
		bool attaqueAPlusieurs = false;
		bool khalassMan = false;
		bool volBandeOrganisee = false;
	public:
		Voleur(std::string nom):Perso(getName(nom)) {
			Stats.pointsDeVie = 10.0;
			Stats.degats = 15.0;
			Stats.defense = 5.0;
		}

		void donnerCompetence() {
			if (level == 5)
				lacosteTN = true;
		}
};
class Archer:public Perso {
	private:
		bool flecheBrulante = false;
		bool flecheEmpoisonnee = false;
		bool pluieDeFleches = false;
		bool bombeDeFleches = false;
	public:
		Archer(std::string nom):Perso(getName(nom)) {
			Stats.pointsDeVie = 10.0;
			Stats.degats = 15.0;
			Stats.defense = 5.0;
		}

		void donnerCompetence() {
			if (level == 5)
				flecheBrulante = true;
		}
};

class Monster {
private:
	stats Stats;
	int level;
	int barre_xp;
	bool vivant = true;
	
public:
	Monster(double degs, double def, int pv, int lvl) {
	Stats.degats = degs;
	Stats.defense = def;
	Stats.pointsDeVie = pv;
	level = lvl;
	barre_xp = 0;
	}
};

Perso creerPersonnage();