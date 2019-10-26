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
	void print(ostream& os) const;
	void Zero();

	LongInt& operator+ (LongInt const& n2);
	LongInt& operator- (LongInt const& n2);
	//LongInt& operator* (LongInt const& n2);
	bool operator> (LongInt& num2);
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

 