#include "TextGame.hpp"

void printASCII(std::string FileName) {

	std::string line = "";
	std::fstream inFile;
	inFile.open(FileName);

	if (inFile.is_open()){
		while (getline(inFile, line)) {
			std::cout << "		" << line << std::endl;
		}
	}

	else {
		std::cerr << "impossible, fichier probablement corrompu (lol le tocard)" << std::endl;
	}

	inFile.close();
}