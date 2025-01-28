#include "Kierownik.h"

using namespace std;


Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok,
	const char* nazwaDzialu, int liczbaPracownikow)
	: Pracownik(im, naz, dzien, miesiac, rok), m_NazwaDzialu(nazwaDzialu), m_nliczbaPracownikow(liczbaPracownikow) {
}

Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok, const char* nazwaDzialu, int liczbaPracownikow, bool noweID) : Pracownik(im, naz, dzien, miesiac, rok, false), m_NazwaDzialu(nazwaDzialu), m_nliczbaPracownikow(liczbaPracownikow)
{}

Kierownik::Kierownik(const Kierownik& wzor) : Pracownik(wzor, false),
m_NazwaDzialu(wzor.m_NazwaDzialu), m_nliczbaPracownikow(wzor.m_nliczbaPracownikow)
{}


Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
	if (this != &wzor) {
		m_NazwaDzialu = wzor.m_NazwaDzialu;
		m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
		static_cast<Pracownik&>(*this) = wzor;
	}
	return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
	if (Pracownik::operator==(wzor) && m_NazwaDzialu == wzor.m_NazwaDzialu && m_nliczbaPracownikow == wzor.m_nliczbaPracownikow) {
		return 1;
	}
	else {
		return 0;
	}
}

void Kierownik::Wpisz()
{
	Pracownik::Wpisz();
	cout << "Podaj nazwe dzialu: ";
	m_NazwaDzialu.Wpisz();
	cout << "Podaj liczbe pracownikow: ";
	cin >> m_nliczbaPracownikow;
	cin.ignore();
}


void Kierownik::WypiszDane() const
{
	cout << "Kierownik: ";
	Pracownik::WypiszDane();  
	cout << "Nazwa dzialu: " << m_NazwaDzialu << endl;
	cout << "Liczba pracownikow: " << m_nliczbaPracownikow << endl;
}




Pracownik* Kierownik::KopiaObiektu() const
{
	return new Kierownik(*this);
}


ostream& operator<<(ostream& wy, const Kierownik& s)
{
	wy << s.Imie() << " " << s.Nazwisko() << " "
		<< s.DzienUrodzenia() << "-" << s.MiesiacUrodzenia() << "-"
		<< s.RokUrodzenia() << " " << s.m_NazwaDzialu << " " << s.m_nliczbaPracownikow;
	return wy;
}


istream& operator>>(istream& we, Kierownik& s)
{
	we >> static_cast<Pracownik&>(s); // Wywo³anie operatora >> klasy bazowej
	we >> s.m_NazwaDzialu;            // Wczytanie nazwy dzia³u
	we >> s.m_nliczbaPracownikow;     // Wczytanie liczby pracowników
	we.ignore(numeric_limits<streamsize>::max(), '\n');
	return we;
}