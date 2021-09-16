#include"Shella.h"
void main()
{
	int el,*mass;//el - это количество элементов в массиве, вводимое пользователем; mass - это массив.
	setlocale(0,"Russian");
	cout<<"Введите желаемое количество элементов в одномерном массиве.\n";
	cin>>el;
	mass=Sozd(el);//Создание массива.
	Zap(mass,el);//Заполнение массива.
	Vyvod(mass,el);//Вывод массива.
	Shell(mass,el);//Сортировка массива.
	cout<<"\n";
	Vyvod(mass,el);//Вывод отсортированного массива.
	delete[]mass;//Очистка памяти.
	system("pause");
}