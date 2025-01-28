#include "Pracownik.h"
#include "ListaPracownikow.h"

using namespace std;

int Pracownik::m_NastepneID = 0;

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesi¹c, int rok) : m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesi¹c, rok), m_nIDZatrudnienia(m_NastepneID++)
{}

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesi¹c, int rok, bool noweID) : m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesi¹c, rok), m_nIDZatrudnienia(m_NastepneID)
{
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	if (this != &wzor) {
		m_Imie = wzor.m_Imie;
		m_Nazwisko = wzor.m_Nazwisko;
		m_DataUrodzenia = wzor.m_DataUrodzenia;
	}
	return *this;

}

Pracownik::Pracownik(const Pracownik& wzor, bool kopiujID)
	: m_Imie(wzor.m_Imie), m_Nazwisko(wzor.m_Nazwisko), m_DataUrodzenia(wzor.m_DataUrodzenia),
	m_nIDZatrudnienia(kopiujID ? wzor.m_nIDZatrudnienia : m_NastepneID),
	m_pNastepny(nullptr), m_pPoprzedni(nullptr) {}

const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

const int Pracownik::ID() const
{
	return m_nIDZatrudnienia;
}

int Pracownik::DzienUrodzenia() const { 
	return m_DataUrodzenia.InfoDzien(); 
}
int Pracownik::MiesiacUrodzenia() const { 
	return m_DataUrodzenia.InfoMiesiac(); 
}
int Pracownik::RokUrodzenia() const { 
	return m_DataUrodzenia.InfoRok(); 
}

void Pracownik::Imie(const char* nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << " ";
	m_Nazwisko.Wypisz();
	cout << " ";
	m_DataUrodzenia.Wypisz();
	cout << " ID: " << m_nIDZatrudnienia;
	cout << endl;
}

void Pracownik::Wpisz()
{
	cout << "Podaj imie: ";
	m_Imie.Wpisz();
	cout << "Podaj nazwisko: ";
	m_Nazwisko.Wpisz();
	cout << "Podaj date urodzenia (dd mm rrrr): ";
	m_DataUrodzenia.Wpisz();
	cin.ignore();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	int wynik = SprawdzNazwisko(wzorzec.Nazwisko());
	if (wynik != 0) return wynik;

	wynik = SprawdzImie(wzorzec.Imie());
	if (wynik != 0) return wynik;

	return m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);
}

void Pracownik::WypiszDane() const
{
	m_Imie.Wypisz();
	cout << " ";
	m_Nazwisko.Wypisz();
	cout << " ";
	m_DataUrodzenia.Wypisz();
	cout << " ID: " << m_nIDZatrudnienia;
	cout << endl;
}
Pracownik* Pracownik::KopiaObiektu() const
{
	Data data = this->m_DataUrodzenia;
	int m_nDzien = data.InfoDzien();
	int m_nMiesiac = data.InfoMiesiac();
	int m_nRok = data.InfoRok();
	return new Pracownik(this->Imie(), this->Nazwisko(), m_nDzien, m_nMiesiac, m_nRok, false);
}
Pracownik::~Pracownik()
{
}

bool Pracownik::operator==(const Pracownik& wzor) const
{
	if (this->SprawdzImie(wzor.Imie()) == 0 && this->SprawdzNazwisko(wzor.Nazwisko()) == 0 && m_DataUrodzenia.Porownaj(wzor.m_DataUrodzenia) == 0)
	{
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& wy, const Pracownik& p)
{
	return wy << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
}


istream& operator>>(istream& we, Pracownik& p)
{
	we >> p.m_Imie;
	we >> p.m_Nazwisko;
	we >> p.m_DataUrodzenia;
	we.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return we;
}
