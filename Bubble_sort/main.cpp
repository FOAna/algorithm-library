#include"Puzyr.h"
void main()
{
	int str,stl,**massiv,*omas,**dmas;//str - количество строк в массиве, вводимое пользователем; stl - количество столбцов в массиве,
//вводимое пользователем; massiv - двумерный массив; omas - одномерный массив; dmas - отсортированный двумерный массив.
	setlocale (0,"Russian");
	cout<<"Введите желаемое количество строк в массиве.\n";
	cin>>str;
	cout<<"Введите желаемое количество столбцов в массиве.\n";
	cin>>stl;
	massiv=Sozd(str,stl);
	Zap(massiv,str,stl);
	Vyvod(massiv,str,stl);
	omas=Odn(massiv,str,stl);
	Sort(omas,str,stl);
	dmas=Dvum(omas,str,stl);
	cout<<"\n";
	Vyvod(dmas,str,stl);
	delete[]massiv;
	delete[]omas;
	delete[]dmas;
	system("pause");
}