#include"Puzyr.h"
int**Sozd(int b,int c)//b - ��� ���������� ����� � ��������� �������; c - ��� ���������� �������� � ��������� �������.
{
	int **a=new int*[b];//�������� ���������� �������.
	for (int i=0;i<b;i++)
		a[i]=new int[c];
	return a;
}

void Zap(int**a,int b,int c)//a - ��� ��������� ������.
{
	for (int i=0;i<b;i++)
	{
		for (int j=0;j<c;j++)
			a[i][j]=1+rand()%99;
	}
}

void Vyvod(int**a,int b,int c)
{
	for (int i=0;i<b;i++)
	{
		for (int j=0;j<c;j++)
			cout<<" "<<a[i][j];
		cout<<"\n";
	}
}

int *Odn(int**a,int b,int c)
{
	int d=0;//������ ��� ��������� ������ ����������� �������.
	int *s = new int[b*c];
	for (int i=0;i<b;i++)
		for (int j=0;j<c;j++,d++)
			s[d]=a[i][j];
	return s;
}

void Sort(int*s,int b,int c)//s - ���������� ������.
{
	int e=0;//e - ���������� ��� ����, ����� ������ ������� �������� �������.
	bool sort=false;//�������� ������� �� �����������������.
	while(!sort)
	{
		sort=true;
		for (int n=1;n<(b*c-1);n++)
			for (int i=b*c-1;i>=n;i--)
				if (s[i]<s[i-1])
				{
					e=s[i-1];
					s[i-1]=s[i];
					s[i]=e;
					sort=false;
				}
	}
}
	
int **Dvum(int*s,int b,int c)
{
	int d=0;//������ ��� ��������� ������ ����������� �������.
	int**f=new int*[b];
	for (int i=0;i<b;i++)
		f[i]=new int[c];
	while(d<(b*c))
	{
		for (int i=0;i<b;i++)
			for (int j=0;j<c;j++)
			{
				f[i][j]=s[d];
				d++;
			}
	}
	return f;
}