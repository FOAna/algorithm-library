#include"Trees.h"
void main ()
{
	int n,a,k=2,udal;//n - это количество чисел в дереве; a - это числа, вводимые пользователем; k - это количество чисел в дереве без первого;
//udal - это элемент, который нужно удалить.
	Tree *root=new Tree, *per;
	setlocale(0,"Russian");
	cout<<"\n ¬ведите количество чисел, которыми вы хотите заполнить дерево. ";
	cin>>n;
	cout<<"\n ¬ведите число.";
	cin>>a;
	root=Root(a);
	while (k<=n)
	{
		cout<<"\n ¬ведите число.";
		cin>>a;
		per=root;
		Child(a,per);
		k++;
	}
	cout<<"\n ƒвоичное дерево:\n";
	Vyvod(0,n,0,root);
	cout<<"\n ¬ведите число, которое хотите удалить из дерева. ";
	cin>>udal;
	root=Del(udal,root);
	cout<<"\n ƒвоичное дерево без элемента, который вы хотели удалить:\n";
	Vyvod(0,n,0,root);
	system("pause");
}