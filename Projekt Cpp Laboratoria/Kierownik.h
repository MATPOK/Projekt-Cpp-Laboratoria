#pragma once

#include "Pracownik.h"

using namespace std;

class Kierownik :
    public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;
public:
	
	Kierownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000, const char* nazwaDzialu = "", int liczbaPracownikow = 0);
	Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok, const char* nazwaDzialu, int liczbaPracownikow, bool noweID);
	Kierownik(const Kierownik& wzor);


	Kierownik& operator=(const Kierownik& wzor);
	bool operator==(const Kierownik& wzor) const;


	virtual void Wpisz() override;
	virtual void WypiszDane() const override;
	virtual Pracownik* KopiaObiektu()const override;


	friend ostream& operator<<(ostream& wy, const Kierownik& p);
	friend istream& operator>>(istream& we, Kierownik& p);
};
ostream& operator<<(ostream& wy, const Kierownik& s);
istream& operator>>(istream& we, Kierownik& s);

