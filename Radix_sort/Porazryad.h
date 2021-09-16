/*Поразрядная сортировка для одномерного массива методом сортировки подсчётом*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int *Sozd(int b);//Функция для создания массива.
void Zap(int*a, int b);//Функция для заполнения массива.
void Vyvod(int*a, int b);//Функция для вывода массива.
void Poraz(int*a, int b);//Функция для поразрядной сортировки массива.