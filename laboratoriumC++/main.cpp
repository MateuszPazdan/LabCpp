#include <iostream>
#include <string.h>
#include <conio.h>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"

int main() {
    ListaPracownikow* lista = new ListaPracownikow();
	int opcja = -1;
	Napis imie, nazwisko;

	do {
		Pracownik p;
		system("cls");
		std::cout << "--------------------\n";
		std::cout << "        MENU        \n";
		std::cout << "--------------------\n";
		std::cout << "1.Dodaj pracownika\n";
		std::cout << "2.Usun pracownika\n";
		std::cout << "3.Wypisz pracownikow\n";
		std::cout << "4.Znajdz pracownika\n";
		std::cout << "0.Zakoncz dzialanie programu\n";
		std::cout << "--------------------\n";
		std::cin >> opcja;
		std::cin.ignore();

		switch (opcja) {
		case 1:
			p.Wpisz();
			lista->Dodaj(p);
			std::cout << "Dodano...\n";
			break;
		case 2:
			std::cout << "Podaj wzorzez pracownika do usuniecia.\n";
			p.Wpisz();
			lista->Usun(p);
			std::cout << "Usuniêto...\n";
			break;
		case 3:
			std::cout << "Pracownicy:\n";
			lista->WypiszPracownikow();
			std::cout << "Kliknij przycisk...\n";
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
				std::cout << "Nie znaleziono pracownika";
			}
			lista->Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			std::cout << "Kliknij przycisk...\n";
			break;
		default:
			std::cout << "Wybierz poprawna opcje\n";
		}
		_getch();

	} while (opcja != 0);


	
	delete lista;



    

    return 0;
}