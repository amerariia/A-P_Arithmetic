#pragma once
#include "Headers.h"

 class LongInt
{
	int* num;
	
public:
	unsigned int length;
	bool isPosit = true;

	LongInt();
	~LongInt();
	LongInt(unsigned int size);
	LongInt(string& s);
	LongInt(LongInt const & n);
	void Zero();

	LongInt sqrt() const;
	LongInt operator+ (const LongInt& n2) const;
	LongInt operator- (const LongInt& n2) const;
	LongInt operator* (const LongInt& n2) const;
	LongInt operator/ (const LongInt& n2) const;
	LongInt operator% (const LongInt& n2) const;
	LongInt operator^ (const LongInt& n2) const;

	bool operator> (const LongInt& n2) const;
	bool operator==(const LongInt& n2) const;
	bool operator< (const LongInt& n2) const;
	LongInt& operator= (LongInt const & n);
	friend  ostream& operator << (ostream& os, const LongInt& num);
	friend istream& operator >> (istream& is, LongInt& num);


	void swap(LongInt& b)
	{
		std::swap(length, b.length);
		std::swap(num, b.num);
		std::swap(isPosit, b.isPosit);
	}
};

 