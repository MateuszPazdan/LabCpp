#include "Data.h"
#include <iostream>

void Data::Koryguj()
{
	if (m_nMiesiac > 12) m_nMiesiac = 12;
	else if (m_nMiesiac < 1) m_nMiesiac = 1;
	if (m_nDzien < 1) m_nDzien = 1;
	else if (((m_nMiesiac <= 7 && m_nMiesiac % 2 == 1) || (m_nMiesiac > 7 && m_nMiesiac % 2 == 0)) && m_nDzien > 31) m_nDzien = 31;
	else if (((m_nMiesiac <= 7 && m_nMiesiac % 2 == 0 && m_nMiesiac != 2) || (m_nMiesiac > 7 && m_nMiesiac % 2 == 1)) && m_nDzien > 30) m_nDzien = 30;
	else if (m_nMiesiac == 2 && m_nRok % 4 == 0 && m_nRok % 400 != 0 && m_nDzien > 29) m_nDzien = 29;
	else if (m_nMiesiac == 2 && m_nDzien > 28) m_nDzien = 28;
}

Data::Data(int d, int m, int r)
{
	this->Ustaw(d, m, r);
}

void Data::Ustaw(int d, int m, int r)
{
	this->m_nDzien = d;
	this->m_nMiesiac = m;
	this->m_nRok = r;
	Koryguj();
}

int Data::Dzien() const
{
	return this->m_nDzien;
}

int Data::Miesiac() const
{
	return this->m_nMiesiac;
}

int Data::Rok() const
{
	return this->m_nRok;
}

void Data::Wypisz() const
{
	std::cout << this->m_nDzien << "-" << this->m_nMiesiac << "-" << this->m_nRok << " ";
}

void Data::Wpisz()
{
	int d, m, r;
	std::cin >> d >> m >> r;
	Ustaw(d,m,r);
}

int Data::Porownaj(const Data& wzor) const
{
	// 0 jesli pola sa identyczne 
	// 1 gdy data wzorca jest pozniejsza od this
	// -1 w przeciwnym wypadku gdy data wzorca jest wczesniejsza od daty obiektu
	if (this->m_nDzien == wzor.Dzien() && this->m_nMiesiac == wzor.Miesiac() && this->m_nRok == wzor.Rok()) return 0;
	else if (wzor.Rok() > this->m_nRok || (wzor.Rok() == this->m_nRok && wzor.m_nMiesiac > this->Miesiac()) || (wzor.Rok() == this->m_nRok && wzor.m_nMiesiac == this->Miesiac() && wzor.m_nDzien > this->Dzien())) return -1;
	else return 1;
}

