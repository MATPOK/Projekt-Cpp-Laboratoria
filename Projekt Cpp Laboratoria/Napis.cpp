#include "Napis.h"

using namespace std;


Napis::Napis(const char* nap) {
    if (nap) {
        m_nDl = strlen(nap) + 1; 
        m_pszNapis = new char[m_nDl];
        strcpy_s(m_pszNapis, m_nDl, nap);
    }
    else {
        m_nDl = 1;
        m_pszNapis = new char[m_nDl];
        m_pszNapis[0] = '\0';
    }
}


Napis::Napis(const Napis& wzor) {
    m_nDl = wzor.m_nDl;
    m_pszNapis = new char[m_nDl];
    strcpy_s(m_pszNapis, m_nDl, wzor.m_pszNapis);
}


Napis& Napis::operator=(const Napis& wzor) {
    if (this != &wzor) { 
        delete[] m_pszNapis;
        m_nDl = wzor.m_nDl;
        m_pszNapis = new char[m_nDl];
        strcpy_s(m_pszNapis, m_nDl, wzor.m_pszNapis);
    }
    return *this;
}


Napis::~Napis() {
    delete[] m_pszNapis;
}


const char* Napis::Zwroc() const {
    return m_pszNapis;
}

void Napis::Ustaw(const char* nowy_napis) {
    if (nowy_napis) {
        int nowaDl = strlen(nowy_napis) + 1;
        if (nowaDl > m_nDl) {
            delete[] m_pszNapis; 
            m_pszNapis = new char[nowaDl];
            m_nDl = nowaDl;
        }
        strcpy_s(m_pszNapis, m_nDl, nowy_napis);
    }
    else {
        m_pszNapis[0] = '\0'; 
    }
}

void Napis::Wypisz() const {
    cout << m_pszNapis;
}

void Napis::Wpisz() {
    char temp[1000]; 
    cin.getline(temp, sizeof(temp));
    Ustaw(temp); 
}

int Napis::SprawdzNapis(const char* por_napis) const {
    return strcmp(m_pszNapis, por_napis);
}

void Napis::operator+=(const char* n)
{
    if (n == nullptr || *n == '\0')return;
    if (m_pszNapis == nullptr)
    {
        m_nDl = strlen(n);
        m_pszNapis = new char[m_nDl + 1];
        strcpy(m_pszNapis, n);
    }
    else
    {
        m_nDl += strlen(n);
        char* ns = new char[m_nDl + 1];
        strcpy(ns, m_pszNapis);
        strcat(ns, n);
        delete[]m_pszNapis;
        m_pszNapis = ns;
    }
}

bool Napis::operator==(const Napis& wzor) const
{
    if (strcmp(m_pszNapis, wzor.Zwroc()) == 0)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& wy, const Napis& p)
{
    return wy << p.m_pszNapis;
}

istream& operator>>(istream& we, Napis& p)
{
    char pom[40];
    int i = 0;

    memset(pom, 0, sizeof(pom));

    while (we.peek() == ' ')
    {
        we.ignore();
    }

    while (we && we.peek() != '\n' && i < 39)
    {
        char c = we.get();
        if (c != ' ') 
        {
            pom[i++] = c;
        }
    }

    p.Ustaw(pom);

    we.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return we;
}
