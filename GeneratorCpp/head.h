#include "math.h"

const int N_gen = 1000;     // kil'kist' chisel, jaki generuut'sia
const int N_gist = 10, N_gist6 = 12, N_gist10 = 20;      // проміжків у гісторгамі
const int MIN = 0, MAX = 1; // початкове та кінцеве значення проміжку розподілу для рівномірного розподілу [0, 1]
const int MIN6 = -3, MAX6 = 3;  // початкове та кінцеве значення проміжку розподілу для нормального розподілу [-3, 3]
const int MIN10 = 0, MAX10 = 100; // початкове та кінцеве значення проміжку розподілу для інших генераторів [0, 100]
const int M = 9949; // модуль
const double PI = 4 * atan (1.); // константа пі

struct polar  // структура для повернення двох чисел
{	double u1, u2;
	polar ();
	void print ();
};

int inverse (int x, const int m); // пошук оберненого числа др х по модулю м

int g1_linear (int x);
int g2_quadratic (int x);
int g3_fibo (int x);
int g4_inverse (int x);
int g5_union (int x);

double g6_sigma ();
polar g7_polar ();
double g8_relation ();

double g9_log ();
double g10_Arens ();

void gist_arr (double x, int  g_arr[], int min, int max, int n_gist );  // заповнення масиву гістограми
void gist_for_uniform (int(*function) (int), int x0, const int min, const int max, const int n_gist); // побудова гістограми для генераторів з рівномірним розподілом
void gist_for_normal (double (*function) (), const int min, const int max, const int n_gist); // побудова гістограми для генераторів з нормальним розподілом
void gist_for_polar (const int min, const int  max, const int n_gist); // побудова гістограми для генератора з полярним розподілом
void gist_for_other (double (*function) (), const int min, const int max, const int n_gist); // побудова гістограми для інших генераторів

int criterion (int(*function) (int),  int x0, const int N, double  r_chastota[], double  st_chastota[]);
void last_criterion (int (*function)  (int), int x0);

double vector_dif (double *a, double *b, int N); // пошук відстані між векторами
void copy_arr (double *a, double *b, const int N); // копіювання з А в В