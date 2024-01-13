#include "ListaPracownikow.h"

ListaPracownikow::ListaPracownikow() : m_pPoczatek(nullptr) {
	this->m_nLiczbaPracownikow = 0;
}

ListaPracownikow::~ListaPracownikow()
{
    Pracownik* obecny = m_pPoczatek;
    Pracownik* nastepny = nullptr;

    while (obecny)
    {
        nastepny = obecny->m_pNastepny;
        delete obecny;
        obecny = nastepny;
    }

    m_pPoczatek = nullptr;
    m_nLiczbaPracownikow = 0;
}

void ListaPracownikow::Dodaj(const Pracownik& p)
{
    if (!m_pPoczatek)
    {
        m_pPoczatek = new Pracownik(p);
        m_nLiczbaPracownikow = 1;
        return;
    }
    if (p.Porownaj(*m_pPoczatek) < 0)
    {
        Pracownik* nowyPracownik = new Pracownik(p);
        nowyPracownik->m_pNastepny = m_pPoczatek;
        m_pPoczatek = nowyPracownik;
        m_nLiczbaPracownikow++;
        return;
    }

    Pracownik* obecny = m_pPoczatek;
    Pracownik* poprzedni = nullptr;

    while (obecny && p.Porownaj(*obecny) > 0)
    {
        poprzedni = obecny;
        obecny = obecny->m_pNastepny;
    }

    if (obecny && p.Porownaj(*obecny) == 0)
    {
        return;
    }

    Pracownik* nowyPracownik = new Pracownik(p);
    nowyPracownik->m_pNastepny = obecny;

    if (poprzedni)
        poprzedni->m_pNastepny = nowyPracownik;
    else
        m_pPoczatek = nowyPracownik;

    m_nLiczbaPracownikow++;

}

void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
    Pracownik* obecny = m_pPoczatek;
    Pracownik* poprzedni = nullptr;

    while (obecny)
    {
        if (wzorzec.Porownaj(*obecny) == 0)
        {
            // Znaleziono pracownika do usuniêcia
            if (poprzedni)
                poprzedni->m_pNastepny = obecny->m_pNastepny;
            else
                m_pPoczatek = obecny->m_pNastepny;

            delete obecny;
            m_nLiczbaPracownikow--;
            return;
        }

        poprzedni = obecny;
        obecny = obecny->m_pNastepny;
    }
}

void ListaPracownikow::WypiszPracownikow() const
{
    Pracownik* obecny = m_pPoczatek;

    while (obecny)
    {
        obecny->Wypisz();
        obecny = obecny->m_pNastepny;
        
    }
}

const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie) const
{
    Pracownik* obecny = m_pPoczatek;

    while (obecny)
    {
        if (obecny->SprawdzNazwisko(nazwisko) == 0 && obecny->SprawdzImie(imie) == 0)
        {
            return obecny;
        }

        obecny = obecny->m_pNastepny;
    }

    return nullptr;
}

