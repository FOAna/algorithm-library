#include"Trees.h"
Tree *Root(int a)//a - ��� ������ ������.
{
	Tree *elem = new Tree;//��������� ������ ��� ��������� � ������.
	elem->a=a;//����������� ���� ��������� �������� ������� �������� ������.
	elem->left = NULL;//������ ������ � ����� �������� ���� ���.
	elem->right = NULL;//������� ������ � ����� �������� ���� ���� ���.
	elem->level = NULL;//������� ����� ������ ����� 0;
	return elem;
}

Tree *Child(int a,Tree *root)//a - ��� ����������� � ������ �������; *root - ��� ��������� �� ������ ������.
{
	if (root)//���� ������ ������ ������ ����������.
	{
		root->level++;//������� ���������� ��������. ����������, ��� � ������������ �������� ������� �� ���� ������.
		if (a<=root->a)//���� ����������� ������� ������ �������� ��������.
		{
			if (root->left)//���� � �������� ���� ����� ������.
			{
				root=root->left;//������������ � �������� �� ������ ������.
				root=Child(a,root);//��������� ���������� �������, ����� ��������� ������� ������ ������.
			}
			else
			{
				Tree *elem = new Tree;
				elem->left = NULL;//������ ������ ���� ���.
				elem->right = NULL;//������� ������ ���� ���.
				elem->a=a;//����������� ������ ����� �������� ������������ � ������ ��������.
				root->left=elem;//���������� ������ ����� �� ��������.
			}
		}
		else
		{
			if (root->right)//���� � �������� ���� ������ ������.
			{
				root=root->right;//������������ � �������� �� ������� ������.
				root=Child(a,root);
			}
			else
			{
				Tree *elem = new Tree;
				elem->left = NULL;//������ ������ ���� ���.
				elem->right = NULL;//������� ������ ���� ���.
				elem->a=a;//����������� ������ ����� �������� ������������ � ������ ��������.
				root->right=elem;//���������� ������ ������ �� ��������.
			}
		}
	}
	else
		root=Root(a);//���� ����� ���, �� ������ ������ ������.
	return root;
}

Tree *Del(int a,Tree *root)
{
	Tree *prov1, *prov2, *list=NULL;//*list - ��� �������, ������������ ��������.
	if (!root)//���� ������� �� �������.
		list = root;
	else
	{
		if (root->a==a)//���� ����� ������, ������� ����� �������.
		{
			if (root->left==root->right)//���� ����� ����� ����� ������ ������.
			{
				free(root);
				//list = NULL;
			}
			else
			{
				if (!root->left)//���� � ����� ����� ���� ������ ���� ������(������).
				{
					prov1 = root->right;
					free(root);
					list = prov1;
				}
				else
				{
					if (!root->right)//���� � ����� ����� ���� ������ ���� ������(�����).
					{
						prov1=root->left;
						free(root);
						list = prov1;
					}
					else//���� � ���������� ����� ���� ��� ������.
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

void Vyvod(int a,int n,int lev,Tree *root)//a - ��� ���������� �������� ���������; n - ��� ���������� ��������� � ������;
//root - ��� ��������� �� ������ ������.
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
	Tree *kor = root,*rem = root;//rem - ��� ��������� �� ���������� ��������.
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

