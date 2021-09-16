/*Деревья*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Tree//Создание списка для стека и очереди.
{
	int a;//Значение элемента списка.
	Tree *left;//Адрес левого ребёнка элемента. 
	Tree *right;//Адрес правого ребёнка элемента.
	int level;//Уровень элемента дерева.
};
Tree *Root(int a);//Создание корня дерева (первого элемента списка).
Tree *Child(int a,Tree *root);//Добавление ребёнка после родителя (добавление элемента в список).
//bool Search(int a, Tree *root);//Поиск элемента в дереве.
Tree *Del(int a,Tree *root);//Удаление эелемента из дерева.
void Vyvod(int a,int n,int lev,Tree *root);//Вывод дерева.