#pragma once
#include "Headers.h"
class LongInt
{
	int* num;
	bool isPosit;
	int length;
	LongInt();
	LongInt(int size);
	LongInt(String& s);
};

