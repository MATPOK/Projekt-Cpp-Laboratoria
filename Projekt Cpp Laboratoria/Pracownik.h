#pragma once

#include "Napis.h"
#include "Data.h"

#include <iostream>

using namespace std;

class Pracownik
{
private:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int m_NastepneID;


public:
	Pracownik(const char* im = "", const char* naz = "", int dzien = 1, int miesi¹c = 1, int rok = 2000);
	Pracownik(const char* im, const char* naz, int dzien, int miesi¹c, int rok, bool noweID);
	Pracownik(const Pracownik& wzor, bool kopiujID = false);
	Pracownik& operator=(const Pracownik& wzor);

	const char* Imie() const;
	const char* Nazwisko() const;
	const int ID() const;
	int DzienUrodzenia() const;
	int MiesiacUrodzenia() const;
	int RokUrodzenia() const;

	Pracownik* m_pNastepny;
	Pracownik* m_pPoprzedni;

	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);

	void Wypisz() const;
	virtual void Wpisz();

	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const;

	virtual void WypiszDane() const;
	virtual Pracownik* KopiaObiektu() const;
	virtual ~Pracownik();

	bool operator==(const Pracownik& wzor) const;

	friend ostream& operator<<(ostream& wy, const Pracownik& p);
	friend istream& operator>>(istream& we, Pracownik& p);
};

ostream& operator<<(ostream& wy, const Pracownik& p);
istream& operator>>(istream& we, Pracownik& p);

