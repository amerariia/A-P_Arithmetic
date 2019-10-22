#include "LongInt.h"

LongInt& LongInt::operator+ (LongInt& num2)
{
	return *this;
}

LongInt::LongInt(int size) {
	num = new int[size];
	length = size;
}