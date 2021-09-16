/*Обратная польская запись.*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct List//Создание списка для стека и очереди.
{
	char a;//Значение элемента списка.
	List *prev;//Адрес предыдущего элемента списка. 
	List *next;//Адрес следующего элемента списка.
};
List *Queue(char a);//Функция для создания первого элемента списка.
List *Add_Queue(char a,List *last);//Функция добавления элемента в список.
List *Del_Queue(List *first);//Функция удаления элемента из очереди.
List *Del_Stack(List *last);//Функция удаления элемента из стека.
List *Beg(List *last);//Проход по списку.
int Kontrol(char *a);//Проверка входного выражения на достаточность скобочек, операторов(=,*,/).
List *Polka(char *a,List *lastQ, List *lastS);//Функция для преобразования выражения в польскую запись.
List *Vyvod(List *first);//Функция для вывода списка на экран.