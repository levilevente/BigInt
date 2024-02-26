#pragma once
#include <iostream>

using namespace std;

void init(int& uj_meret, int*& uj_szam, int elso_meret, int elso_elojel, int*& elso_szam, int masodik_meret, int masodik_elojel, int*& masodik_szam, int* ELSO, int* MASODIK, int& index_elso, int& index_masodik, int& index_uj)
{
	uj_meret = max(elso_meret, masodik_meret);
	uj_szam = new int[uj_meret] {0};
	index_elso = elso_meret - 1;
	index_masodik = masodik_meret - 1;
	index_uj = uj_meret - 1;
	elso_szam = new int[elso_meret] {0};
	for (int i = 0; i < elso_meret; i++)
	{
		elso_szam[i] = ELSO[i];
	}
	masodik_szam = new int[masodik_meret] {0};
	for (int i = 0; i < masodik_meret; i++)
	{
		masodik_szam[i] = MASODIK[i];
	}
}

int melyik_nagyobb(int n, int* a, int m, int* b)
{
	if (n > m)
	{
		return 1;
	}
	else
	{
		if (n < m)
		{
			return 2;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] > b[i])
				{
					return 1;
				}
				if (a[i] < b[i])
				{
					return 2;
				}
			}
			return 3;
		}
	}
}
