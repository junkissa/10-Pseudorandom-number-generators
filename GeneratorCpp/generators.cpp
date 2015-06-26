#include "head.h"
#include "iostream"
using namespace std;


int g1_linear (int x) 
{
	const int a = 3, c = 5;
	return (a*x + c) % M;
}

int g2_quadratic (int x)
{
	const int a = 1,  c = 5,  d = 11;
	return (d*x*x + a*x + c) % M;
}

int g3_fibo (int x)
{
	static int x_p = 139; // початкове знаення
	int c = x_p;	// запам,ятовування попередньої змінної
	x_p = x;		// запам,ятовування поточної змінної
	return (x + c) % M;
}


int inverse (int x, const int m)
{
	int *inverse_arr = new int [x + 1];
	int x_inv;
	inverse_arr [0] = 0;
	inverse_arr [1] = 1;
	for (int i = 2; i < (x + 1); ++i)
	inverse_arr [i] = (m - (m/i) * inverse_arr [m%i] % m) % m;
	x_inv = inverse_arr [x];
	delete [] inverse_arr;
	return x_inv;
}

int g4_inverse (int x)
{
	const int a = 3, c = 5;
	int x_inv = inverse (x, M);
	return  (a * x_inv + c) % M;
}


int g5_union (int z)
{
	static int u0 = 3, v0 = 7;  // статичні змінні для збереження значення змінних між викликами функції
	u0 = g1_linear(u0);
	v0 = g2_quadratic (v0);
	int sum;
	sum = v0 - u0;
	if (sum < 0) sum += M; // перевірка на невід,ємність, якщо від,ємна, то додати модуль
	return sum % M;
}


double g6_sigma ()
{
	static int x;
	double  sum = 0;
	for (int i = 0; i < 12; ++i)
	{
		 x =  g1_linear (x);
		 sum += (double(x) / M); 
	}		
	return (sum - 6);
}


polar :: polar () : u1(0), u2(0) {}; 
void polar :: print ()
	{
		cout << (this -> u1) << "	" << (this -> u2) << "  ";
	}

polar g7_polar ()
{
	static int x1 = 3, x2 = 5;
	double v1, v2;
	double s;
	polar X;
	do
	{
	x1 = g1_linear (x1);
	x2 = g4_inverse (x2);
	v1 = 2 * double(x1) / M - 1;
	v2 = 2 * double(x2) / M - 1;
	s = v1*v1 + v2*v2;
	}
	while (s >= 1);
	X.u1 = v1 * pow ((-2 * log (s)) / s , 0.5);
	X.u2 = v2 * pow ((-2 * log (s)) / s , 0.5);
	return X;
}


double g8_relation ()
{
	static int x1 = 3, x2 = 5;
	double x, u0, v0;

	do {
		do 
		{
			x1 = g2_quadratic  (x1);
			x2 = g3_fibo (x2);
			u0 = double(x1) / M;
			v0 = double(x2) / M;
		}
		while (u0 == 0);
			x = pow (8./exp(1.0), 0.5) * (v0 - 0.5) / u0;
			if (x*x <= 5 - 4 * u0 * exp(0.25)) return x;
			if (x*x >= 4 * exp (1.35) / u0 + 1.4) continue;
	   }
	while (x*x > -4 * log (u0));
	return x;
}


double g9_log ()
{
	const int m = 57;
	static int x1 = 11;
	int z = 0;
	double x, u;
	x1 = g5_union (z);
	u = double (x1) / M;
	if (u == 0) u = 24e-15;
	x = -m * log(u);
	return x;
}


double g10_Arens ()
{
	const int a = 19; int z = 0;
	static int x1, x2 = 11;
	double u, x, y, v, comp;
	do 
	{
		do {
			x1 = g5_union (z);
			u = double (x1) / M;
			y = tan(PI * u);
			x = pow(2*a - 1, 0.5) * y + a - 1;
		   }
		while (x <= 0);
			x2 = g1_linear (x2);
			v = double (x2) / M;
			comp = (1 + y*y) * exp ((a - 1) * log(x / (a - 1)) - pow(2*a - 1, 0.5) * y);		
	}
	while (v > comp);
	return x;
}
