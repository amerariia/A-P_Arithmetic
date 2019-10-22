#pragma once
#include "Headers.h"

 class LongInt
{
	int* num;
	bool isPosit = true;
	int length;
public:
	LongInt();
	LongInt(int size);
	LongInt(string& s);
	LongInt(LongInt& n);
	void print();
	void Zero();

	LongInt& operator+ (LongInt& num2);
	LongInt& operator- (LongInt& num2);
	bool operator> (LongInt& num2);
};

