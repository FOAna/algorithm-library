#include"Pol'skaya.h"
void main()
{
	int prav;
	char stroka[255];
	List *zap, *vyv;
	setlocale(0,"Russian");
	cout<<"������� ���������.\n";
	cin>>stroka;
	prav = Kontrol(stroka);
	List *Stek = Queue(0);
	List *Ocher = Queue(0);
	if (prav!=NULL)
		zap = Polka(stroka,Ocher,Stek);
	if ((prav!=NULL)&&(zap!=NULL))
	{
		cout<<" �������� �������� ������ ������ ���������: ";
		vyv = Vyvod(Ocher);
		cout<<"\n";
	}
	system("pause");
}