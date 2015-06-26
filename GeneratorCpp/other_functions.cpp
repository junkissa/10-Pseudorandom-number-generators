#include "head.h"
#include "math.h"
#include "iostream"
#include "algorithm"
using namespace std;


void gist_for_uniform (int(*function) (int), int x0, const int min, const int max, const int n_gist) // �������� ��������� ��� ���������� � ��������� ���������
{
	int g_arr [N_gist] = {}; // ����� ���������
	for (int i = 0; i < N_gen; ++i) // ���� ���������� ������ ���������
	{
		gist_arr (double (x0 = function(x0)) / M,  g_arr,  min,  max,  n_gist); 
	}
	double step = double (max - min)/n_gist; // ���� ������� � ��������
	for (int i = 0; i < n_gist; ++i)	// ���� ���������
	{
		cout << "[" ; 
		cout.width(3); cout << left << (min + i*step) << "; ";
		cout.width(3); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}
}

void gist_for_normal (double (*function) (), const int min, const int max, const int n_gist)  // �������� ��������� ��� ���������� � ���������� ���������
{
	double x;
	int g_arr [N_gist6] = {}; // ����� ���������
	for (int i = 0; i < N_gen; ++i)  // ���� ���������� ������ ���������
	{
		gist_arr (x = function (), g_arr, min, max, n_gist);
	}
	double step = double (max - min) / n_gist;  // ���� ������� � ��������
	for (int i = 0; i < n_gist; ++i)  // ���� ���������
	{
		cout << "[" ; 
		cout.width(4); cout << left << (min + i*step) << "; ";
		cout.width(4); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}

}


void gist_for_polar (const int min, const int  max, const int n_gist)  // �������� ��������� ��� ���������� � �������� ���������
{
	polar x;
	int g_arr [N_gist6] = {};  // ����� ���������
	for (int k = 0; k < N_gen / 2; ++k)  // ���� ���������� ������ ���������
	{
		x = g7_polar ();
		gist_arr (x.u1, g_arr, min, max, n_gist);
		gist_arr (x.u2, g_arr, min, max, n_gist);
	}
	double step = double (max - min) / n_gist;  // ���� ������� � ��������
	for (int i = 0; i < n_gist; ++i)  
	{
		cout << "[" ; 
		cout.width(4); cout << left << (min + i*step) << "; ";
		cout.width(4); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}
}

void gist_for_other (double (* function) (), const int min, const int max, const int n_gist)  // �������� ��������� ��� ����� ����������
{
	double x;
	int g_arr [N_gist10] = {};  // ����� ���������
	for (int i = 0; i < N_gen; ++i)  // ���� ���������� ������ ���������
	{
		gist_arr (x = function (), g_arr, min, max, n_gist);
	}
	double step = double (max - min) / n_gist;  // ���� ������� � ��������
	for (int i = 0; i < n_gist; ++i)  // ���� ���������
	{
		cout << "[" ; 
		cout.width(3); cout << left << (min + i*step) << "; ";
		cout.width(3); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}
}


void gist_arr (double x, int  g_arr[], const int min, const int max, const int n_gist )   // ���������� ������ ���������
{
	double c = double (n_gist)/(max - min);  // ���������, �� ��� ������ ��������� ����� � �������
	int i;                                       
	i = int ((x - min) * c);
	if (x >= min &&  x <= max) // �������� ��� 6 ����������
	++g_arr[i];
	return;
}

int criterion (int(*function) (int),  int x0, const int N, double  r_chastota[], double  st_chastota[])
{
	double  sum_dvoichnyu_r [N_gen] = {};   // �������, �� ���������� � ��������� ������ � ������
	double  sum_dvoichnyu_st [N_gen] = {};  // �������, �� ���������� � ��������� ������ � ����������
	for (int i = 0; i < N_gen; ++i)  // ��������� ������� ������, ��� �� �������� ��� ������� �� ������ ������
	{
		r_chastota [i] = 0;
		st_chastota [i] = 0;
	}
	
	for (int i = 0; i < N ;  ++i)  // ����������� �� ������ "�������"
	{
		for (int j = 0; j < N; ++j)  // ����������� �� �������� "�������"
		{
			x0 = function (x0);  // ������ ����������
			if (x0 % 2 == 0)   // ���������� ������ ����� ( "�������� �������")
			{
				r_chastota [i] += 1./N;  // ��������� ������ � ������
				st_chastota [j] += 1./N;   // ��������� ������ � �������� 
				sum_dvoichnyu_r [i] += pow (0.5, j + 1 ); // ����� ����������� ����� �� ���� ������� ����������� � ������
				sum_dvoichnyu_st [j] += pow (0.5, i + 1); // ����� ����������� ����� �� ���� �������� ����������� � ����������
			}	
		}
	}
	

	sort (sum_dvoichnyu_r, sum_dvoichnyu_r + N );     // ������������� 0. �� ���������� � �������
	sort (sum_dvoichnyu_st, sum_dvoichnyu_st + N);    // ������������� 0. �� ���������� � ����������
	double max_r = sum_dvoichnyu_r [1] - sum_dvoichnyu_r [0],  // ���� ��������� ������������� ��������� � ������
		   max_st = sum_dvoichnyu_st [1] - sum_dvoichnyu_st [0]; // ���� ��������� ������������� ��������� � ����������
	for (int i = 1; i < (N - 1); ++i)
	{
		if ((sum_dvoichnyu_r [i + 1] - sum_dvoichnyu_r [i]) > max_r)    
			max_r = sum_dvoichnyu_r [i + 1] - sum_dvoichnyu_r [i];

		if ((sum_dvoichnyu_st [i + 1] - sum_dvoichnyu_st [i]) > max_st)
			max_st = sum_dvoichnyu_st [i + 1] - sum_dvoichnyu_st [i];
	}
	cout << "max difference in row    for N = "; cout.width(4); cout << N << "    =  " << max_r << endl; // ��������� ������������� ��������� � ������
	cout << "max difference in column for N = "; cout.width(4); cout  << N << "    =  " << max_st << endl; // ��������� ������������� ��������� � ��������
	
	return  g1_linear (x0); // ���������� ������������� ����� ��� ������� ������� ��� N = N + 100
}

void last_criterion (int (*function) (int), int x0)
{
	int vector_vyzova [11]; // ������ �� ����������� �0
	vector_vyzova[0] = x0;  // ��������� ��������
	double r_chastota_p [N_gen] = {}; // ������� � ������ ��� N, �� � ������ � ������ �������� (�����)
	double r_chastota_n [N_gen] = {}; // ������� � �������� ��� N, �� � ������ � ������ �������� (�����)
	double st_chastota_p [N_gen] = {}; // ������� � ������ ��� N, �� � ������ � ������ �������� (����)
	double st_chastota_n [N_gen] = {}; // ������� � �������� ��� N, �� � ������ � ������ �������� (����)
	double r_vector_dif [9]; // ����� ������ �� ��������� � ������
	double st_vector_dif [9]; // ����� ������ �� ��������� � ��������
	bool first = true;  // �������� ������� ��������� � ���� (N = 100)
						
	for (int i = 0, N = 100;   N <= N_gen;    ++i , N += 100)
					
	{
					
		if (first)
				{
					vector_vyzova[i + 1] = criterion (g1_linear, vector_vyzova [i], N, r_chastota_n, st_chastota_n); // ������ ������� � �����,���������� �0 ��� ���������� �������
					copy_arr ( r_chastota_n, r_chastota_p, N);  // � ������ ��������� ����� �����
					copy_arr (st_chastota_n, st_chastota_p, N); // � ������ ��������� ����� �����
					first = false;
				}
		else 
				{
					vector_vyzova[i + 1] = criterion (g1_linear, vector_vyzova [i], N, r_chastota_n, st_chastota_n); // ��������� ������� � �����,���������� �0
					r_vector_dif [i - 1] = vector_dif (r_chastota_p , r_chastota_n , N - 100 );  // ���������� ������ "������" �� ���������
					st_vector_dif [i - 1] = vector_dif (st_chastota_p , st_chastota_n , N - 100);  // ���������� ������ "������" �� ���������
					copy_arr ( r_chastota_n, r_chastota_p, N);  // � ������ ��������� ����� �����
					copy_arr (st_chastota_n, st_chastota_p, N); // � ������ ��������� ����� �����
				}
			}
		cout << endl;
		cout << "row dif: \n \n";
		for (int i = 0; i < 9; ++i)  // ���� ������ ������ �� ��������� ������ � ������
		{
		cout << "between " << (i*100 + 100) << " and " ; cout.width (5); cout << ((i + 1 )*100 + 100) << "  :";
		cout << r_vector_dif[i] << endl;
		}
		cout << endl;
		cout << "colums dif:  \n \n";
		for (int i = 0; i < 9; ++i)  // ���� ������ ������ �� ��������� ������ � ����������
		{
			cout << "between " << (i*100 + 100) << " and " ; cout.width (5); cout << ((i + 1 )*100 + 100) << "  :";
			cout << st_vector_dif[i] << endl;
		}
			cout << endl;
}



double vector_dif (double *a, double *b, int N) // ������� �� ���������
{ 
double  sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += (a[i] - b[i]) * (a[i] - b[i]);
	}
return sqrt(sum);
}

void copy_arr (double *a, double *b, const int N)  // ��������� ������ � � ����� �
{
for (int i = 0; i < N; ++i)
	b[i] = a[i];
return;
}


