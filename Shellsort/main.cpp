#include"Shella.h"
void main()
{
	int el,*mass;//el - ��� ���������� ��������� � �������, �������� �������������; mass - ��� ������.
	setlocale(0,"Russian");
	cout<<"������� �������� ���������� ��������� � ���������� �������.\n";
	cin>>el;
	mass=Sozd(el);//�������� �������.
	Zap(mass,el);//���������� �������.
	Vyvod(mass,el);//����� �������.
	Shell(mass,el);//���������� �������.
	cout<<"\n";
	Vyvod(mass,el);//����� ���������������� �������.
	delete[]mass;//������� ������.
	system("pause");
}