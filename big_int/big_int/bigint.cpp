#include "bigint.h"
#include "seged.h"
#include <iostream>

using namespace std;

bigint::bigint()
{
	//szam = NULL;
	szam = new int[1] {0};
	meret = 0;
	elojel = 0;
}

bigint::bigint(int elojel, int n, const int* szamjegyek)
{
	this->elojel = elojel;
	meret = n;
	if (elojel == 0 || meret == 0)
	{
		//szam = NULL;
		szam = new int[1] {0};
		meret = 0;		//ez csak azert kell, hogy ne tudjon a felhasznalo akarmit beirni
	}
	else
	{
		szam = new int[n] {0};
		for (int i = 0; i < n; i++)
		{
			szam[i] = szamjegyek[i];
		}
	}
}

bigint::bigint(const bigint& a)
{
	this->elojel = a.elojel;
	this->meret = a.meret;
	if (a.elojel == 0 || a.meret == 0)
	{
		//this->szam = NULL;
		this->szam = new int [1] {0};
	}
	else
	{
		this->szam = new int[a.meret] {0};
		for (int i = 0; i < a.meret; i++)
		{
			this->szam[i] = a.szam[i];
		}
	}
}

bigint::bigint(int n)
{
	if (n == 0)
	{
		elojel = 0;
		//szam = NULL;
		szam = new int[1] {0};
		meret = 0;
		return;
	}
	else
	{
		if (n > 0)
		{
			elojel = 1;
		}
		else
		{
			elojel = -1;
		}
	}
	unsigned long long int n_cpy = 0;
	meret = 0;
	while (n != 0)
	{
		if (elojel == -1)
		{
			n_cpy = (n_cpy * 10) + (n % 10) * -1;
		}
		else
		{
			n_cpy = (n_cpy * 10) + n % 10;
		}
		n = n / 10;
		meret++;
	}

	szam = new int [meret] {0};
	for (int i = 0; i < meret; i++)
	{
		szam[i] = n_cpy % 10;
		n_cpy /= 10;
	}
}

bigint::bigint(long long int n)
{
	if (n == 0)
	{
		elojel = 0;
		//szam = NULL;
		szam = new int [1] {0};
		meret = 0;
		return;
	}
	else
	{
		if (n > 0)
		{
			elojel = 1;
		}
		else
		{
			elojel = -1;
		}
	}
	unsigned long long int n_cpy = 0;
	meret = 0;
	while (n != 0)
	{
		if (elojel == -1)
		{
			n_cpy = (n_cpy * 10) + (n % 10) * -1;
		}
		else
		{
			n_cpy = (n_cpy * 10) + n % 10;
		}
		n = n / 10;
		meret++;
	}

	szam = new int [meret] {0};
	for (int i = 0; i < meret; i++)
	{
		szam[i] = n_cpy % 10;
		n_cpy /= 10;
	}
}

bigint::~bigint()
{
	delete[]szam;
}

ostream& operator<<(ostream& s, const bigint& a)
{
	if (a.elojel == -1)
	{
		s << "-";
	}
	else
	{
		if (a.elojel == 0)
		{
			s << 0;
			s << endl;
			return s;
		}
	}
	for (int i = 0; i < a.meret; i++)
	{
		s << a.szam[i];
	}
	return s;
};

bigint& bigint::operator=(const bigint& a)
{

	if (this != &a)
	{
		if (meret != 0)
		{
			delete[] szam;
		}
		meret = a.meret;
		elojel = a.elojel;


		if (a.meret == 0)	//ez a resz negyon kell
		{
			szam = new int[1] {0};
		}
		else
		{
			szam = new int[a.meret] {0};
		}


		for (int i = 0; i < meret; i++)
		{
			szam[i] = a.szam[i];
		}
	}
	return *this;
}

bigint bigint::operator+(const bigint& a)
{
	int uj_elojel;
	if (elojel == 1)
	{
		if (a.elojel == 1)
		{
			uj_elojel = 1;
		}
		else if (a.elojel == -1)
		{
			bigint uj = a;
			uj.elojel = 1;
			return *this - uj;
		}
		else
		{
			bigint uj = *this;
			return uj;
		}

	}
	else if (elojel == -1)
	{
		if (a.elojel == 1)
		{
			bigint uj = *this;
			uj.elojel = 1;
			bigint aa(a);
			return aa - uj;
		}
		else if (a.elojel == -1)
		{
			uj_elojel = -1;
		}
		else
		{
			bigint uj = *this;
			return uj;
		}
	}
	else
	{
		if (a.elojel == 1)
		{
			bigint uj = a;
			return uj;
		}
		else if (a.elojel == -1)
		{
			bigint uj = a;
			return uj;
		}
		else
		{
			bigint uj(0);
			return uj;
		}
	}

	int uj_meret = std::max(meret, a.meret);
	if (elojel != a.elojel)
	{
		uj_meret++;
	}
	int* uj_szam = new int[uj_meret] { 0 };
	int index_elso = meret - 1, index_masodik = a.meret - 1;
	int index_eredmeny = uj_meret - 1;
	int carry = 0;
	while (index_elso >= 0 && index_masodik >= 0)
	{
		int sum = carry + szam[index_elso] + a.szam[index_masodik];
		if (sum > 9)
		{
			carry = 1;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}
		uj_szam[index_eredmeny] = sum;
		index_elso--;
		index_masodik--;
		index_eredmeny--;
	}
	while (index_elso >= 0)
	{
		int sum = carry + szam[index_elso];
		if (sum > 9)
		{
			carry = 1;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}
		uj_szam[index_eredmeny] = sum;
		index_elso--;
		index_eredmeny--;
	}
	while (index_masodik >= 0)
	{
		int sum = carry + a.szam[index_masodik];
		if (sum > 9)
		{
			carry = 1;
			sum = sum % 10;
		}
		else
		{
			carry = 0;
		}
		uj_szam[index_eredmeny] = sum;
		index_masodik--;
		index_eredmeny--;
	}

	if (carry == 1)
	{
		int* uj_szam_carry = new int[uj_meret + 1] {0};
		uj_szam_carry[0] = carry;
		for (int i = 1; i <= uj_meret; i++)
		{
			uj_szam_carry[i] = uj_szam[i - 1];
		}
		delete[] uj_szam;
		bigint uj(uj_elojel, uj_meret + 1, uj_szam_carry);
		delete[] uj_szam_carry;
		return uj;
	}
	else
	{
		int offset = 0;
		while (uj_szam[offset] == 0)
		{
			offset++;
		}

		if (offset == uj_meret)
		{
			bigint uj(0);
			return uj;
		}
		for (int i = 0; i < uj_meret - offset; i++)
		{
			uj_szam[i] = uj_szam[i + offset];
		}
		uj_meret -= offset;

	}
	bigint uj(uj_elojel, uj_meret, uj_szam);
	delete[]uj_szam;

	return uj;
}

bigint bigint::operator-(const bigint& a)
{
	int uj_meret = 0, uj_elojel = 0;
	int* uj_szam = NULL;
	int* temp_szam = NULL;
	int* temp_szam_a = NULL;
	int index_elso, index_masodik, index_uj = 0;
	index_elso = 1;
	index_masodik = 1;

	if (elojel == 1)	//elso pozitiv
	{
		if (a.elojel == 1)	//mind2 pozitiv
		{
			if (melyik_nagyobb(meret, szam, a.meret, a.szam) == 1)
			{
				uj_elojel = 1;
				init(uj_meret, uj_szam, meret, elojel, temp_szam, a.meret, a.elojel, temp_szam_a, szam, a.szam, index_elso, index_masodik, index_uj);
			}
			else if (melyik_nagyobb(meret, szam, a.meret, a.szam) == 2)
			{
				uj_elojel = -1;
				init(uj_meret, uj_szam, meret, elojel, temp_szam_a, a.meret, a.elojel, temp_szam, szam, a.szam, index_masodik, index_elso, index_uj);
			}
			else
			{
				bigint uj(0);
				return uj;
			}
		}
		else if (a.elojel == -1)	//masodik negativ
		{
			bigint uj(a);
			uj.elojel = 1;
			return *this + uj;
		}
		else						//masodik 0;
		{
			bigint uj(*this);
			return uj;				//????????????????????????????????????????????
		}
	}
	else if (elojel == -1)	//elso negativ
	{
		if (a.elojel == 1)	//masodik pozitiv
		{
			uj_elojel = -1;
			bigint elso = *this;
			elso.elojel = 1;
			bigint masodik = a;
			bigint uj = elso + masodik;
			uj.elojel = -1;
			return uj;
		}
		else if (a.elojel == -1)	//masodik negativ
		{
			if (melyik_nagyobb(meret, szam, a.meret, a.szam) == 1) // ha az elso nagyobb : -1234   >   -123
			{
				uj_elojel = -1;
				init(uj_meret, uj_szam, meret, elojel, temp_szam, a.meret, a.elojel, temp_szam_a, szam, a.szam, index_elso, index_masodik, index_uj);
			}
			else if (melyik_nagyobb(meret, szam, a.meret, a.szam) == 2)														//ha a masodik nagyobb: -123 < -1234
			{
				uj_elojel = 1;
				init(uj_meret, uj_szam, meret, elojel, temp_szam_a, a.meret, a.elojel, temp_szam, szam, a.szam, index_masodik, index_elso, index_uj);
			}
			else
			{
				bigint uj(0);
				return uj;
			}
		}
		else						//masodik 0
		{
			bigint uj(*this);
			return uj;
		}
	}
	else		//elso 0
	{
		if (a.elojel == 1)	//masodik pozitiv
		{
			bigint uj(a);
			uj.elojel = -1;
			return uj;
		}
		else if (a.elojel == -1)	//masodik negativ
		{
			bigint uj(a);
			uj.elojel = 1;
			return uj;
		}
		else
		{
			bigint uj(0);
			return uj;
		}
	}


	while (index_elso >= 0 && index_masodik >= 0)
	{
		if (temp_szam[index_elso] >= temp_szam_a[index_masodik])
		{
			uj_szam[index_uj] = temp_szam[index_elso] - temp_szam_a[index_masodik];
		}
		else
		{
			int i = index_elso - 1;
			while (temp_szam[i] == 0 && i >= 0)
			{
				i--;
			}
			if (i >= 0)
			{
				temp_szam[i]--;
				for (int j = i + 1; j < index_elso; j++)
				{
					temp_szam[j] = 9;
				}
				uj_szam[index_uj] = 10 - temp_szam_a[index_masodik] + temp_szam[index_elso];
			}
		}
		index_uj--;
		index_elso--;
		index_masodik--;
	}

	while (index_elso >= 0)
	{
		uj_szam[index_uj] = temp_szam[index_elso];
		index_elso--;
		index_uj--;
	}

	while (index_masodik >= 0)
	{
		uj_szam[index_uj] = temp_szam_a[index_masodik];
		index_masodik--;
		index_uj--;
	}


	int offset = 0;
	while (uj_szam[offset] == 0)
	{
		offset++;
	}

	if (offset == uj_meret)
	{
		bigint uj(0);

		delete[]temp_szam;
		delete[]uj_szam;

		return uj;
	}
	for (int i = 0; i < uj_meret - offset; i++)
	{
		uj_szam[i] = uj_szam[i + offset];
	}
	uj_meret -= offset;
	bigint uj(uj_elojel, uj_meret, uj_szam);

	delete[]temp_szam;
	delete[]uj_szam;

	return uj;
}

bigint bigint::operator*(const bigint& a)
{

	int uj_elojel = 0;
	if (elojel == -1)
	{
		if (a.elojel == -1)
		{
			uj_elojel = 1;
		}
		else if (a.elojel == 1)
		{
			uj_elojel = -1;
		}
		else
		{
			bigint uj(0);
			return uj;
		}
	}
	else if (elojel == 1)
	{
		if (a.elojel == -1)
		{
			uj_elojel = -1;
		}
		else if (a.elojel == 1)
		{
			uj_elojel = 1;
		}
		else
		{
			bigint uj(0);
			return uj;
		}
	}
	else
	{
		bigint uj(0);
		return uj;
	}
	bigint elso(*this);
	bigint masodik(a);

	int* temp = new int[meret + a.meret]();
	int i, j, carry, prod;

	for (i = meret - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = a.meret - 1; j >= 0; j--) {
			prod = elso.szam[i] * masodik.szam[j] + carry + temp[i + j + 1];
			carry = prod / 10;
			temp[i + j + 1] = prod % 10;
		}
		temp[i + j + 1] += carry;
	}

	int k = 0;
	while (k < meret + a.meret && temp[k] == 0)
	{
		k++;
	}
	if (k != 0)
	{
		for (int i = 0; i < meret + a.meret - k; i++)
		{
			temp[i] = temp[i + k];
		}
	}

	int* uj_szam = new int[meret + a.meret - k] {0};

	for (i = 0; i < meret + a.meret - k; i++)
	{
		uj_szam[i] = temp[i];
	}
	int uj_meret = meret + a.meret - k;
	delete[] temp;

	bigint uj(uj_elojel, uj_meret, uj_szam);
	delete[]uj_szam;
	return uj;
}

bigint bigint::operator/(const bigint& a)
{
	bigint uj(0);
	int uj_elojel = 0;
	if (this->elojel == a.elojel && elojel != 0)	//ha mind2 ugyanolyan elojelu az eredmeny pozitiv
	{
		uj_elojel = 1;
	}
	else
	{
		if (a.elojel == 0 || a.meret == 0)		//ha az oszto 0 akkor throw
		{
			throw NullavalValoOsztas();
		}
		if (this->elojel == 0 || this->meret == 0)	//ha az osztando 0 akkor
		{

			uj = 0;
			return uj;
		}
		else
		{
			if (this->elojel != a.elojel)
			{
				uj_elojel = -1;
			}
		}
	}

	int ki = melyik_nagyobb(this->meret, this->szam, a.meret, a.szam);
	if (ki == 2)
	{
		uj.elojel = 0;
		uj.meret = 0;
		return uj;
	}
	else if (ki == 3)
	{
		uj = 1;
		return uj;
	}

	if (a == bigint(1))
	{
		uj = *this;
		return uj;
	}

	bigint elso(*this);
	bigint masodik(a);
	elso.elojel = 1;
	masodik.elojel = 1;

	int* uj_szam = new int[elso.meret] {0};
	int uj_meret = 0;

	int lehozom = 0;


	int elos_meret = elso.meret;

	int* piros = new int[elso.meret] {0};
	int index_piros = 0;
	while (bigint(1, index_piros, piros) < masodik)
	{
		piros[index_piros] = elso.szam[lehozom];
		lehozom++;
		index_piros++;
	}

	while (lehozom <= elso.meret)
	{
		int hany = 0;
		bigint sarga(0);
		while (sarga + masodik <= bigint(1, index_piros, piros))
		{
			sarga += masodik;
			hany++;
		}

		uj_szam[uj_meret] = hany;
		uj_meret++;

		bigint kek(bigint(1, index_piros, piros) - sarga);

		index_piros = 0;
		for (int i = 0; i < kek.meret; i++)
		{
			piros[index_piros] = kek.szam[i];
			index_piros++;
		}
		piros[index_piros] = elso.szam[lehozom];
		lehozom++;
		index_piros++;
		if (piros[0] == 0)
		{
			index_piros = 0;
		}
	}



	/*int offset = 0;
	while (uj_szam[offset] == 0)
	{
		offset++;
	}

	if (offset == uj_index)
	{
		bigint uj(0);
		return uj;
	}
	for (int i = 0; i < uj_index - offset; i++)
	{
		uj_szam[i] = uj_szam[i + offset];
	}
	uj_index -= offset;*/
	//uj = bigint(1, uj_index, uj_szam);
	uj = bigint(uj_elojel, uj_meret, uj_szam);
	return uj;

}

bigint bigint::pow2()
{
	bigint uj = *this * *this;
	*this = uj;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint regi(*this);
	*this = *this + bigint(1);
	return regi;
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator--(int)
{
	bigint regi(*this);
	*this = *this - bigint(1);
	return regi;
}

bigint& bigint::operator--()
{
	*this = *this - bigint(1);
	return *this;
}

bigint& bigint::operator+=(const bigint& a)
{
	return *this = *this + a;
}

bigint& bigint::operator-=(const bigint& a)
{
	return *this = *this - a;
}

bigint& bigint::operator*=(const bigint& a)
{
	return *this = *this * a;
}

bigint& bigint::operator/=(const bigint& a)
{
	if (a.elojel == 0 || a.meret == 0)		//ha az oszto 0 akkor throw
	{
		throw NullavalValoOsztas();
	}
	return *this = *this / a;
}

bool bigint::operator<(const bigint& a)const
{
	if (elojel == -1)
	{
		if (a.elojel == 1)
		{
			return true;
		}
		else if (a.elojel == 0)
		{
			return true;
		}
		else
		{
			int melyik = melyik_nagyobb(meret, szam, a.meret, a.szam);
			if (melyik == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (elojel == 0)
	{
		if (a.elojel == 1)
		{
			return true;
		}
		else if (a.elojel == 0)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (a.elojel == 1)
		{
			int melyik = melyik_nagyobb(meret, szam, a.meret, a.szam);
			if (melyik == 2)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (a.elojel == 0)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
}

bool bigint::operator>(const bigint& a)const
{
	if (*this < a || *this == a)
	{
		return false;
	}
	return true;
}

bool bigint::operator==(const bigint& a)const
{
	if (elojel != a.elojel)
	{
		return false;
	}

	if (elojel == 0)
	{
		return true;
	}
	int melyik = melyik_nagyobb(meret, szam, a.meret, a.szam);
	if (melyik == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool bigint::operator<=(const bigint& a)const
{
	if (elojel == -1)
	{
		if (a.elojel == 1)
		{
			return true;
		}
		else if (a.elojel == 0)
		{
			return true;
		}
		else
		{
			int melyik = melyik_nagyobb(meret, szam, a.meret, a.szam);
			if (melyik == 1 || melyik == 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else if (elojel == 0)
	{
		if (a.elojel == 1)
		{
			return true;
		}
		else if (a.elojel == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (a.elojel == 1)
		{
			int melyik = melyik_nagyobb(meret, szam, a.meret, a.szam);
			if (melyik == 2 || melyik == 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (a.elojel == 0)
		{
			return false;
		}
		else
		{
			return false;
		}
	}
}

bool bigint::operator>=(const bigint& a)const
{
	if (*this < a)
	{
		return false;
	}
	return true;
}

bool bigint::operator!=(const bigint& a)const
{
	if (*this == a)
	{
		return false;
	}
	return true;
}

bigint bigint::min(const bigint& a, const bigint& b)
{
	if (a > b)
	{
		return b;
	}
	return a;
}

bigint bigint::max(const bigint& a, const bigint& b)
{
	if (a < b)
	{
		return b;
	}
	return a;
}