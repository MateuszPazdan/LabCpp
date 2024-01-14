#pragma once
#include "Napis.h"
#include "Data.h"


class Pracownik
{
protected:
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
	static int ID;
public:
	Pracownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik& wzor);
	const char* Imie() const;
	const char* Nazwisko() const;
	Pracownik* m_pNastepny;


	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);

	virtual void Wypisz() const;
	virtual void Wpisz();

	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik& wzorzec) const;

	Pracownik& operator=(const Pracownik& wzor);
	bool operator==(const Pracownik& wzor) const;
	friend std::ostream& operator<<(std:: ostream& wy, const Pracownik& p);
	friend std::istream& operator>>(std::istream& we, Pracownik& p);

	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu()const;
};



