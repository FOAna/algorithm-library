/*�������*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Tree//�������� ������ ��� ����� � �������.
{
	int a;//�������� �������� ������.
	Tree *left;//����� ������ ������ ��������. 
	Tree *right;//����� ������� ������ ��������.
	int level;//������� �������� ������.
};
Tree *Root(int a);//�������� ����� ������ (������� �������� ������).
Tree *Child(int a,Tree *root);//���������� ������ ����� �������� (���������� �������� � ������).
//bool Search(int a, Tree *root);//����� �������� � ������.
Tree *Del(int a,Tree *root);//�������� ��������� �� ������.
void Vyvod(int a,int n,int lev,Tree *root);//����� ������.