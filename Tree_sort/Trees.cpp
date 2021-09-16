#include"Trees.h"
Tree *Root(int a)//a - это корень дерева.
{
	Tree *elem = new Tree;//Выделение памяти под структуру в списке.
	elem->a=a;//Присваиваем этой структуре значение первого элемента дерева.
	elem->left = NULL;//Левого ребёнка у этого родителя пока нет.
	elem->right = NULL;//Правого ребёнка у этого родителя тоже пока нет.
	elem->level = NULL;//Уровень корня дерева равен 0;
	return elem;
}

Tree *Child(int a,Tree *root)//a - это добавляемый в список элемент; *root - это указатель на корень дерева.
{
	if (root)//Если корень дерева вообще существует.
	{
		root->level++;//Уровень последнего родителя. Получается, что у добавляемого элемента уровень на один больше.
		if (a<=root->a)//Если добавляемый элемент меньше значения родителя.
		{
			if (root->left)//Если у родителя есть левый ребёнок.
			{
				root=root->left;//Перемещаемся с родителя на левого ребёнка.
				root=Child(a,root);//Запускаем рекурсивно функцию, чтобы проверить наличие левого ребёнка.
			}
			else
			{
				Tree *elem = new Tree;
				elem->left = NULL;//Левого ребёнка пока нет.
				elem->right = NULL;//Правого ребёнка пока нет.
				elem->a=a;//Присваеваем новому листу значение добавляемого в дерево элемента.
				root->left=elem;//Записываем ребёнка слева от родителя.
			}
		}
		else
		{
			if (root->right)//Если у родителя есть правый ребёнок.
			{
				root=root->right;//Перемещаемся с родителя на правого ребёнка.
				root=Child(a,root);
			}
			else
			{
				Tree *elem = new Tree;
				elem->left = NULL;//Левого ребёнка пока нет.
				elem->right = NULL;//Правого ребёнка пока нет.
				elem->a=a;//Присваеваем новому листу значение добавляемого в дерево элемента.
				root->right=elem;//Записываем ребёнка справа от родителя.
			}
		}
	}
	else
		root=Root(a);//Если корня нет, то создаём корень дерева.
	return root;
}

Tree *Del(int a,Tree *root)
{
	Tree *prov1, *prov2, *list=NULL;//*list - это элемент, возвращаемый функцией.
	if (!root)//Если вершина не найдена.
		list = root;
	else
	{
		if (root->a==a)//Если нашли корень, который нужно удалить.
		{
			if (root->left==root->right)//Если после этого корня дерево пустое.
			{
				free(root);
				//list = NULL;
			}
			else
			{
				if (!root->left)//Если у этого корня есть только один ребёнок(правый).
				{
					prov1 = root->right;
					free(root);
					list = prov1;
				}
				else
				{
					if (!root->right)//Если у этого корня есть только один ребёнок(левый).
					{
						prov1=root->left;
						free(root);
						list = prov1;
					}
					else//Если у удаляемого корня есть оба ребёнка.
					{
						prov1 = root->right;
						/*!*/prov2 = root->right;
						while (prov1->left)
							prov1=prov1->left;
						prov1->left = root->left;
						free(root);
						list = prov2;
					}
				}
			}
		}
		if (a>root->a)
			root->right = Del(a,root->right);
		if (a<root->a)
			root->left = Del(a,root->left);
	}
	return list;
}

void Vyvod(int a,int n,int lev,Tree *root)//a - это количество введённых элементов; n - это количество элементов в дереве;
//root - это указатель на корень дерева.
{
	/*Tree *per = root;
	if(!root)
		return;
	else
	{
		Vyvod(root->level+1,root->left);
		for(int i=0;i<=root->level;i++)
			cout<<" ";
		cout<<root->a<<"\n";
		Vyvod(root->level+1,root->left);
	}*/
	Tree *kor = root,*rem = root;//rem - это указатель на последнего родителя.
	if (!root->left)
	{
		for(int l=0;l<=lev;l++)
			cout<<"   ";
		cout<<root->a<<"\n";
		root = root->right;
		lev++;
		a++;
		if (a<n)
			Vyvod(a,n,lev,root);
	}
	else
	{
		while (root->left)
		{
			rem = root;
			root = root->left;
			lev++;
		}
		if (root->a)
		{
			for(int l=0;l<=lev;l++)
				cout<<"   ";
			cout<<root->a<<"\n";
			root->a=NULL;
			lev--;
			a++;
		}
		if (root->right)
		{
			while (root->right)
			{
				lev++;
				for(int l=0;l<=lev;l++)
					cout<<"   ";
				rem = root;
				root = root->right;
				cout<<root->a<<"\n";
				a++;
			}
			rem->right=NULL;
			lev--;
			if (a<n)
				Vyvod(a,n,lev,kor);
		}
		else
		{
			rem->left=NULL;
			lev--;
			if (a<n)
				Vyvod(a,n,lev,kor);
		}
	}
	/*if (!kor->left)
	{
		cout<<kor->a<<"\n";
		kor = kor->right;
		lev++;
		Vyvod(n,kor);
	}*/
	/*if (root->right)
	{
		while (root->right)
		{
			root = root->right;
			lev++;
		}
		for(int l=0;l<=lev;l++)
			cout<<" ";
		cout<<root->right<<"\n";
		a++;
		free(root->right);*/

}

