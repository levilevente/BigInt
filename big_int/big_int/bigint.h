#ifndef BIG_INT_DEFF
#define BIG_INT_DEFF
#include <iostream>

using namespace std;

class bigint {

	int* szam;
	int meret;
	int elojel;

public:

	//KONSTRUKTOROK:

	bigint();
	bigint(int, int, const int*);
	bigint(const bigint&);
	bigint(int);
	bigint(long long int);

	//DESTRUKTOR:

	~bigint();

	//OPERATOR TULTERHELESEK:

		//kiirato
	friend ostream& operator<<(ostream& s, const bigint& a);


	//ertekadado operator
	bigint& operator=(const bigint&);

	//muveletek
	bigint operator+(const bigint&);
	bigint operator-(const bigint&);
	bigint operator*(const bigint&);
	bigint operator/(const bigint&);
	bigint pow2();

	//novelesek/csokkentesek  1-el
	bigint operator++(int);
	bigint& operator++();
	bigint operator--(int);
	bigint& operator--();

	//rovid novelesek/csokkentesek
	bigint& operator+=(const bigint&);
	bigint& operator-=(const bigint&);
	bigint& operator*=(const bigint&);
	bigint& operator/=(const bigint&);

	//hasonlito operatorok
	bool operator<(const bigint&)const;
	bool operator>(const bigint&)const;
	bool operator==(const bigint&)const;
	bool operator<=(const bigint&)const;
	bool operator>=(const bigint&)const;
	bool operator!=(const bigint&)const;
	bigint min(const bigint&, const bigint&);
	bigint max(const bigint&, const bigint&);

	//KIVETELKEZELES

	class NullavalValoOsztas {};

};

#endif // !BIG_INT_DEFF