#include"KMP.h"
void main()
{
	int elt, eltsh, *pref;//elt - количество элементов в строке, вводимое пользователем; eltsh - количество элементов в шаблоне, вводимое пользователем;
//pref - табличка префиксов-суффиксов.
	char *stroka, *shablon;//stroka - это исходная строка, в которой проводится поиск; shablon - это искомый шаблон.
	setlocale(0,"Russian");
	cout<<"Введите желаемое количество элементов в строке.\n";
	cin>>elt;
	stroka=Sozdchar(elt);
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
		shablon=Sozdchar(eltsh);
		cout<<"Введите шаблон, который хотите найти в строке.\n";
		cin>>shablon;
		cout<<"Ваш шаблон:\n";
		Vyvod(shablon,eltsh);
		pref=Sozdint(eltsh);
		pref=Prefix(shablon,eltsh);
		cout<<"Табличка префиксов:\n";
		Vyvodint(pref,eltsh);
		Poisk(stroka,elt,shablon,eltsh,pref);
	}
	system("pause");
}