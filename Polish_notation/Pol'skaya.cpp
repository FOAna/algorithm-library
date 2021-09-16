#include"Pol'skaya.h"
List *Queue(char a)//a - ��� ������, �, ����, ������������ ������� ������.
{
	List *elem = new List;//��������� ������ ��� ��������� � ������.
	elem->a=a;//����������� ���� ��������� �������� ������� �������� ������.
	elem->next = NULL;//���������� �������� � ���� ������ ���� ���.
	elem->prev = NULL;//����������� �������� � ���� ������ ���� ���� ���.
	return elem;
}

List *Add_Queue(char a,List *last)//a - ��� ����������� � ������ �������; *last - ��� ��������� �� ��������� ������� � ������.
{
	if (last!=NULL)
	{
		List *elem = new List;
		elem->prev = last;//��������� ����� ��������� � ��������� ��������� ������.
		elem->next = NULL;//���������� �������� ���� ���.
		elem->a=a;//����������� ����� ��������� �������� ������������ � ������ ��������.
		last->next=elem;//��������� ��������� ������� ������ � ����� ����������.
		last=elem;
	}
	else
		last=Queue(last->a);
	return last;
}

List *Del_Queue(List *first)//*first - ��� ��������� �� ������ ������� � �������.
{
	if (first!=NULL)
	{
		first = first->next;//����������� ������ ��������� �������� ��������� � ������� ���������.
		first->prev = NULL;//������� � ������ ��������� �������� ����������� ��������.
	}
	else
		first=Queue(first->a);
	return first;
}

List *Del_Stack(List *last)//*last - ��� ��������� �� ��������� ������� � �����.
{
	if (last!=NULL)
	{
		last = last->prev;//����������� ��������� ��������� �������� ���������� � ����� ���������.
		last->next = NULL;//������� � ��������� ��������� �������� ���������� ��������.
	}
	else
		last=Queue(last->a);
	return last;
}

List *Beg(List *first)//*first - ��� ��������� �� ������ ������� � ������.
{
	List*p = first;
	while (p!=NULL)//���� �� ����� �� ���������� �������� � ������.
		p = p->next; 
	return first;
}

int Kontrol(char *a)//*a - ��� ��������� �� ������ � ����������.
{
	int skobyot=0, skobyzak=0, znaki=0, n = strlen(a), pr=1;//skobyot - ��� ������� ���������� ����������� �������� � ���������;
//skobyzak - ��� ������� ���������� ����������� �������� � ���������; znaki - ��� ������� ���������� ������ ������ ������ � ���������;
//n = strlen(a) - ���������� ����� ������ � ����������; pr=1 - ������������ ���������� ��� ��������� ���������� ���������, ���� ��������� �����������.
	for (int i=0;i<n;i++)//����������� ������ �� ������.
	{
		if (a[i]=='(')//������� ���������� ����������� ��������.
			skobyot++;
		if (a[i]==')')//������� ���������� ����������� ��������.
			skobyzak++;
		if ((a[i]=='+')||/*(a[i]=='-')||*/(a[i]=='/')||(a[i]=='*')||(a[i]=='^'))
			znaki++;//���� ��������� ������ ����������� ������.
		else
			znaki=0;
		if (znaki>1)
		{
			cout<<" � ��������� ���� ������ �����!\n";
			i=n;
			pr = NULL;
		}
		if (((a[i]=='+')||(a[i]=='-')||(a[i]=='/')||(a[i]=='*')||(a[i]=='^')||(a[i]=='('))&&((i==n-1)||(a[i+1]==')')))//���� ����� ������ ������ ���,
// ��� ������ �������� ������ ���.
		{
			cout<<" � ��������� �� ������� ���������!\n";
			i=n;
			pr = NULL;
		}
	}
	if ((pr!=NULL)&&(skobyot!=skobyzak))//���� ������ ��� �� ����������, � ���� �������� ��������.
	{
			cout<<" � ��������� �� ������� ��������!\n";
			pr = NULL;
	}
	return pr;
}

List *Polka(char *a,List *lastQ, List *lastS)//*a - ��� ���������, ���������������� �������� �������; *lastQ - ��� ��������� ������� �������;
//*lastS - ��� ��������� ������� �����.
{
	int n = strlen(a), sk=0;//sk - ������� ���������� ����������� ��������.
	List *firstQ = lastQ;//���������� ������ ������� �������.
	for (int i=0;i<n;i++)//����������� ������ �� ������.
	{
		if (isdigit(a[i]))//���� ������� ������ �������� ������.
		{
			lastQ = Add_Queue(a[i],lastQ);//���������� ����� � �������.
			if ((a[i+1]=='(')||(a[i-1]==')'))//���� ����� � �������� �����������, � ��� ����� ������� �� ���������.
			{
				int v;//���������� ��� ������.
				cout<<"<< "<<a[i-1]<<a[i]<<a[i+1]<<" >>"<<" ����� ��������� ������� ��������� �� �������� ���������?\n";
				cout<<" 1) ��, � ���� ����������� ����� ���������.\n 2) ���, ��� ������, � ���� ������ ������ ���������.\n";
				cin>>v;
				switch(v)
				{
				case 1:
					{
						while (((lastS->a=='*')||(lastS->a=='/')||(lastS->a=='^'))&&(lastS->prev!=NULL))//�������� �������� ������ ��� ���������.
						{
							lastQ = Add_Queue(lastS->a,lastQ);
							lastS = Del_Stack(lastS);
						}
						char b = '*';
						lastS = Add_Queue(b,lastS);
						break;
					}
				case 2:
					{
						i=n;
						firstQ = NULL;
						break;
					}
				default:
					{
						cout<<"����� ������� �� ���� ���������: 1 ��� 2.\n";
						i=n;
						firstQ = NULL;
						break;
					}
				}
			}
		}
		else
		{
			switch(a[i])
			{
			case '+':
				{
					while ((lastS->a!='(')&&(lastS->prev!=NULL))
					{
						lastQ = Add_Queue(lastS->a,lastQ);
						lastS = Del_Stack(lastS);
					}
					lastS = Add_Queue(a[i],lastS);
					break;
				}
			case '-':
				{
					if ((i==0)||(a[i-1]=='+')||(a[i-1]=='-')||(a[i-1]=='*')||(a[i-1]=='/')||(a[i-1]=='(')||(a[i-1]=='^'))//�������� �� ������� �����.
					{
						char un = '!';
						lastQ = Add_Queue(un,lastQ);
					}
					else
					{
						while ((lastS->a!='(')&&(lastS->prev!=NULL))
						{
							lastQ = Add_Queue(lastS->a,lastQ);
							lastS = Del_Stack(lastS);
						}
						lastS = Add_Queue(a[i],lastS);
					}
					break;
				}
			case '(':
				{
					sk++;
					lastS = Add_Queue(a[i],lastS);
					break;
				}
			case ')':
				{
					if (sk>0)
					{
						while (lastS->a!='(')
						{
							lastQ = Add_Queue(lastS->a,lastQ);
							lastS = Del_Stack(lastS);
						}
						lastS = Del_Stack(lastS);
					}
					break;
				}
			case '*':
				{
					while (((lastS->a=='*')||(lastS->a=='/')||(lastS->a=='^'))&&(lastS->prev!=NULL))
					{
						lastQ = Add_Queue(lastS->a,lastQ);
						lastS = Del_Stack(lastS);
					}
					lastS = Add_Queue(a[i],lastS);
					break;
				}
			case '/':
				{
					while (((lastS->a=='*')||(lastS->a=='/')||(lastS->a=='^'))&&(lastS->prev!=NULL))
					{
						lastQ = Add_Queue(lastS->a,lastQ);
						lastS = Del_Stack(lastS);
					}
					lastS = Add_Queue(a[i],lastS);
					break;
				}
			case '^':
				{
					while ((lastS->a=='^')&&(lastS->prev!=NULL))
					{
						lastQ = Add_Queue(lastS->a,lastQ);
						lastS = Del_Stack(lastS);
					}
					lastS = Add_Queue(a[i],lastS);
					break;
				}
			default:
				{
					cout<<"\n ������� �����, ������� �� ������ ���� � ���������!\n";
					i=n;
					firstQ = NULL;
					break;
				}
			}
		}
	}
	while (lastS->a!=NULL)
	{
		lastQ = Add_Queue(lastS->a,lastQ);
		lastS = Del_Stack(lastS);
	}
	return firstQ;
}

List *Vyvod(List *first)
{
	if (first==NULL)//���� ������ �������� ������
	{
		cout<<"\n������ ������!\n";
		return NULL;
	}
	List*p=first;//*p - ��� ��������� �� ��������������� �������, � ������� �������� �������������� ������ �� ������
	while(p!=NULL)
	{
		cout<<p->a<<" ";
		p=p->next;
	}
	return first;
}