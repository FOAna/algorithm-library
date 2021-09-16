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
	int hash=0, ind=0;//hash - это значение хэш-функции, ind - это индекс элемента, его позиция.
	for (int i=nach;i<b;i++)
	{
		ind++;
		int ascii=(int)a[i];
		int h=ascii*ind;//Промежуточный подсчёт для хэш-функции.
		hash+=h;
	}
	return hash;
}

void Poisk(char*a,int b,int d,int hf,char*c)//hf - это значение хэш-функции шаблона
{
	int hast;//Значение хэш-функции строки.
	//cout<<"\nХэш шаблона: "<<hf<<" ";
	for (int i=0;i<=b-d;i++)
	{
		hast=Hash(a,(d+i),i);
		//cout<<"Хэш строки: "<<hast<<"\n";
		if (hast==hf)
		{
			cout<<"\n   Индекс первого вхождения искомого шаблона: "<<i<<"\n";
			for (int j=i,e=0;j<d+i;j++,e++)
			{
				if (a[j]!=c[e])
				{
					cout<<"\n   !!! Найдено несовпадение !!!\n";
					j=b;
				}
				else
				{
					cout<<"\n Проверка не выявила несовпадений, поздравляем! \n";
					j=b;
				}
			}
			i=b;
		}
		else
		{
			if(i==b-d)
			{
				cout<<" \n ! Шаблон не найден !\n";
				i=b;
			}
		}
	}
}