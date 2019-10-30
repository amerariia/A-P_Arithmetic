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

	try {
		num = new char[length];
	}
	catch(bad_alloc& ex)
	{
		cout << "bad_alloc\n";
		cout << ex.what();
	}
	catch (...)
	{
		cout << "pizdec!";
	}
	for (int j = length - 1; j >= 0; --j)
	{
		num[j] = number[i] - '0';
		i++;
	}

}

LongInt LongInt::sqrt() const
{
	string s0 = "0", s1 = "1";
	LongInt zero(s0);
	LongInt one(s1);
	LongInt r(s0), r2(s0);

	if (*this < zero)
		throw exception("inv_arg");

	while(r2 < *this)
	{
		r = r + one;
		r2 = r * r;
	}

	if (r2 == *this)
		return r;
	else
		return r - one;
}

LongInt LongInt::operator+ (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == false)
	{
		LongInt n(n2);
		n.isPosit = true;
		return *this - n;
	}
	if (this->isPosit == false && n2.isPosit == true)
	{
		LongInt n(*this);
		n.isPosit = true;
		return n2 - n;
	}

	if (this->isPosit == true && n2.isPosit == true)
	{
		if (*this < n2)
			return n2 + *this;

		LongInt r1(this->length + 1);
		LongInt n1(this->length + 1);
		for (int i = 0; i < length; ++i)
			n1.num[i] = this->num[i];


		int i;
		for (i = 0; i < n2.length; ++i)
		{
			if (n1.num[i] + n2.num[i] > 9)
			{
				int j = i + 1;
				while (n1.num[j] == 9 && j < length + 1)
				{
					n1.num[j] = 0;
					j++;
				}
				n1.num[j]++;
			}
			r1.num[i] = (n1.num[i] + n2.num[i]) % 10;
		}

		for (i; i < length + 1; ++i)
			r1.num[i] = n1.num[i];

		int j = r1.length - 1;
		while (r1.num[j] == 0 && j >= 0)
			j--;

		if (j != r1.length - 1)
		{
			r1.length = j + 1;
			LongInt r(r1);
			return r;
		}

		return r1;

	}

	if (this->isPosit == false && n2.isPosit == false)
	{
		LongInt n_1(*this);
		n_1.isPosit = true;
		LongInt n_2(n2);
		n_2.isPosit = true;
		LongInt r = n_1 + n_2;
		r.isPosit = false;
		return r;
	}

	LongInt n = n2;
	return n;
}

LongInt LongInt::operator- (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == false)
	{
		LongInt n(n2);
		n.isPosit = true;
		return *this + n;
	}

	if (this->isPosit == false && n2.isPosit == true)
	{
		LongInt n(*this);
		n.isPosit = true;
		LongInt r = n + n2;
		r.isPosit = false;
		return r;
	}

	if (this->isPosit == true && n2.isPosit == true)
	{
		if (*this < n2)
		{
			LongInt r = n2 - *this;
			r.isPosit = false;
			return r;
		}
		else
			if (*this == n2)
			{
				string str = "0";
				LongInt r(str);
				return r;
			}
		// n1 > n2

		LongInt r1(this->length);
		LongInt n1(*this);
		int i;
		for (i = 0; i < n2.length; ++i)
		{
			if (n1.num[i] < n2.num[i])
			{
				n1.num[i] += 10;
				int j = i + 1;
				while (n1.num[j] == 0 && j < length)
				{
					n1.num[j] = 9;
					j++;
				}
				n1.num[j]--;
			}
			r1.num[i] = n1.num[i] - n2.num[i];
		}

		for (i; i < length; ++i)
			r1.num[i] = n1.num[i];

		int j = length - 1;
		while (r1.num[j] == 0 && j > 0)
			j--;

		if (j != length - 1)
		{
			r1.length = j + 1;
			LongInt r(r1);
			return r;
		}

		return r1;
		
	}

	if (this->isPosit == false && n2.isPosit == false)
	{
		LongInt n_1(*this);
		LongInt n_2(n2);

		n_1.isPosit = true;
		n_2.isPosit = true;
		return n_2 - n_1;
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

LongInt LongInt::operator^ (const LongInt& n2) const
{
	string str = "0";
	string str1 = "1";
	string str2 = "2";
	LongInt r(str1); //result
	LongInt odun(str1);
	LongInt dwa(str2);
	LongInt n_2(n2);	
	LongInt zero(str);

	if (n_2 < zero)
	{
		throw exception();
	}
	if (this->isPosit == true)
	{
		while (n_2 > zero)
		{			
			r = r * *this;
			n_2 = n_2 - odun;
		}
		return r;
	}
	else
	{
		if (n_2 % dwa == odun)
		{
			LongInt n_1(*this);
			n_1.isPosit = true;
			r = n_1 ^ n_2;
			r.isPosit = false;
			return r;
		}
		else
		{
			LongInt n_1(*this);
			n_1.isPosit = true;
			return n_1 ^ n_2;
		}
	}

}

LongInt LongInt::operator* (const LongInt& n2) const
{
	if (this->isPosit == true && n2.isPosit == true)
	{
		string str = "0";
		string str1 = "1";
		LongInt r(str); //result
		LongInt n_1(*this);
		LongInt odun(str1);
		LongInt zero(str);
		while (n_1 > zero)
		{
			r = r + n2;
			n_1 = n_1 - odun;
		}
		return r;
	}
	
	if (this->isPosit == false && n2.isPosit == true)
	{
		LongInt n_1(*this);
		n_1.isPosit = true;
		LongInt r = n_1 * n2;
		r.isPosit = false;
		return r;
	}

	if (this->isPosit == true && n2.isPosit == false)
	{
		LongInt n_2(n2);
		n_2.isPosit = true;
		LongInt r = *this * n_2;
		r.isPosit = false;
		return r;
	}

	if (this->isPosit == false && n2.isPosit == false)
	{
		LongInt n_1(*this);
		LongInt n_2(n2);

		n_1.isPosit = true;
		n_2.isPosit = true;
		return n_2 * n_1;
	}
}

LongInt LongInt::operator/ (const LongInt& n2) const
{
	string num = "0", str1 = "1";

	LongInt result;
	LongInt left(*this);
	LongInt right(n2);
	LongInt zero(num);
	LongInt one(str1);
	
	bool sign = (left.isPosit && !right.isPosit) || (!left.isPosit && right.isPosit); //if the result is negative
	left.isPosit = true;
	right.isPosit = true;

	if (right == zero)
		throw exception("Divide by zero");
	if (right > left)
		return zero;
	else
	{
		LongInt div = zero;
		while (left > right || left == right)
		{
			div = div + one;
			left = left - right;
		}
		result = div;
 	}

	result.isPosit = !sign;
	return result;
}

LongInt LongInt::operator% (const LongInt& n2) const
{
	string s = "0";
	LongInt zero(s);
	if (n2 == zero || n2 < zero || *this < zero)
		throw exception();
	LongInt left(*this);
	LongInt right(n2);

	return left - (left / right) * right;
}

LongInt LongInt ::AddByMod(LongInt& n1, LongInt& n2, LongInt& n)
{
	
	LongInt result = n1 + n2;

	if (result < n)
		return result;
	else
	{
		return (result - n);
	}

}

LongInt LongInt::SubByMod(LongInt& n1, LongInt& n2, LongInt& n)
{
	string str = "0";
	LongInt zero(str);

	LongInt result = n1 - n2;

	if (result < zero)
		return result + n;
	else
		return result;

}

LongInt LongInt::MultByMod(LongInt& n1, LongInt& n2, LongInt& n)
{
	//string str = "0";
	LongInt tmp = n1 * n2;
	
	return tmp - (tmp) / n * n;

}

LongInt LongInt::DivByMod(LongInt& n1, LongInt& n2, LongInt& n)
{	
	LongInt a(n1);
	LongInt mult = FindMultiply(n2, n);
	LongInt result = a * mult;

	return result;
}

LongInt LongInt::FindMultiply(LongInt& b, LongInt& m)
{
	string str = "0", str1 = "1";
	LongInt zero(str);
	LongInt one = (str1);

	LongInt x1(one);
	LongInt x2(zero);
	LongInt x3 = m;
	LongInt y1(zero);
	LongInt y2(one);
	LongInt y3 = b;

	LongInt g;
	LongInt t1;
	LongInt t2;
	LongInt t3;

	while (true)
	{
		if (y3 == zero)
			throw exception();
		if (y3 == one)
		{
			if (y2 < zero)
				return y2 + m;
			else
				return y2;
		}

		g = x3 / y3;
		t1 = x1 - g * y1;
		t2 = x2 - g * y2;
		t3 = x3 - g * y3;

		x1 = y1;
		x2 = y2;
		x3 = y3;

		y1 = t1;
		y2 = t2;
		y3 = t3;
	}

}

bool LongInt::operator> (const LongInt& n2) const
{
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

bool LongInt::operator== (const LongInt& n2) const
{
	if (this->isPosit != n2.isPosit || this->length != n2.length)
		return false;

	int i = length - 1;

	while (i >= 0)
	{
		if (num[i] != n2.num[i])
			return false;
		i--;
	}

	return true;
}

bool LongInt::operator< (const LongInt& n2) const
{
	if (*this == n2)
		return false;
	return !(*this > n2);
}


LongInt::LongInt(const LongInt& num2)
{
	//cout << "constr copy\n";

	length = num2.length;
	try {
		num = new char[length];
	}
	catch (bad_alloc& ex)
	{
		cout << ex.what();
	}
	catch (...)
	{
		cout << "pizdec!";
	}
	isPosit = num2.isPosit;
	for (int i = 0; i < length; ++i)
		num[i] = num2.num[i];

}

LongInt::LongInt(unsigned int size) 
{
	try {
		num = new char[size];
	}
	catch (bad_alloc& ex)
	{
		cout << ex.what();
	}
	catch(...)
	{
		cout << "pizdec!";
	}
	length = size;
	Zero();
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
		os << static_cast<int>(n.num[i]);
	os << '\n';

	return os;
}

void LongInt::porevnyanna()
{
	const int N = 100;
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	string str;
	int i = 0;
	cout << "enter a, b, c for      ax = b(mod c)" << endl;
	while (cin >> A[i] >> B[i] >> C[i])
	{
		cout << A[i] << "x = " << B[i] << "(mod " << C[i] << ")" << endl;
		cin.clear();
		i++;
	}
	cout << endl;
	int length = i;
	int M = 1;
	int* Meme = new int[length];
	int* Nene = new int[length];
	int* Q = new int[length];

	for (i = 0; i < length; i++)
	{
		Q[i] = 1;
		if (A[i] == 1)
		{
			break;
		}
		else
		{
			while ((B[i] % A[i]) != 0)
			{
				B[i] = B[i] + C[i];
			}
			B[i] = B[i] / A[i];
			A[i] = 1;

		}
		cout << A[i] << "x = " << B[i] << "(mod " << C[i] << ")" << endl;
		M = M * C[i];
	}
	/////////////////
	for (i = 0; i < length; i++)
	{
		Meme[i] = M / C[i];
		cout << "M[" << i << "] " << "N[" << i << "] = " << Q[i] << "(mod " << C[i] << ")" << endl;
	}
	////////////////
	for (i = 0; i < length; i++)
	{
		cout << Meme[i] << " N[" << i << "] " << " = " << Q[i] << "(mod " << C[i] << ")" << endl;
	}
	////////////////

	for (i = 0; i < length; i++)
	{
		while ((Q[i] % Meme[i]) != 0)
		{
			Q[i] = Q[i] + C[i];
		}
		Q[i] = Q[i] / Meme[i];
	}
	cout << endl;
	for (i = 0; i < length; i++)
	{
		cout << "N[" << i << "] " << " = " << Q[i] << "(mod " << C[i] << ")" << endl;
	}
	int Xresult = 1;
	for (i = 0; i < length; i++)
	{
		Xresult += Meme[i] * Q[i] * B[i];
	}
	cout << "Xresult = " << Xresult << endl;
	cout << "XXresult ~ " << Xresult << " (mod " << M << " )" << endl;
	while (Xresult > M)
	{
		Xresult = Xresult - M;
	}
	cout << "XXresult = " << Xresult << endl;
}

void LongInt::swap(LongInt& b)
{
	std::swap(length, b.length);
	std::swap(num, b.num);
	std::swap(isPosit, b.isPosit);
}