#define _CRT_SECURE_NO_WARNINGS 1
#include "Napis.h"
#include <iostream>
#include <string.h>

Napis::Napis(const Napis& wzor)
{
	this->Ustaw(wzor.m_pszNapis);
}

Napis::Napis(const char* nowyNapis)
{
	Ustaw(nowyNapis);
}

Napis::~Napis()
{
	this->m_nDl = 0;
	delete m_pszNapis;
}

Napis& Napis::operator=(const Napis& wzor)
{
	this->~Napis();
	new (this) Napis(wzor);
	return *this;
}

const char* Napis::Zwroc() const
{
	return this->m_pszNapis;
}

void Napis::Ustaw(const char* nowy_napis)
{
	this->~Napis();
	this->m_nDl = strlen(nowy_napis) + 1;
	this->m_pszNapis = new char[this->m_nDl];
	strcpy(this->m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	std::cout << m_pszNapis;
}

void Napis::Wpisz()
{
	char buffer[40];
	std::cin >> buffer;
	this->Ustaw(buffer);
}

int Napis::SprawdzNapis(const char* por_napis) const
{
	return strcmp(m_pszNapis, por_napis);
}
