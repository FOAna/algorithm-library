/*�������� �������� ������.*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct List//�������� ������ ��� ����� � �������.
{
	char a;//�������� �������� ������.
	List *prev;//����� ����������� �������� ������. 
	List *next;//����� ���������� �������� ������.
};
List *Queue(char a);//������� ��� �������� ������� �������� ������.
List *Add_Queue(char a,List *last);//������� ���������� �������� � ������.
List *Del_Queue(List *first);//������� �������� �������� �� �������.
List *Del_Stack(List *last);//������� �������� �������� �� �����.
List *Beg(List *last);//������ �� ������.
int Kontrol(char *a);//�������� �������� ��������� �� ������������� ��������, ����������(=,*,/).
List *Polka(char *a,List *lastQ, List *lastS);//������� ��� �������������� ��������� � �������� ������.
List *Vyvod(List *first);//������� ��� ������ ������ �� �����.