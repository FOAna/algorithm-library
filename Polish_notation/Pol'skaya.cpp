#include"Pol'skaya.h"
List *Queue(char a)//a - это первый, и, пока, единственный элемент списка.
{
	List *elem = new List;//Выделение памяти под структуру в списке.
	elem->a=a;//Присваиваем этой структуре значение первого элемента списка.
	elem->next = NULL;//Следующего элемента в этом списке пока нет.
	elem->prev = NULL;//Предыдущего элемента в этом списке тоже пока нет.
	return elem;
}

List *Add_Queue(char a,List *last)//a - это добавляемый в список элемент; *last - это указатель на последний элемент в списке.
{
	if (last!=NULL)
	{
		List *elem = new List;
		elem->prev = last;//Связываем новую структуру с последним элементом списка.
		elem->next = NULL;//Следующего элемента пока нет.
		elem->a=a;//Присваеваем новой структуре значение добавляемого в список элемента.
		last->next=elem;//Связываем последний элемент списка с новой структурой.
		last=elem;
	}
	else
		last=Queue(last->a);
	return last;
}

List *Del_Queue(List *first)//*first - это указатель на первый элемент в очереди.
{
	if (first!=NULL)
	{
		first = first->next;//Присваеваем первой структуре значение следующей в очереди структуры.
		first->prev = NULL;//Убираем у первой структуры значение предыдущего элемента.
	}
	else
		first=Queue(first->a);
	return first;
}

List *Del_Stack(List *last)//*last - это указатель на последний элемент в стеке.
{
	if (last!=NULL)
	{
		last = last->prev;//Присваеваем последней структуре значение предыдущей в стеке структуры.
		last->next = NULL;//Убираем у последней структуры значение следующего элемента.
	}
	else
		last=Queue(last->a);
	return last;
}

List *Beg(List *first)//*first - это указатель на первый элемент в списке.
{
	List*p = first;
	while (p!=NULL)//Пока не дойдём до последнего элемента в списке.
		p = p->next; 
	return first;
}

int Kontrol(char *a)//*a - это указатель на строку с выражением.
{
	int skobyot=0, skobyzak=0, znaki=0, n = strlen(a), pr=1;//skobyot - это счётчик количества открывающих скобочек в выражении;
//skobyzak - это счётчик количества закрывающих скобочек в выражении; znaki - это счётчик количества подряд идущих знаков в выражении;
//n = strlen(a) - вычисление длины строки с выражением; pr=1 - возвращаемая переменная для остановки выполнения программы, если выражение некорректно.
	for (int i=0;i<n;i++)//Поэлементый проход по строке.
	{
		if (a[i]=='(')//Подсчёт количества открывающих скобочек.
			skobyot++;
		if (a[i]==')')//Подсчёт количества закрывающих скобочек.
			skobyzak++;
		if ((a[i]=='+')||/*(a[i]=='-')||*/(a[i]=='/')||(a[i]=='*')||(a[i]=='^'))
			znaki++;//Если несколько знаков встречаются подряд.
		else
			znaki=0;
		if (znaki>1)
		{
			cout<<" В выражении есть лишние знаки!\n";
			i=n;
			pr = NULL;
		}
		if (((a[i]=='+')||(a[i]=='-')||(a[i]=='/')||(a[i]=='*')||(a[i]=='^')||(a[i]=='('))&&((i==n-1)||(a[i+1]==')')))//Если после знаков ничего нет,
// или внутри скобочек ничего нет.
		{
			cout<<" В выражении не хватает операндов!\n";
			i=n;
			pr = NULL;
		}
	}
	if ((pr!=NULL)&&(skobyot!=skobyzak))//Если ошибок ещё не обнаружено, и есть одинокие скобочки.
	{
			cout<<" В выражении не хватает скобочек!\n";
			pr = NULL;
	}
	return pr;
}

List *Polka(char *a,List *lastQ, List *lastS)//*a - это выражение, перезаписываемое польской записью; *lastQ - это последний элемент очереди;
//*lastS - это последний элемент стека.
{
	int n = strlen(a), sk=0;//sk - счётчик количества открывающих скобочек.
	List *firstQ = lastQ;//Запоминаем первый элемент очереди.
	for (int i=0;i<n;i++)//Поэлементый проход по строке.
	{
		if (isdigit(a[i]))//Если элемент строки является цифрой.
		{
			lastQ = Add_Queue(a[i],lastQ);//Добавление цифры в очередь.
			if ((a[i+1]=='(')||(a[i-1]==')'))//Если цифра и скобочка встречаются, и это можно принять за умножение.
			{
				int v;//Переменная для свитча.
				cout<<"<< "<<a[i-1]<<a[i]<<a[i+1]<<" >>"<<" Такое выражение следует принимать за операцию умножения?\n";
				cout<<" 1) Да, я хочу реализовать здесь умножение.\n 2) Нет, это ошибка, я хочу заново ввести выражение.\n";
				cin>>v;
				switch(v)
				{
				case 1:
					{
						while (((lastS->a=='*')||(lastS->a=='/')||(lastS->a=='^'))&&(lastS->prev!=NULL))//Кусочная польская запись для умножения.
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
						cout<<"Нужно выбрать из двух вариантов: 1 или 2.\n";
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
					if ((i==0)||(a[i-1]=='+')||(a[i-1]=='-')||(a[i-1]=='*')||(a[i-1]=='/')||(a[i-1]=='(')||(a[i-1]=='^'))//Проверка на унарный минус.
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
					cout<<"\n Введены знаки, которые не должны быть в выражении!\n";
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
	if (first==NULL)//Если список окажется пустым
	{
		cout<<"\nСписок пустой!\n";
		return NULL;
	}
	List*p=first;//*p - это указатель на вспомогательный элемент, с помощью которого осуществляется проход по списку
	while(p!=NULL)
	{
		cout<<p->a<<" ";
		p=p->next;
	}
	return first;
}