#pragma once
#include <iostream>
#include <vector>
#include <string>

class Perso {

protected:

	double degats;
	double defense;
	double pointsDeVie;
	int level;

private:

	double barre_xp;
	bool vivant = true;

public:

	std::vector<std::string> equipement;
	std::vector<std::string> inventaire;
	std::string Nom;

	Perso(std::string);

	void augmenterLevel();

	void augmenterBarreXP(double);

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
		Guerrier(std::string nom):Perso(Nom) {
			Nom = nom;
			pointsDeVie = 15.0;
			degats = 15.0;
			defense = 5.0;
		}

		void donnerCompetence() {
			if (level == 5)
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

	Monster(double, double, int, int);

};