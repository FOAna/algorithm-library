#include"Trees.h"
void main ()
{
	int n,a,k=2,udal;//n - ��� ���������� ����� � ������; a - ��� �����, �������� �������������; k - ��� ���������� ����� � ������ ��� �������;
//udal - ��� �������, ������� ����� �������.
	Tree *root=new Tree, *per;
	setlocale(0,"Russian");
	cout<<"\n ������� ���������� �����, �������� �� ������ ��������� ������. ";
	cin>>n;
	cout<<"\n ������� �����.";
	cin>>a;
	root=Root(a);
	while (k<=n)
	{
		cout<<"\n ������� �����.";
		cin>>a;
		per=root;
		Child(a,per);
		k++;
	}
	cout<<"\n �������� ������:\n";
	Vyvod(0,n,0,root);
	cout<<"\n ������� �����, ������� ������ ������� �� ������. ";
	cin>>udal;
	root=Del(udal,root);
	cout<<"\n �������� ������ ��� ��������, ������� �� ������ �������:\n";
	Vyvod(0,n,0,root);
	system("pause");
}