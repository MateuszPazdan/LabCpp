#include "ListaPracownikow.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

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
        m_pPoczatek = p.KopiaObiektu();
        m_nLiczbaPracownikow = 1;
        return;
    }
    if (p.Porownaj(*m_pPoczatek) < 0)
    {
        Pracownik* nowyPracownik = p.KopiaObiektu();
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

    Pracownik* nowyPracownik = p.KopiaObiektu();
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
            std::cout << "Usunieto pracownika";
            return;
        }

        poprzedni = obecny;
        obecny = obecny->m_pNastepny;
    }
    std::cout << "Nie znaleziono pracowinka";
}

void ListaPracownikow::WypiszPracownikow() const
{
    Pracownik* obecny = m_pPoczatek;

    while (obecny)
    {
        obecny->WypiszDane();
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

void ListaPracownikow::ZapiszDoPliku(const char* nazwaPliku) const
{

    std::ofstream plik(nazwaPliku);

    if (plik.is_open())
    {
        Pracownik* biezacy = m_pPoczatek;

        while (biezacy != nullptr)
        {
            plik << *(biezacy) << std::endl;
            biezacy = biezacy->m_pNastepny;
        }

        plik.close();
        std::cout << "Zapisano do pliku: " << nazwaPliku << std::endl;
    }
    else
    {
        std::cerr << "B³¹d otwarcia pliku do zapisu." << std::endl;
    }
}

void ListaPracownikow::OdczytZPliku(const char* nazwaPliku)
{
    std::ifstream plik(nazwaPliku);

    if (plik.is_open())
    {
        std::string linia;
        while (std::getline(plik, linia))
        {
            if (!linia.empty())
            {
                std::istringstream iss(linia);
                Pracownik nowyPracownik;
                if (iss >> nowyPracownik)
                {
                    Dodaj(nowyPracownik);
                }
            }
        }
        plik.close();
        std::cout << "Odczytano z pliku: " << nazwaPliku << std::endl;
    }
    else
    {
        std::cerr << "B³¹d otwarcia pliku do odczytu." << std::endl;
    }
}


