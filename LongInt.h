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

	void print();
	void Zero();

	LongInt& operator+ (LongInt& num2);
};

