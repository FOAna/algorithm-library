#include"Pyramid.h"
void main()
{
	int elt, *massiv;//elt - ���������� ��������� � �������, �������� �������������; massiv - ��� ���������� ������.
	setlocale(0,"Russian");
	cout<<" ������� �������� ���������� ��������� � �������.\n";
	cin>>elt;
	massiv=Sozd(elt);//�������� �������.
	Zap(massiv,elt);//���������� �������.
	Vyvod(massiv,elt);//����� �������.
	Pyram(massiv,elt);//���������� �������.
	Vyvod(massiv,elt);//����� �������.
	delete[]massiv;//������� ������.
	system("pause");
}