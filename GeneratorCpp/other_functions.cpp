#include "head.h"
#include "math.h"
#include "iostream"
#include "algorithm"
using namespace std;


void gist_for_uniform (int(*function) (int), int x0, const int min, const int max, const int n_gist) // побудова гістограми для генераторів з рівномірним розподілом
{
	int g_arr [N_gist] = {}; // масив гістограми
	for (int i = 0; i < N_gen; ++i) // цикл заповнення масиву гістограми
	{
		gist_arr (double (x0 = function(x0)) / M,  g_arr,  min,  max,  n_gist); 
	}
	double step = double (max - min)/n_gist; // крок проміжків у гістограмі
	for (int i = 0; i < n_gist; ++i)	// вивід гістограми
	{
		cout << "[" ; 
		cout.width(3); cout << left << (min + i*step) << "; ";
		cout.width(3); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}
}

void gist_for_normal (double (*function) (), const int min, const int max, const int n_gist)  // побудова гістограми для генераторів з нормальним розподілом
{
	double x;
	int g_arr [N_gist6] = {}; // масив гістограми
	for (int i = 0; i < N_gen; ++i)  // цикл заповнення масиву гістограми
	{
		gist_arr (x = function (), g_arr, min, max, n_gist);
	}
	double step = double (max - min) / n_gist;  // крок проміжків у гістограмі
	for (int i = 0; i < n_gist; ++i)  // вивід гістограми
	{
		cout << "[" ; 
		cout.width(4); cout << left << (min + i*step) << "; ";
		cout.width(4); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}

}


void gist_for_polar (const int min, const int  max, const int n_gist)  // побудова гістограми для генератора з полярним розподілом
{
	polar x;
	int g_arr [N_gist6] = {};  // масив гістограми
	for (int k = 0; k < N_gen / 2; ++k)  // цикл заповнення масиву гістограми
	{
		x = g7_polar ();
		gist_arr (x.u1, g_arr, min, max, n_gist);
		gist_arr (x.u2, g_arr, min, max, n_gist);
	}
	double step = double (max - min) / n_gist;  // крок проміжків у гістограмі
	for (int i = 0; i < n_gist; ++i)  
	{
		cout << "[" ; 
		cout.width(4); cout << left << (min + i*step) << "; ";
		cout.width(4); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}
}

void gist_for_other (double (* function) (), const int min, const int max, const int n_gist)  // побудова гістограми для інших генераторів
{
	double x;
	int g_arr [N_gist10] = {};  // масив гістограми
	for (int i = 0; i < N_gen; ++i)  // цикл заповнення масиву гістограми
	{
		gist_arr (x = function (), g_arr, min, max, n_gist);
	}
	double step = double (max - min) / n_gist;  // крок проміжків у гістограмі
	for (int i = 0; i < n_gist; ++i)  // вивід гістограми
	{
		cout << "[" ; 
		cout.width(3); cout << left << (min + i*step) << "; ";
		cout.width(3); cout << right << (min + (i + 1)*step) << "]  : ";
		cout.width(4); cout << left << double (g_arr [i]) * 100 / N_gen << "%" << endl;
	}
}


void gist_arr (double x, int  g_arr[], const int min, const int max, const int n_gist )   // заповнення масиву гістограми
{
	double c = double (n_gist)/(max - min);  // константа, на яку будемо домножати числа з проміжків
	int i;                                       
	i = int ((x - min) * c);
	if (x >= min &&  x <= max) // перевірка для 6 генератора
	++g_arr[i];
	return;
}

int criterion (int(*function) (int),  int x0, const int N, double  r_chastota[], double  st_chastota[])
{
	double  sum_dvoichnyu_r [N_gen] = {};   // вектори, що утворилися з двійкового запису в рядках
	double  sum_dvoichnyu_st [N_gen] = {};  // вектори, що утворилися з двійкового запису у стовпчиках
	for (int i = 0; i < N_gen; ++i)  // обнулення векторів частот, щоб не додавати нові частоти до масиву старих
	{
		r_chastota [i] = 0;
		st_chastota [i] = 0;
	}
	
	for (int i = 0; i < N ;  ++i)  // проходження по рядках "матриці"
	{
		for (int j = 0; j < N; ++j)  // проходження по стовпцях "матриці"
		{
			x0 = function (x0);  // виклик генератора
			if (x0 % 2 == 0)   // врахування парних чисел ( "одиничок матриці")
			{
				r_chastota [i] += 1./N;  // підрахунок частот у рядках
				st_chastota [j] += 1./N;   // підрахунок частот у стовпцях 
				sum_dvoichnyu_r [i] += pow (0.5, j + 1 ); // запис десяткового дробу за його двійковм зображенням в рядках
				sum_dvoichnyu_st [j] += pow (0.5, i + 1); // запис десяткового дробу за його двійковим зображенням в стовпчиках
			}	
		}
	}
	

	sort (sum_dvoichnyu_r, sum_dvoichnyu_r + N );     // упорядкування 0. за зростанням у рядкках
	sort (sum_dvoichnyu_st, sum_dvoichnyu_st + N);    // упорядкування 0. за зростанням у стовпчиках
	double max_r = sum_dvoichnyu_r [1] - sum_dvoichnyu_r [0],  // цикл підрахунку максимального відхилення в рядках
		   max_st = sum_dvoichnyu_st [1] - sum_dvoichnyu_st [0]; // цикл підрахунку максимального відхилення в стовпчиках
	for (int i = 1; i < (N - 1); ++i)
	{
		if ((sum_dvoichnyu_r [i + 1] - sum_dvoichnyu_r [i]) > max_r)    
			max_r = sum_dvoichnyu_r [i + 1] - sum_dvoichnyu_r [i];

		if ((sum_dvoichnyu_st [i + 1] - sum_dvoichnyu_st [i]) > max_st)
			max_st = sum_dvoichnyu_st [i + 1] - sum_dvoichnyu_st [i];
	}
	cout << "max difference in row    for N = "; cout.width(4); cout << N << "    =  " << max_r << endl; // виведення максимального відхилення в рядках
	cout << "max difference in column for N = "; cout.width(4); cout  << N << "    =  " << max_st << endl; // виведення максимального відхилення в стовпцях
	
	return  g1_linear (x0); // повернення згенерованого числа для виклику критерію для N = N + 100
}

void last_criterion (int (*function) (int), int x0)
{
	int vector_vyzova [11]; // вектор де зберігаються х0
	vector_vyzova[0] = x0;  // початкове значення
	double r_chastota_p [N_gen] = {}; // частота в рядках для N, що є меншим у даному порівнянні (старе)
	double r_chastota_n [N_gen] = {}; // частота в стовпцях для N, що є меншим у даному порівнянні (старе)
	double st_chastota_p [N_gen] = {}; // частота в рядках для N, що є більшим у даному порівнянні (нове)
	double st_chastota_n [N_gen] = {}; // частота в стовпцях для N, що є більшим у даному порівнянні (нове)
	double r_vector_dif [9]; // масив різниць між частотами в рядках
	double st_vector_dif [9]; // масив різниці між частотами в стовпцях
	bool first = true;  // перевірка першого входження в цикл (N = 100)
						
	for (int i = 0, N = 100;   N <= N_gen;    ++i , N += 100)
					
	{
					
		if (first)
				{
					vector_vyzova[i + 1] = criterion (g1_linear, vector_vyzova [i], N, r_chastota_n, st_chastota_n); // виклик критерія і запам,ятовування х0 для наступного виклику
					copy_arr ( r_chastota_n, r_chastota_p, N);  // в старий копіюється новий масив
					copy_arr (st_chastota_n, st_chastota_p, N); // в старий копіюється новий масив
					first = false;
				}
		else 
				{
					vector_vyzova[i + 1] = criterion (g1_linear, vector_vyzova [i], N, r_chastota_n, st_chastota_n); // виконання критерію і запам,ятовування х0
					r_vector_dif [i - 1] = vector_dif (r_chastota_p , r_chastota_n , N - 100 );  // заповнення масиву "різниць" між частотами
					st_vector_dif [i - 1] = vector_dif (st_chastota_p , st_chastota_n , N - 100);  // заповнення масиву "різниць" між частотами
					copy_arr ( r_chastota_n, r_chastota_p, N);  // в старий копіюється новий масив
					copy_arr (st_chastota_n, st_chastota_p, N); // в старий копіюється новий масив
				}
			}
		cout << endl;
		cout << "row dif: \n \n";
		for (int i = 0; i < 9; ++i)  // цикл виводу відстані між векторами частот в рядках
		{
		cout << "between " << (i*100 + 100) << " and " ; cout.width (5); cout << ((i + 1 )*100 + 100) << "  :";
		cout << r_vector_dif[i] << endl;
		}
		cout << endl;
		cout << "colums dif:  \n \n";
		for (int i = 0; i < 9; ++i)  // цикл виводу відстані між векторами частот в стовпчиках
		{
			cout << "between " << (i*100 + 100) << " and " ; cout.width (5); cout << ((i + 1 )*100 + 100) << "  :";
			cout << st_vector_dif[i] << endl;
		}
			cout << endl;
}



double vector_dif (double *a, double *b, int N) // відстань між векторами
{ 
double  sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += (a[i] - b[i]) * (a[i] - b[i]);
	}
return sqrt(sum);
}

void copy_arr (double *a, double *b, const int N)  // копіювання масиву а в масив б
{
for (int i = 0; i < N; ++i)
	b[i] = a[i];
return;
}


