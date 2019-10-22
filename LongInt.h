#pragma once
#include "Headers.h"

class LongInt
{
	int* num;
	bool isPosit;
	int length;

	LongInt();
	LongInt(int size);
	LongInt(string& s);

	LongInt& operator+ (LongInt& num2);
};

