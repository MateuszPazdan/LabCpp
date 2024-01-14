#include "Kierownik.h"

Kierownik::Kierownik(const char* im, const char* naz, int dzien, int miesiac, int rok , const char* wydzial, const int ilePracownikow) : Pracownik(im, naz, dzien, miesiac,  rok)
{
	this->m_NazwaDzialu.Ustaw(wydzial);
	this->m_nliczbaPracownikow = ilePracownikow;
}

Kierownik::Kierownik(const Kierownik& wzor) : Pracownik(wzor), m_NazwaDzialu(wzor.m_NazwaDzialu), m_nliczbaPracownikow(wzor.m_nliczbaPracownikow)
{
}


Kierownik& Kierownik::operator=(const Kierownik& wzor)
{
	this->~Kierownik();
	new (this) Kierownik(wzor);
	return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const
{
	if (this->Porownaj(wzor) == 0) return true;
	return false;
}

void Kierownik::Wpisz()
{
	std::cout << "Imie: ";
	std::cin >> m_Imie;
	std::cout << "Nazwisko: ";
	std::cin >> m_Nazwisko;
	std::cout << "Data urodzenia: ";
	std::cin >> m_DataUrodzenia;
	std::cout << "Nazwa wydzialu: ";
	m_NazwaDzialu.Wpisz();
	std::cout << "Liczba pracownikow: ";
	std::cin >> m_nliczbaPracownikow;
}

void Kierownik::WypiszDane()
{
	this->Pracownik::WypiszDane();
	std::cout << "Nazwa Dzialu: " << m_NazwaDzialu << " " ;
	std::cout << "Liczba Pracownikow: " << m_nliczbaPracownikow << " ";
}

Pracownik* Kierownik::KopiaObiektu() const
{
	return new Kierownik(*this);
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& k)
{
	wy << k.m_Imie << " " << k.m_Nazwisko << " " << k.m_DataUrodzenia << " " << k.m_NazwaDzialu << " " << k.m_nliczbaPracownikow;
	return wy;

}

std::istream& operator>>(std::istream& we, Kierownik& k)
{
	we >> k.m_Imie >> k.m_Nazwisko >> k.m_DataUrodzenia >> k.m_NazwaDzialu >> k.m_nliczbaPracownikow;
	return we;
}
