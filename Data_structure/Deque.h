template <class T>
struct Deque_elem // ������� ��������������� �������
{
	T data; // �����-�� ������
	Deque_elem<T> *next = NULL; // ��������� �� ��������� ������� �������
	Deque_elem<T> *prev = NULL; // ��������� �� ���������� ������� �������
};


template <class T>
struct Deque // ��������������� �������
{
	Deque_elem<T> *head = NULL; // ��������� �� ������ (�������) ������� �������
	Deque_elem<T> *tail = NULL; // ��������� �� ��������� (������) ������� �������
};


/*		��������� ��������� �� �������, � ������� - ������, ������� ����� �������� � �������.
	��������� ������ � ������ (������) �������:
	������� ����� ������� �������, � ������� ���������� ������, ��������� ��� � ������ ��������� ������� ���, ��� ����� ������� ���������� ������ � �������.
	���� ��������� � ������� �� ����, ������� ������� � ���������� ���� ���������� ������.		*/
template <class T>
void AddtoTop(Deque<T> *deque, T data)
{
	if (deque->head == NULL) // ���� ������� ������ (������� �������� � ������� ���)
	{
		Deque_elem<T> *tmp = new Deque_elem<T>; // ������� ����� ������� �������
		deque->head = deque->tail = tmp; // ���������� �� ������ � ��������� �������� ������� ����������� ��������� �� ���� �������
		deque->head->data = data; // ��������� ������������� �������
	}
	else // ���� ������� �� ������
	{
		Deque_elem<T> *tmp = new Deque_elem<T>; // ������� ����� ������� �������
		tmp->data = data; // ��������� ������������� �������
		deque->head->next = tmp; // ��������� �� ��������� ������� ����������� ��������� �� ����� �������
		tmp->prev = deque->head; // ��������� ������ �������� �� ���������� ����������� ��������� �� ������� ������� �������
		deque->head = tmp; // ��������� �� ����� �������, ������ �� � ���� ����� ������� � �������
	}
}


/*		��������� ��������� �� �������, � ������� - ������, ������� ����� �������� � �������.
	��������� ������ � ����� (����) �������:
	������� ����� ������� �������, � ������� ���������� ������, ��������� ��� � ��������� ��������� ������� ���, ��� ����� ������� ���������� ��������� � �������.
	���� ��������� � ������� �� ����, ������� ������� � ���������� ���� ���������� ������.		*/
template <class T>
void AddtoEnd(Deque<T> *deque, T data)
{
	if (deque->tail == NULL) // ���� ������� ������ (���������� �������� � ������� ���)
	{
		Deque_elem<T> *tmp = new Deque_elem<T>; // ������� ����� ������� �������
		deque->head = deque->tail = tmp; // ���������� �� ������ � ��������� �������� ������� ����������� ��������� �� ���� �������
		deque->tail->data = data; // ��������� ������������� �������
	}
	else // ���� ������� �� ������
	{
		Deque_elem<T> *tmp = new Deque_elem<T>; // ������� ����� ������� �������
		tmp->data = data; // ��������� ��� �������
		deque->tail->prev = tmp; // ��������� �� ���������� ������� ����������� ��������� �� ����� �������
		tmp->next = deque->tail; // ��������� ������ �������� �� ��������� ������� ����������� ��������� �� ��������� ������� �������
		deque->tail = tmp; // ��������� �� ����� �������, ������ �� � ���� ����� ��������� (������) � �������
	}
}


// ��������� ��������� �� �������. ������� � ��������� ����� ��������� (������) ������� �������. **�� ���������� ��������� �� ������ ������� ** 
template <class T>
T GetfromEnd(Deque<T> *deque)
{
	T data = deque->tail->data; // �������� ������ �� �������� ������� � ����������

	Deque_elem<T> *tail = deque->tail; // ������� ��������� �� ��������� ������� �������
	deque->tail = deque->tail->next; // ������������ � ���������� (��������������) �������� �������

	if (deque->tail == NULL) // ���� �������������� �������� ������� ���
		deque->head = NULL; // ������� ��������� �� ������ ������� ������� (��������� � ������� ������ ���)

	delete tail; // ����������� ������, ������� ��� ��������� ������� �������

	return data;
}


// ��������� ��������� �� �������. ������� � ��������� ����� ������ (�������) ������� �������. **�� ���������� ��������� �� ������ ������� ** 
template <class T>
T GetfromTop(Deque<T> *deque)
{
	T data = deque->head->data; // �������� ������ �� �������� ������� � ����������
	Deque_elem<T> *head = deque->head; // ������� ��������� �� ������ ������� �������
	deque->head = deque->head->prev; // ������������ � ����������� (�������) �������� �������

	if (deque->head == NULL) // ���� ������� �������� ������� ���
		deque->tail = NULL; // ������� ��������� �� ��������� ������� ������� (��������� � ������� ������ ���)

	delete head; // ����������� ������, ������� ��� ������ ������� �������

	return data;
}