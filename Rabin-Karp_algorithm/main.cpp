#include"Rabin-Carp.h"
void main()
{
	int elt, eltsh, fash;
	char *stroka, *shablon;
	setlocale(0,"Russian");
	cout<<"������� �������� ���������� ��������� � ������.\n";
	cin>>elt;
	stroka=Sozd(elt);
	cout<<"������� ������.\n";
	cin>>stroka;
	cout<<"�������� ������:\n";
	Vyvod(stroka,elt);
	cout<<"������� �������� ���������� ��������� � �������.\n";
	cin>>eltsh;
	if (eltsh>elt)
		cout<<"\n���������� ��������� � ������� ������ ���� ������ ���������� ��������� � ������.\n����������, ������� ������ ���������� ��������� � �������, ��� ������� ������ ������.\n";
	else
	{
		shablon=Sozd(eltsh);
		cout<<"������� ������, ������� ������ ����� � ������.\n";
		cin>>shablon;
		cout<<"��� ������:\n";
		Vyvod(shablon,eltsh);
		fash=Hash(shablon,eltsh,0);
		Poisk(stroka,elt,eltsh,fash,shablon);
	}
	system("pause");
}