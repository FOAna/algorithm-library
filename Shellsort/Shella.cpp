#include"Shella.h"
int *Sozd(int b)//b - ��� ���������� ��������� � �������.
{
	int*a = new int[b];
	return a;
}

void Zap(int*a,int b)//a - ��� ������; b - ��� ���������� ��������� � �������.
{
	for (int i=0;i<b;i++)
		a[i]=1+rand()%99;
}

void Vyvod(int*a,int b)//a - ��� ������; b - ��� ���������� ��������� � �������.
{
	for (int i=0;i<b;i++)
		cout<<" "<<a[i];
	cout<<"\n";
}

void Shell(int*a,int b)//a - ��� ������; b - ��� ���������� ��������� � �������.
{
	if ((b%2)==0)//��������� ���������� ��������� � ������� �� ��������.
	{
		for (int n=0; n<b; n+=2)//n - ��� ���������� ��� ���������� ����, �� �������� ����� ������������ �������� �������.
			for (int i=0; i<((b+n)/2); i++)//i - ��� ����� �������� �������.
			{
				if (a[i]>a[i+(b-n)/2])
				{
					int c=a[i];
					a[i]=a[i+(b-n)/2];
					a[i+(b-n)/2]=c;
				}
				int p = i;
				//���������� ���������� ������� � ����������� ���������� � �������, ���� ������� ��������� ����� ������� ��� �����.
				while (p >= (b-n)/2 && a[p] < a[p-(b-n)/2])
				{
					int d = a[p];
					a[p] = a[p-(b-n)/2];
					a[p-(b-n)/2] = d;
					p -= (b-n)/2;
				}
			}
	}
	else
	{
		for (int n=0; n<b; n+=2)//n - ��� ���������� ��� ���������� ����, �� �������� ����� ������������ �������� �������.
			for (int i=0; i<=((b+n)/2); i++)//i - ��� ����� �������� �������.
				if (a[i]>a[i+(b-n)/2])
				{
					int c=a[i];
					a[i]=a[i+(b-n)/2];
					a[i+(b-n)/2]=c;
				}
	}
}