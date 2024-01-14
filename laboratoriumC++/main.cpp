#include <iostream>
#include <string.h>
#include <conio.h>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "Kierownik.h"
#include "ListaPracownikow.h"

int main() {
    ListaPracownikow* lista = new ListaPracownikow();
	Napis imie, nazwisko;
	int opcja = -1;

	do {
		Pracownik* p;
		system("cls");
		std::cout << "--------------------\n";
		std::cout << "        MENU        \n";
		std::cout << "--------------------\n";
		std::cout << "1.Dodaj pracownika\n";
		std::cout << "2.Usun pracownika\n";
		std::cout << "3.Wypisz pracownikow\n";
		std::cout << "4.Znajdz pracownika\n";
		std::cout << "5.Zapisz pracownikow do pliku\n";
		std::cout << "6.Odczytaj pracownikow z pliku\n";
		std::cout << "0.Zakoncz dzialanie programu\n";
		std::cout << "--------------------\n";
		std::cin >> opcja;
		std::cin.ignore();

		switch (opcja) {
		case 1:
			p = new Pracownik();
			p->Wpisz();
			lista->Dodaj(*p);
			std::cout << "Dodano...\n";
			break;
		case 2:
			p = new Pracownik();
			std::cout << "Podaj wzorzez pracownika do usuniecia.\n";
			p->Wpisz();
			lista->Usun(*p);
			break;
		case 3:
			std::cout << "Pracownicy:\n";
			lista->WypiszPracownikow();
			std::cout << "\n" << "Kliknij przycisk...\n";
			break;
		case 4:
			std::cout << "Znajdz pracownika\n";
			std::cout << "Podaj imie: ";
			imie.Wpisz();
			std::cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();
			if (lista->Szukaj(nazwisko.Zwroc(), imie.Zwroc()) != nullptr) {
				lista->Szukaj(nazwisko.Zwroc(), imie.Zwroc())->Wypisz();
			}
			else {
				std::cout << "Nie znaleziono pracownika\n";
			}
			std::cout << "Kliknij przycisk...\n";
			break;
		case 5:
			lista->ZapiszDoPliku("pracownicy.txt");
			std::cout << "Zapisano pracownikow do pliku...\n";
			break;
		case 6:
			lista->OdczytZPliku("pracownicy.txt");
			std::cout << "Odczytano pracownikow z pliku...\n";
			break;
		case 7:
			p = new Kierownik();
			p->Wpisz();
			lista->Dodaj(*p);
			std::cout << "Dodano...\n";
			break;
		case 0:
			return 0;
		default:
			std::cout << "Wybierz poprawna opcje...\n";
		}
		_getch();

	} while (opcja != 0);

	/*delete lista;
	Pracownik p1("Pawel", "Ochal", 10, 9, 2003);
	Pracownik p3("Lukasz", "Karolak", 11, 12, 2005);
	Pracownik p2("Marcin", "Michnik", 12, 10, 2003);
	
	ListaPracownikow* lista = new ListaPracownikow();
	ListaPracownikow* lista2 = new ListaPracownikow();
	lista->Dodaj(p1);
	lista->Dodaj(p2);
	lista->Dodaj(p3);
	lista->ZapiszDoPliku("pracownicy.txt");
	lista2->OdczytZPliku("pracownicy.txt");
	lista2->WypiszPracownikow();

	delete(lista);*/

    return 0;
}