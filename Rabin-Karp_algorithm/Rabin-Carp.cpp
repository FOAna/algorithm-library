#include"Rabin-Carp.h"
char* Sozd(int b)
{
	char*a = new char[b];
	return a;
}

void Vyvod(char*a,int b)
{
	for (int i=0;i<b;i++)
		cout<<" "<<a[i];
	cout<<"\n";
}

int Hash(char*a,int b,int nach)
{
	int hash=0, ind=0;//hash - ��� �������� ���-�������, ind - ��� ������ ��������, ��� �������.
	for (int i=nach;i<b;i++)
	{
		ind++;
		int ascii=(int)a[i];
		int h=ascii*ind;//������������� ������� ��� ���-�������.
		hash+=h;
	}
	return hash;
}

void Poisk(char*a,int b,int d,int hf,char*c)//hf - ��� �������� ���-������� �������
{
	int hast;//�������� ���-������� ������.
	//cout<<"\n��� �������: "<<hf<<" ";
	for (int i=0;i<=b-d;i++)
	{
		hast=Hash(a,(d+i),i);
		//cout<<"��� ������: "<<hast<<"\n";
		if (hast==hf)
		{
			cout<<"\n   ������ ������� ��������� �������� �������: "<<i<<"\n";
			for (int j=i,e=0;j<d+i;j++,e++)
			{
				if (a[j]!=c[e])
				{
					cout<<"\n   !!! ������� ������������ !!!\n";
					j=b;
				}
				else
				{
					cout<<"\n �������� �� ������� ������������, �����������! \n";
					j=b;
				}
			}
			i=b;
		}
		else
		{
			if(i==b-d)
			{
				cout<<" \n ! ������ �� ������ !\n";
				i=b;
			}
		}
	}
}