#include"Puzyr.h"
void main()
{
	int str,stl,**massiv,*omas,**dmas;//str - ���������� ����� � �������, �������� �������������; stl - ���������� �������� � �������,
//�������� �������������; massiv - ��������� ������; omas - ���������� ������; dmas - ��������������� ��������� ������.
	setlocale (0,"Russian");
	cout<<"������� �������� ���������� ����� � �������.\n";
	cin>>str;
	cout<<"������� �������� ���������� �������� � �������.\n";
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