#include "Headers.h"

LongInt::LongInt()
{
	//cout << "empty constr\n";
	num = nullptr;
	length = 0;
}

LongInt::~LongInt()
{
	if (num != nullptr)
		delete[] num;
}

LongInt& LongInt::operator+ (LongInt const& n2)
{
	return *this;
}

LongInt& LongInt::operator- (LongInt const& n2)
{
	//cout << "oper-\n";
	///*if (n2 > *this)
	//{
	//	cout << "minus\n";
	//	LongInt res(n2 - *this);
	//	res.isPosit = false;
	//	return res;
	//}
	//else*/
	//{
	//	cout << "norm\n";
	//	LongInt res(length);
	//	//res.print();
	//	//bool odin = false;
	//	for (int i = 0; i < length; ++i)
	//	{
	//		if (num[i] < n2.num[i])
	//		{
	//			res.num[i] = num[i] + 10 - n2.num[i];
	//			int j = 1;
	//			while (num[i + j] == 0)
	//			{
	//				num[i + j] = 9;
	//				j++;
	//			}
	//			num[i + j]--;

	//		}
	//		else
	//			res.num[i] = num[i] - n2.num[i];
	//	}
	//	cout << "length in op-: " << res.length << endl;

	//	cout << "print in op-\n";
	//	//res.print();
	//	return res;}
	LongInt n;
	return n;
	
}

bool LongInt::operator> (LongInt& n2)
{
	//cout << "oper>\n";
	if (this->isPosit == true && n2.isPosit == false)	//+ > -
		return true;
	if (this->isPosit == false && n2.isPosit == true)	//- > +
		return false;

	bool answer = true;			// + +
	if (this->isPosit == false)	// - -
		answer = false;

	if (length > n2.length)		// +____ > +__
		return answer;
	if (length < n2.length)		// +__ > +____
		return !answer;

	int i = length - 1;

	while (i >= 0)
	{
		if (num[i] > n2.num[i])
			return answer;
		if (num[i] < n2.num[i])
			return !answer;
		i--;
	}
	return false;
}

LongInt::LongInt(LongInt const & num2)
{
	//cout << "constr copy\n";

	length = num2.length;
	num = new int[length];
	isPosit = num2.isPosit;
	for (int i = 0; i < length; ++i)
		num[i] = num2.num[i];

}

LongInt::LongInt(unsigned int size) {
	num = new int[size];
	length = size;
	Zero();
}

LongInt::LongInt(string& number)
{
	//cout << "CONSTR string\n";
	length = number.size();
	int i = 0;
	if (number[i] == '-')
	{
		isPosit = false;
		length--;
		i++;
	}

	num = new int[length];

	for (int j = length - 1; j >= 0; --j)
	{
		//cout << "constr: " << int(number[i] - '0') << endl;
		num[j] = number[i] - '0';
		i++;
	}

}

void LongInt::print(ostream& os) const
{
	//cout << "print\n";
	//cout << "length: " << length << endl;
	if (isPosit == false)
		os << '-';
	for (int i = length-1; i >= 0; --i)
		os << num[i];
	os << '\n';
}

void LongInt::Zero()
{
	for (int i = 0; i < length; ++i)
		num[i] = 0;
	isPosit = true;
}

LongInt& LongInt::operator= (LongInt const& n)
{
	//cout << "operator= \n";
	if (this != &n)
		LongInt(n).swap(*this);
	
	return *this;
}

istream& operator >> (istream& is, LongInt& n)
{
	cout << "Enter a number: ";
	string str;
	cin >> str;
	n = LongInt(str);
	return is;
}

ostream& operator << (ostream& os, const LongInt& n)
{
	if (n.isPosit == false)
		os << '-';
	for (int i = n.length - 1; i >= 0; --i)
		os << n.num[i];
	os << '\n';
	//os << "Length = " << n.length << '\n';

	return os;
}

