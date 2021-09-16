#include"Poisk.h"
void main()
{
	int elt, eltsh;//elt - это количество элементов в исходной строке, вводимое пользователем; eltsh - это количество элементов в шаблоне, вводимое
//пользователем.
	char *stroka, *shablon;//stroka - это исходная строка; shablon - это искомый шаблон.
	setlocale(0,"Russian");
	cout<<"Введите желаемое количество элементов в строке.\n";
	cin>>elt;
	stroka=Sozd(elt);
	cout<<"Введите строку.\n";
	cin>>stroka;
	cout<<"Исходная строка:\n";
	Vyvod(stroka,elt);
	cout<<"Введите количество элементов в вашем шаблоне.\n";
	cin>>eltsh;
	if (eltsh>elt)
		cout<<"\nКоличество элементов в шаблоне должно быть меньше количества элементов в строке. Пожалуйста, задайте другое количество элементов в шаблоне, или введите другую строку.\n";
	else
	{
		shablon=Sozd(eltsh);
		cout<<"Введите шаблон, который хотите найти в строке.\n";
		cin>>shablon;
		cout<<"Шаблон поиска:\n";
		Vyvod(shablon,eltsh);
		PEvr(stroka,shablon,elt,eltsh);
	}
	system("pause");
}