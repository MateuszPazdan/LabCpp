#include <iostream>
#include "Pracownik.h"

int Pracownik::ID = 0;

Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok) : m_pNastepny(nullptr), m_nIDZatrudnienia(ID++), m_DataUrodzenia(*(new Data(dzien,miesiac,rok)))
{
	this->m_Imie.Ustaw(im);
	this->m_Nazwisko.Ustaw(naz);
}

Pracownik::Pracownik(const Pracownik& wzor) : m_pNastepny(nullptr), m_nIDZatrudnienia(wzor.m_nIDZatrudnienia), m_DataUrodzenia(*(new Data(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok())))
{
	this->m_Imie.Ustaw(wzor.Imie());
	this->m_Nazwisko.Ustaw(wzor.Nazwisko());
}

const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	this->~Pracownik();
	new (this) Pracownik(wzor);
	return *this;
}

void Pracownik::Imie(const char* nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	std::cout << " ";
	m_Nazwisko.Wypisz();
	std::cout << " ";
	m_DataUrodzenia.Wypisz();
	std::cout << '\n';
}

void Pracownik::Wpisz()
{
	std::cout << "Imie: ";
	m_Imie.Wpisz();
	std::cout << "Nazwisko: ";
	m_Nazwisko.Wpisz();
	std::cout << "Data urodzenia: ";
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char* por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	if (wzorzec.SprawdzNazwisko(this->m_Nazwisko.Zwroc()) != 0) return -(wzorzec.SprawdzNazwisko(this->m_Nazwisko.Zwroc()));
	else if (wzorzec.SprawdzImie(this->m_Imie.Zwroc()) != 0) return -(wzorzec.SprawdzImie(this->m_Imie.Zwroc()));
	else if (wzorzec.m_DataUrodzenia.Porownaj(this->m_DataUrodzenia) != 0) return  -(wzorzec.m_DataUrodzenia.Porownaj(this->m_DataUrodzenia));
	else return 0;
}


