/*Создать двумерный массив и отсортировать его методом пузырька.*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int **Sozd(int b,int c);//Функция для создания двумерного массива.
void Zap(int**a,int b,int c);//Функция для заполнения массива.
void Vyvod(int**a,int b,int c);//Функция вывода массива.
int *Odn(int**a,int b,int c);//Функция для преобразования двумерного массива в одномерный. 
void Sort(int*s,int b,int c);//Функция для сортировки массива.
int **Dvum(int*s,int b,int c);//Функция для преобразования одномерного массива в двумерный.