#include"Poisk.h"
void main()
{
	int elt, eltsh;//elt - ��� ���������� ��������� � �������� ������, �������� �������������; eltsh - ��� ���������� ��������� � �������, ��������
//�������������.
	char *stroka, *shablon;//stroka - ��� �������� ������; shablon - ��� ������� ������.
	setlocale(0,"Russian");
	cout<<"������� �������� ���������� ��������� � ������.\n";
	cin>>elt;
	stroka=Sozd(elt);
	cout<<"������� ������.\n";
	cin>>stroka;
	cout<<"�������� ������:\n";
	Vyvod(stroka,elt);
	cout<<"������� ���������� ��������� � ����� �������.\n";
	cin>>eltsh;
	if (eltsh>elt)
		cout<<"\n���������� ��������� � ������� ������ ���� ������ ���������� ��������� � ������. ����������, ������� ������ ���������� ��������� � �������, ��� ������� ������ ������.\n";
	else
	{
		shablon=Sozd(eltsh);
		cout<<"������� ������, ������� ������ ����� � ������.\n";
		cin>>shablon;
		cout<<"������ ������:\n";
		Vyvod(shablon,eltsh);
		PEvr(stroka,shablon,elt,eltsh);
	}
	system("pause");
}