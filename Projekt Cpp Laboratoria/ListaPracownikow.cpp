#include "ListaPracownikow.h"



ListaPracownikow::ListaPracownikow()
{
    m_nLiczbaPracownikow = 0; 
    m_pPoczatek = nullptr;    
}


ListaPracownikow::~ListaPracownikow()
{
    Pracownik* usun = m_pPoczatek; 
    while (usun != nullptr)        
    {
        Pracownik* next = usun->m_pNastepny; 
        delete usun;                        
        m_nLiczbaPracownikow--;            
        usun = next;                         
    }
}

void ListaPracownikow::Dodaj(const Pracownik* p)
{
    bool wasFoundInList = false;
    Pracownik* test = m_pPoczatek;


    while (test != nullptr)
    {
        if (test->Porownaj(*p) == 0) 
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }


    if (!wasFoundInList)
    {
        Pracownik* nowy = p->KopiaObiektu(); 
        nowy->m_pNastepny = nullptr;      
        nowy->m_pPoprzedni = nullptr;      
        if (m_nLiczbaPracownikow == 0)    
        {
            m_pPoczatek = nowy;            
        }
        else
        {
            Pracownik* last = m_pPoczatek;
            while (last->m_pNastepny != nullptr) 
            {
                last = last->m_pNastepny;
            }
            last->m_pNastepny = nowy;     
            nowy->m_pPoprzedni = last;     
        }
        m_nLiczbaPracownikow++;           
    }
}


void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
    Pracownik* test = m_pPoczatek;
    while (test != nullptr) 
    {
        if (test->Porownaj(wzorzec) == 0) 
        {
            Pracownik* next = test->m_pNastepny;
            Pracownik* prev = test->m_pPoprzedni;
            if (test == m_pPoczatek)
                m_pPoczatek = next; 
            if (prev)
                prev->m_pNastepny = next; 
            if (next)
                next->m_pPoprzedni = prev; 
            m_nLiczbaPracownikow--;       
            delete test;                 
            break;
        }
        test = test->m_pNastepny; 
    }
}


void ListaPracownikow::WypiszPracownikow() const
{
    if (m_pPoczatek == nullptr) 
    {
        cout << "Brak pracownikow w liscie." << endl;
        return;
    }

    Pracownik* p = m_pPoczatek;
    int i = 1;
    while (p != nullptr) 
    {
        cout << i << "\t"; 
        p->Wypisz();          
        cout << endl;
        p = p->m_pNastepny;    
        i++;
    }
}


const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
    Pracownik* test = m_pPoczatek;
    while (test != nullptr) 
    {
        if (strcmp(test->Nazwisko(), nazwisko) == 0 && strcmp(test->Imie(), imie) == 0)
        {
            return test; 
        }
        test = test->m_pNastepny; 
    }
    return nullptr; 
}

void ListaPracownikow::ZapiszDoPliku(const char* nazwaPliku) const {
    ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Nie uda³o siê otworzyæ pliku do zapisu: " << nazwaPliku << endl;
        return;
    }

    Pracownik* p = m_pPoczatek;
    while (p != nullptr) {
        if (dynamic_cast<Kierownik*>(p) != nullptr) {
            plik << "K " << p->ID() << " " << *dynamic_cast<Kierownik*>(p) << "\n";
        }
        else if (dynamic_cast<Kontrahent*>(p) != nullptr) {
            plik << "C " << p->ID() << " " << *dynamic_cast<Kontrahent*>(p) << "\n";
        }
        else {
            plik << "P " << p->ID() << " " << *p << "\n";
        }
        p = p->m_pNastepny;
    }

    plik.close();
    cout << "Pomyslnie zapisano liste pracownikow do pliku\n";
}

void ListaPracownikow::OdczytZPliku(const char* nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Nie uda³o siê otworzyæ pliku do odczytu: " << nazwaPliku << endl;
        return;
    }

    char typ;
    while (plik >> typ) { 
        int id;
        plik >> id;

        if (typ == 'P') {
            char imie[256], nazwisko[256];
            int dzien, miesiac, rok;

            plik >> imie >> nazwisko >> dzien;
            plik.ignore(1, '-'); 
            plik >> miesiac;
            plik.ignore(1, '-'); 
            plik >> rok;

            if (!plik.fail()) {
                Pracownik* nowyPracownik = new Pracownik(imie, nazwisko, dzien, miesiac, rok);
                Dodaj(nowyPracownik);
            }
        }
        else if (typ == 'K') {
            char imie[256], nazwisko[256], nazwaDzialu[256];
            int dzien, miesiac, rok, liczbaPracownikow;

            plik >> imie >> nazwisko >> dzien;
            plik.ignore(1, '-');
            plik >> miesiac;
            plik.ignore(1, '-');
            plik >> rok;
            plik >> nazwaDzialu >> liczbaPracownikow;

            if (!plik.fail()) {
                Kierownik* nowyKierownik = new Kierownik(imie, nazwisko, dzien, miesiac, rok, nazwaDzialu, liczbaPracownikow);
                Dodaj(nowyKierownik);
            }
        }
        else if (typ == 'C') {
            char imie[256], nazwisko[256], firma[256];
            int dzien, miesiac, rok, liczbaZamowien;

            plik >> imie >> nazwisko >> dzien;
            plik.ignore(1, '-');
            plik >> miesiac;
            plik.ignore(1, '-');
            plik >> rok;
            plik >> firma >> liczbaZamowien;

            if (!plik.fail()) {
                Kontrahent* nowyKontrahent = new Kontrahent(imie, nazwisko, dzien, miesiac, rok, firma, liczbaZamowien);
                Dodaj(nowyKontrahent);
            }
        }
    }

    plik.close();
    cout << "Lista pracownikow zostala odczytana z pliku\n";
}
