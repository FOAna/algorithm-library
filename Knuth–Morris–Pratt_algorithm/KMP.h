/*Поиск подстроки в строке. Алгоритм Кнута-Морриса-Пратта.*/
#include<iostream>
#include<string.h>
using namespace std;
char *Sozdchar(int b);//Функция для создания строки.
int *Sozdint(int b);//Функция для создания динамического массива.
void Vyvod(char*a,int b);//Функция для вывода строки.
void Vyvodint(int*a,int b);//Функция для вывода массива.
int *Prefix(char*a, int b);//Функция для нахождения в шаблоне префиксов-суффиксов.
void Poisk(char*a, int b, char*c, int d, int*e);//Функция для поиска шаблона в строке.