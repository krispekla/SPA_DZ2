#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	int slucajniBroj(int min, int max);
	bool celija_zauzeta(int i, int j);
	int brojacZauzetosti = 0;
	void kopiranjeGeneracija();
	bool prezivljava(int i, int j);
public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
