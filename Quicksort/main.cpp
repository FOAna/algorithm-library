#include"Quick.h"
void main()
{
	int elt, *massiv;//elt - ���������� ��������� � �������, �������� �������������; massiv - ��� ���������� ������.
	setlocale(0,"Russian");
	cout<<"������� �������� ���������� ��������� � �������.\n";
	cin>>elt;
	massiv=Sozd(elt);//�������� �������.
	Zap(massiv,elt);//���������� �������.
	Vyvod(massiv,elt);//����� �������.
	Bystr(massiv,0,elt);//������� ���������� �������.
	Vyvod(massiv,elt);//����� ���������������� �������.
	delete[]massiv;//������� ������.
	system("pause");
}