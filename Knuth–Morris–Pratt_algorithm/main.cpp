#include"KMP.h"
void main()
{
	int elt, eltsh, *pref;//elt - ���������� ��������� � ������, �������� �������������; eltsh - ���������� ��������� � �������, �������� �������������;
//pref - �������� ���������-���������.
	char *stroka, *shablon;//stroka - ��� �������� ������, � ������� ���������� �����; shablon - ��� ������� ������.
	setlocale(0,"Russian");
	cout<<"������� �������� ���������� ��������� � ������.\n";
	cin>>elt;
	stroka=Sozdchar(elt);
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
		shablon=Sozdchar(eltsh);
		cout<<"������� ������, ������� ������ ����� � ������.\n";
		cin>>shablon;
		cout<<"��� ������:\n";
		Vyvod(shablon,eltsh);
		pref=Sozdint(eltsh);
		pref=Prefix(shablon,eltsh);
		cout<<"�������� ���������:\n";
		Vyvodint(pref,eltsh);
		Poisk(stroka,elt,shablon,eltsh,pref);
	}
	system("pause");
}