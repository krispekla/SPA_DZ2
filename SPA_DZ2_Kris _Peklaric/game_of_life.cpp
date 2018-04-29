#include <ctime>
#include "game_of_life.h"

//Generiranje brojeva za pocetno stanje
bool game_of_life::slucajna_vrijednost()
{
	//garantira 25% pocetnog stanje, povecavati max da ih bude sto manje za lakse pracenje(do 8 ima smisla)
	if (slucajniBroj(0, 3) == 0)
	{
		return true;
	}
	return false;
}

//Obicna generate random
int game_of_life::slucajniBroj(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

//Osigurava da ne provjerava rubove koji su random vrijednosti te radi provjeru za normalna polja
bool game_of_life::celija_zauzeta(int i, int j)
{
	if (i < 0 || j < 0 || i>REDAKA || j>STUPACA)   //Provjera rubova
	{
		return false;
	}
	else if (_generacija[i][j])     //Provjera stanja polja
	{
		return true;
	}
	return false;
}

//Obicno kopiranje polja za iduci refresh
void game_of_life::kopiranjeGeneracija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

//Odredujes na temelju stanja okolnih celija hoce li prezivjeti
bool game_of_life::prezivljava(int i, int j)
{
	brojacZauzetosti=0;

	//Provjera 8 okolinih polja
	for (int g = -1; g < 2; g++)
	{
		for (int h = -1; h < 2; h++)
		{
			if (g==0 && h==0)
			{
				continue;
			}
			else if (celija_zauzeta(i + g, j + h))
			{
				brojacZauzetosti++;
			}
		}
	}



	//Suma okolnih polja

	//Ako je celija prazna i okolo ima 3
	if (!celija_zauzeta(i,j))
	{
		if (brojacZauzetosti==3)
		{
			return true;
		}
	}

	//Ostali slucajevi
	else if (brojacZauzetosti == 2 || brojacZauzetosti == 3)
	{
		return true;
	}

	return false;
}

//Pocetna postava random stanja
game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

//Finalno provjeravanje, upis u generaciju te  pozivanje metode za kopiranje cijelog arraya
void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (prezivljava(i, j))
			{
				_sljedeca_generacija[i][j] = true;
			}
			else
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}
	kopiranjeGeneracija();
}
//Ispis sadasnje generacije
void game_of_life::iscrtaj()
{

	cout << endl;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}

		}
		cout << endl;
	}
}
