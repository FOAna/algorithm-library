#include"Quick.h"
int *Sozd(int b)//b - ��� ���������� ��������� � �������.
{
	int*a = new int[b];//�������� ������������� ����������� �������.
	return a;
}

void Zap(int*a,int b)//a - ��� ���������� ������; b - ��� ���������� ��������� � �������.
{
	for (int i=0;i<b;i++)
		a[i]=1+rand()%99;//���������� ������� ���������� ������� �� 1 �� 99.
}

void Vyvod(int*a,int b)//a - ��� ���������� ������; b - ��� ���������� ��������� � �������.
{
	for (int i=0;i<b;i++)//����� ������� ����������.
		cout<<" "<<a[i];
	cout<<"\n";
}

void Bystr(int*a,int per,int posl)//a - ��� ���������� ������; per - ��� ����� ������� �������� ��� ����� �������, ������� ����� �������������;
	//posl - ��� ����� ���������� �������� ��� ����� �������, ������� ����� �������������.
{
	int vse=0, kolvo=0, sred, kmen=0, kbol=0, vsm=0;//vse - ��� ����� ���� ��������� �������, ������� �����������, ��� ���������� �������� ��������
	//��������� � ������������� ���������; kolvo - ��� ���������� ������������� ���������; sred - ��� ������� �������� ���������; kmen - ���
	//���������� ���������, ������� ��� ������ �������� ��������; kbol - ��� ���������� ���������, ������� �������� ��������;
	//vsm - ��� ��� �������� �������, ������� �������� ��������.
	for (int i=per;i<posl;i++)
	{
		vse+=a[i];//����� ����������� ��������� �������.
		kolvo++;//���������� ����������� ��������� �������.
	}
	sred=vse/kolvo;//���������� �������� ��������.
	//������� ��� ��������. � ����������� �� ��� ��� ���������� ���������. ������ �� �������, �����, ��� �����������.
	/*cout<<"������� ��������: "<<sred<<"\n";
	cout<<"���������� ���������: "<<kolvo<<"\n";*/
	int j=per;//��������� ���������� �� ������ ������� �������.
	for (int i=per;i<posl;i++)//���������� ������� �� ��� ������ - ��������, ������� ��� ������ �������� ��������, � ��������,
	//������� �������� ��������.
	{
		if (a[i]<=sred)
		{
			int c=a[j];
			a[j]=a[i];
			a[i]=c;
			j++;
			kmen++;//������� ���������, ������� ��� ������ �������� ��������.
		}
		else
			kbol++;//������� ���������, ������� �������� ��������.
	}
	//������� ��� ��������.
	/*cout<<"���������� ���������, ������� ��������:"<<kmen;
	cout<<"\n���������� ���������, ������� ��������:"<<kbol<<"\n";*/
	if (kmen>2)
	{
		//������� ��� ��������.
		/*cout<<"\n";
		for (int i=per;i<kmen;i++)
			cout<<" "<<a[i];
		cout<<"\n";*/
		Bystr(a,kolvo-kbol-kmen,kmen);
	}
	if (kbol>2)
	{
		int i=0;
		while (a[i]<sred)//���������� ������ �������� �������, � �������� ���������� �����, � ������� ��������, ������� �������� ��������.
		{
			vsm++;
			i++;
		}
		//������� ��� ��������.
		/*cout<<"\n";
		for (int i=vsm;i<posl;i++)
			cout<<" "<<a[i];
		cout<<"\n";*/
		Bystr(a,vsm,vsm+kbol);
	}
	for (int i=0;i<posl-1;i++)//��������� �������� ��������� ���������.
	{
		if (a[i]>a[i+1])
		{
			int c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
		}
	}
}