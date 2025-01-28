#pragma once

#include "Pracownik.h"
#include "Kierownik.h"
#include "Kontrahent.h"

#include<fstream>
#include <iostream>
#include <cstring>

class ListaPracownikow
{
private:
    Pracownik* m_pPoczatek; 
    int m_nLiczbaPracownikow; 

public:
    ListaPracownikow();
    ~ListaPracownikow();

    void Dodaj(const Pracownik* p);
    void Usun(const Pracownik& wzorzec);
    void WypiszPracownikow() const;

    const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
    void ZapiszDoPliku(const char* nazwaPliku) const;
    void OdczytZPliku(const char* nazwaPliku);
};
