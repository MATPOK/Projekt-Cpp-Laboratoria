#include "Kontrahent.h"
#include <iostream>

using namespace std;


Kontrahent::Kontrahent(const char* im, const char* naz, int dzien, int miesiac, int rok,
    const char* firma, int liczbaZamowien)
    : Pracownik(im, naz, dzien, miesiac, rok), m_NazwaFirmy(firma), m_nLiczbaZamowien(liczbaZamowien) {
}

Kontrahent::Kontrahent(const char* im, const char* naz, int dzien, int miesiac, int rok, const char* firma, int liczbaZamowien, bool noweID)
    : Pracownik(im, naz, dzien, miesiac, rok, false), m_NazwaFirmy(firma), m_nLiczbaZamowien(liczbaZamowien)
{}


Kontrahent::Kontrahent(const Kontrahent& wzor)
    : Pracownik(wzor), m_NazwaFirmy(wzor.m_NazwaFirmy), m_nLiczbaZamowien(wzor.m_nLiczbaZamowien) {
}


Kontrahent& Kontrahent::operator=(const Kontrahent& wzor) {
    if (this != &wzor) {
        Pracownik::operator=(wzor);
        m_NazwaFirmy = wzor.m_NazwaFirmy;
        m_nLiczbaZamowien = wzor.m_nLiczbaZamowien;
    }
    return *this;
}


bool Kontrahent::operator==(const Kontrahent& wzor) const {
    return Pracownik::operator==(wzor) &&
        m_NazwaFirmy == wzor.m_NazwaFirmy &&
        m_nLiczbaZamowien == wzor.m_nLiczbaZamowien;
}

void Kontrahent::Wpisz()
{

    Pracownik::Wpisz();
    cout << "Podaj nazwe firmy: ";
    m_NazwaFirmy.Wpisz();
    cout << "Podaj liczbê zamówieñ: ";
    cin >> m_nLiczbaZamowien;
    cin.ignore();
}


void Kontrahent::WypiszDane() const {
    cout << "Kontrahent: ";
    Pracownik::WypiszDane();
    cout << "Nazwa firmy: " << m_NazwaFirmy.Zwroc() << endl << "Liczba zamowien: " << m_nLiczbaZamowien << endl;
}


Pracownik* Kontrahent::KopiaObiektu() const {
    return new Kontrahent(*this);
}


ostream& operator<<(ostream& wy, const Kontrahent& i) {
    wy << i.Imie() << " " << i.Nazwisko() << " "
        << i.DzienUrodzenia() << "-" << i.MiesiacUrodzenia() << "-" << i.RokUrodzenia() << " "
        << i.m_NazwaFirmy << " " << i.m_nLiczbaZamowien;
    return wy;
}


istream& operator>>(std::istream& we, Kontrahent& i) {
    we >> static_cast<Pracownik&>(i); 
    cout << "Podaj nazwe firmy: ";
    we >> i.m_NazwaFirmy;
    cout << "Podaj liczbe zamowien: ";
    we >> i.m_nLiczbaZamowien;
    return we;
}