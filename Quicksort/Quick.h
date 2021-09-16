/*Быстрая сортировка для одномерного массива*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int *Sozd(int b);//Функция для создания одномерного массива.
void Zap(int*a,int b);//Функция для заполнения массива.
void Vyvod(int*a,int b);//Функция для вывода массива.
void Bystr(int*a,int per,int posl);//Функция для быстрой сортировки массива.