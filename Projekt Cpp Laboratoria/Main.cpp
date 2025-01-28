#include "ListaPracownikow.h"

using namespace std;


void Menu() {
	ListaPracownikow list;
	const char* fileName = "Pracownicy.txt";
	int choose;

	do {
		cout << "--------------------------------------\n";
		cout << "|               MENU                 |\n";
		cout << "--------------------------------------\n";
		cout << "| 1) Nowy pracownik                  |\n";
		cout << "| 2) Nowy kierownik                  |\n";
		cout << "| 3) Nowy kontrahent                 |\n";
		cout << "| 4) Usu� z listy                    |\n";
		cout << "| 5) Wypisz ca�� list�               |\n";
		cout << "| 6) Znajd� na li�cie                |\n";
		cout << "| 7) Zapisz list� do pliku           |\n";
		cout << "| 8) Wczytaj list� z pliku           |\n";
		cout << "| 9) Zako�cz program                 |\n";
		cout << "--------------------------------------\n";
		cout << "Wybierz co chcesz zrobi�: ";
		cin >> choose;
		cin.ignore();

		switch (choose) {
		case 1: {
			cout << endl;
			Pracownik* worker = new Pracownik();
			worker->Wpisz();
			list.Dodaj(worker);
			cout << "\nPracownik dodany pomy�lnie!\n";
			break;
		}
		case 2: {
			cout << endl;
			Kierownik* executive = new Kierownik();
			executive->Wpisz();
			list.Dodaj(executive);
			cout << "\nKierownik dodany pomy�lnie!\n";
			break;
		}
		case 3: {
			cout << endl;
			Kontrahent* contractor = new Kontrahent();
			contractor->Wpisz();
			list.Dodaj(contractor);
			cout << "\nKontrahent dodany pomy�lnie!\n";
			break;
		}
		case 4: {
			Pracownik w;
			cout << "\nWprowad� dane osoby do usuni�cia: \n";
			w.Wpisz();
			list.Usun(w);
			cout << "\nUsuni�to pomy�lnie z listy!\n";
			break;
		}
		case 5: {
			cout << "\nLista:\n";
			list.WypiszPracownikow();
			break;
		}
		case 6: {
			char name[256], surname[256];
			cout << "Podaj imi�: ";
			cin.getline(name, 256);
			cout << "Podaj nazwisko: ";
			cin.getline(surname, 256);

			const Pracownik* found = list.Szukaj(surname, name);
			if (found != nullptr) {
				cout << "\nZnaleziona osoba:\n";
				found->WypiszDane();
			}
			else {
				cout << "Nie znaleziono na li�cie!\n";
			}
			break;
		}
		case 7: {
			list.ZapiszDoPliku(fileName);
			break;
		}
		case 8: {
			list.OdczytZPliku(fileName);
			break;
		}
		case 9: {
			cout << "\nKoniec programu!";
			break;
		}
		default:
			cout << "\nB��dna opcja! Spr�buj ponownie!\n";
		}
	} while (choose != 9);
}

int main() {
	setlocale(LC_ALL, "pl_PL");
	Menu();
	return 0;
}