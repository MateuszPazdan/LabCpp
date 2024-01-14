#pragma once
#include "Pracownik.h"


class Kierownik : public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;
public:
	Kierownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000, const char* wydzial = "", const int ilePracownikow = 0);
	Kierownik(const Kierownik& wzor);
	
	void Wpisz();
	void WypiszDane();
	Pracownik* KopiaObiektu() const override;

	Kierownik& operator=(const Kierownik& wzor);
	bool operator==(const Kierownik& wzor) const;
	friend std::ostream& operator<<(std::ostream& wy, const Kierownik& k);
	friend std::istream& operator>>(std::istream& we, Kierownik& k);

};

