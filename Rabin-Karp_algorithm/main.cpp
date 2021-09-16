#include"Rabin-Carp.h"
void main()
{
	int elt, eltsh, fash;
	char *stroka, *shablon;
	setlocale(0,"Russian");
	cout<<"Введите желаемое количество элементов в строке.\n";
	cin>>elt;
	stroka=Sozd(elt);
	cout<<"Введите строку.\n";
	cin>>stroka;
	cout<<"Исходная строка:\n";
	Vyvod(stroka,elt);
	cout<<"Введите желаемое количество элементов в шаблоне.\n";
	cin>>eltsh;
	if (eltsh>elt)
		cout<<"\nКоличество элементов в шаблоне должно быть меньше количества элементов в строке.\nПожалуйста, задайте другое количество элементов в шаблоне, или введите другую строку.\n";
	else
	{
		shablon=Sozd(eltsh);
		cout<<"Введите шаблон, который хотите найти в строке.\n";
		cin>>shablon;
		cout<<"Ваш шаблон:\n";
		Vyvod(shablon,eltsh);
		fash=Hash(shablon,eltsh,0);
		Poisk(stroka,elt,eltsh,fash,shablon);
	}
	system("pause");
}