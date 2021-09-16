#include"Porazryad.h"
void main()
{
	int elt, *massiv;//elt - это количество элементов в массиве, вводимое пользователем; massiv - это полученный массив.
	setlocale(0,"Russian");
	cout<<"Введите желаемое количество элементов в массиве.\n";
	cin>>elt;
	massiv=Sozd(elt);//Создание массива.
	Zap(massiv, elt);//Заполнение массива.
	Vyvod(massiv, elt);//Вывод массива.
	Poraz(massiv, elt);//Поразрядная сортировка массива.
	Vyvod(massiv, elt);//Вывод отсортированного массива.
	delete[]massiv;//Очистка памяти.
	system("pause");
}
