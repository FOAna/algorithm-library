#include"Poisk.h"
char *Sozd(int b)//b - ��� ���������� ��������� � ������.
{
	char*a = new char[b];
	return a;
}

void Vyvod(char*a,int b)//a - ��� ������; b - ��� ���������� ��������� � ������.
{
	for (int i=0;i<b;i++)
		cout<<" "<<a[i];
	cout<<"\n";
}

int Stop(char*c,int d,char e)//c - ��� ������, � ������� ������ ����� ����-��������; d - ��� ���������� ��������� � ���� ������;
//e - ��� ������� ����-������.
{
	int st=0;//st - ��� ���������� ����� ��������, ������� ����-�������.
	for (int i=0;i<d-1;i++)
		if (c[i]==e)
			st=i+1;
	return st;
}

int VEvr(char*a,char*c,int b,int f)//a - ��� ������� ������; c - ��� �������, ������� � �������; b - ��� ���������� ��������� � �������;
//f - ��� ���������� ��������� � ��������.
{
	int i=b-1-f,j=f-1,kol=0,gr=0,per=0;//i - ��� ������ �������� �������; j - ��� ������ �������� ��������; kol - ��� ���������� ��������� ���������
//� ������� � ��������; gr - ��� ������� �������� �� ������ (���� ������� ����� ����� ���������); per - ��� ���������� ���������, �� ������� ����
//����� ����������� ������ ������������ ������.
	while ((i>=f-1-gr) && (j>=gr))
	{
		if (a[i]==c[j])
		{
			kol+=1;
			if (j==gr)
			{
				per=b-kol;
				j--;
			}
			else
			{
				i--;
				j--;
			}
		}
		else
		{
			if (i==f-1-gr)
			{
				if (kol>1)
				{
					gr+=1;
					i=b-1-f+gr;
					j=f-1;
					kol=0;
				}
				else
					i--;
			}
			else
			{
				i--;
				kol=0;
			}
		}
	}
	return per;
}

void PEvr(char*a,char*c,int b,int d)//a - ��� �������� ������; c - ��� ������; b - ��� ���������� ��������� � ������; d - ��� ���������� ���������
//� �������.
{
	int sim,i=d-1,j=d-1,sov=0,suf;//sim - ��� ����-������; i - ��� ������ ��������� �������� ������; j - ��� ������ ��������� �������;
//sov - ��� ���������� ��������� ��������� ������; suf - ��� ������� �������.
	char* s;//s - ��� ������ ��� ��������.
	while ((i<b) && (j>=0))
	{
		if (a[i]==c[j])
		{
			sov+=1;
			if (j==0)
			{
				cout<<"\n   ������ ������� ��������� �������� �������: "<<i<<"\n";
				i--;
				j--;
			}
			else
			{
				i--;
				j--;
			}
		}
		else
		{
			if ((sov>1) && (sov<b/2))
			{
				s=Sozd(sov);
				for (int i=0,j=d-sov;i<sov,j<d;i++,j++)
					s[i]=c[j];
				suf=VEvr(c,s,d,sov);
				i+=d-suf;
			}
			else
			{
				sim=Stop(c,d,a[i]);
				if (i==b-1)
				{
					cout<<"\n   ������ �� ������!\n";
					i++;
				}
				else
				{
					if (sim==0)
					{
						i+=d;
						j=d-1;
					}
					else
					{
						i+=d-sim;
						j=d-1;
					}
				}
			}
		}
	}
}
