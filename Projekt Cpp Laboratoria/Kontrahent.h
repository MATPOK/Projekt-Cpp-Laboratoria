#pragma once

#include "Pracownik.h"

using namespace std;

class Kontrahent : public Pracownik {
private:
    Napis m_NazwaFirmy; 
    int m_nLiczbaZamowien;    

public: 
    Kontrahent(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000, const char* firma = "", int liczbaZamowien = 0);
    Kontrahent(const char* im, const char* naz, int dzien, int miesiac, int rok, const char* firma, int liczbaZamowien, bool noweID);
    Kontrahent(const Kontrahent& wzor);

    Kontrahent& operator=(const Kontrahent& wzor);
    bool operator==(const Kontrahent& wzor) const;

    virtual void Wpisz() override;
    virtual void WypiszDane() const override;
    virtual Pracownik* KopiaObiektu() const override;

    friend ostream& operator<<(ostream& wy, const Kontrahent& i);
    friend istream& operator>>(istream& we, Kontrahent& i);
};
istream& operator>>(istream& we, Kontrahent& i);
ostream& operator<<(ostream& wy, const Kontrahent& i);