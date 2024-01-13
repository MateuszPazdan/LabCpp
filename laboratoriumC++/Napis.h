#pragma once
class Napis
{
private:
	char* m_pszNapis;
	int m_nDl;
public:
	Napis(const Napis& wzor);
	Napis(const char* nowyNapis = "");
	~Napis();
	Napis& operator=(const Napis& wzor);
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;
};

