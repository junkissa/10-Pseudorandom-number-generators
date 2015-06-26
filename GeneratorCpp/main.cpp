#include "head.h"
#include "iostream"
#include "math.h"
#include "algorithm"

using namespace std;

int main ()
{
		int numb, x;
		cout << "Enter number of generator (1 - 10):  ";
		cout << endl;
		
		while (bool(cin >> numb))
		{
	switch (numb)
	{	case 1 :	x = 3; 
					cout << "linear\n";
					last_criterion (g1_linear, x);
					gist_for_uniform (g1_linear, x, MIN, MAX, N_gist);
					break;	

		case 2 :	x = 13;
					cout << "quadratic\n";
					last_criterion (g2_quadratic, x);
					gist_for_uniform (g2_quadratic, x, MIN, MAX, N_gist);
					break;  

		case 3 :	x = 124;
					cout << "Fibo\n";
					last_criterion (g3_fibo, x);
					gist_for_uniform (g3_fibo , x, MIN, MAX, N_gist);
					break;

		case 4 :	x = 7;
					cout << "inverse\n";
					last_criterion (g4_inverse, x); 
					gist_for_uniform (g4_inverse , x, MIN, MAX, N_gist);
					break;

		case 5 :	x = 0;	
					cout << "union\n";
					last_criterion (g5_union,  x); 
					gist_for_uniform (g5_union, x, MIN, MAX, N_gist);
					break;

		case 6 :	cout << "sigma\n";
					gist_for_normal (g6_sigma, MIN6, MAX6, N_gist6);
					break;

		case 7  :	cout << "polar\n";
					gist_for_polar (MIN6, MAX6, N_gist6);
					break;

		case 8  :	cout << "relation\n";
					gist_for_normal (g8_relation, MIN6, MAX6, N_gist6);
					break;

		case 9  :	cout << "log\n";
					gist_for_other (g9_log, MIN10, MAX10, N_gist10);
					break;

		case 10 :	cout << "Arens \n";
					gist_for_other (g10_Arens, MIN10, MAX10, N_gist10);
					break;
	}
		}
	cin.get();
	cin.get();
	return 0;
}
