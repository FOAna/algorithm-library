/*Поиск подстроки в строке. Алгоритм Бойера-Мура.*/
#include<iostream>
#include<string.h>
using namespace std;
char *Sozd(int b);//Функция для создания строки.
void Vyvod(char*a,int b);//Функция для вывода строки.
int Stop(char*c,int d,char e);//Функция для нахождения стоп-символов.
void PEvr(char*a,char*c,int b,int d);//Функция для поиска по первой эвристике.
int VEvr(char*a,char*c,int b,int f);//Функция для поиска по второй эвристкие.