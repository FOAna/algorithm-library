/*Поиск подстроки в строке. Алгоритм Рабина-Карпа.*/
#include<iostream>
#include<string.h>
using namespace std;
char* Sozd(int b);
void Vyvod(char*a,int b);
int Hash(char*a,int b,int nach);
void Poisk(char*a,int b,int d,int hf,char*c);