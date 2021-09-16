#include"Quick.h"
void main()
{
	int elt, *massiv;//elt - количество элементов в массиве, вводимое пользователем; massiv - это одномерный массив.
	setlocale(0,"Russian");
	cout<<"Введите желаемое количество элементов в массиве.\n";
	cin>>elt;
	massiv=Sozd(elt);//Создание массива.
	Zap(massiv,elt);//Заполнение массива.
	Vyvod(massiv,elt);//Вывод массива.
	Bystr(massiv,0,elt);//Быстрая сортировка массива.
	Vyvod(massiv,elt);//Вывод отсортированного массива.
	delete[]massiv;//Очистка памяти.
	system("pause");
}