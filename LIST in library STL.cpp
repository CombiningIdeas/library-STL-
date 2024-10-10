#include <iostream>
#include <list>

using namespace std;

/*
 ������� list �� vector � ���, ��� � ����� ������������ �� ���������
 ����� ������ � ������� ��������� � ��� ��������, ��� ��� ������ �������� � 
 ��������: [] - � ������� ���������� ������, �������� ����� �������� �������(��� 
 ������).
*/


template<typename T>
void print_list(const list<T>& lst);


int main()
{
	setlocale(LC_ALL, "Russian");

	// ����� ������� list ����� c ���������� ������:
	list<int> practice_list = {634, 11, 11, 297, 11, 120, 11};
	// � ����� ������ ������� list:
	//list<int> practice_list;

	practice_list.push_back(5294);
	practice_list.push_back(602);
	practice_list.push_front(777);
	practice_list.push_front(313);

	// LIST - �� ������������ �������������� ����� ������������� �������
	// ���������� ��������( [] ).

	// �������� ���������:
	list<int>::iterator it;
	it = practice_list.begin();
	// ��������� ���� �� ������� ���������(it) ����(������) ��������(iterator),
	// ��� �����(list), ������� ������ �������� ���� int � ����������� ���� 
	// ��������� ������ ������ begin() - ������� ���������� ��������, ������� 
	// ������ ��������� �� ����� ������ ������� ������ �����(list).

	// ��� ���:
	// list<int>::iterator it = practice_list.begin();

	// ��� �� ����� ������������ �������� ����� auto:
	auto it_2 = practice_list.begin();
	// ������ ��� � ���� ������� ����� �������� �����
	//  �� ����� ������ ��� ����������� ������ ����.

	// ����� ��������������� ��������� � �������:
	cout << *it << " - ������ ������� ������." << endl;

	cout << "����� ����� ������ �� �����: " << endl;
	for (auto ii = practice_list.begin(); ii != practice_list.end(); ++ii)
	{
		cout << *ii << ' ';
	}
	cout << endl;

	// �������� ������������ ���������� �� ������:
	cout << endl << "�������� ������������ ���������� �� ������: " << endl;
	practice_list.unique();

	print_list(practice_list);

	// ����� ��� ���������� ������:
	practice_list.sort();

	cout << endl << "��������������� ������: " << endl;
	print_list(practice_list);

	// �������� ������� �������� � ������:
	practice_list.pop_front();
	// �������� ���������� �������� � ������:
	practice_list.pop_back();

	cout << endl << "�������� ������� � ���������� ��������� ������: " << endl;
	print_list(practice_list);

	cout << endl << "���������� ��������� ������(������ ������): " 
		<< practice_list.size() << endl;

	// ������ ������ ������(list):
	// unique(); - ���� ���� ������ ��� �����������


	auto it_3 = practice_list.begin();

	// advance(a, b); - ��������� �������� �, � ������� b
	cout << endl << "����� �� ����� ������� �� ������� ���� ����� ��������:"
		<< endl;
	advance(it_3, 1);
	cout << *it_3 << endl;
	// ����� ���������� � ��� ������� ����� ��� ����� ������� ������ ����
	practice_list.insert(it_3, 12345678);

	advance(it_3, 3);
	cout << *it_3 << endl;
	practice_list.insert(it_3, 1892);

	advance(it_3, 2);
	cout << *it_3 << endl;
	practice_list.insert(it_3, 101010);


	// ������ ���������� ���������:
	cout << endl;
	print_list(practice_list);

	cout << endl << "���������� ��������� ������(������ ������): "
		<< practice_list.size() << endl;


	// ���� ��� �� ��� ����� ������� �� ���� ��� ���� � ������� �������� ���������:
	it_2 = it_3;
	practice_list.erase(--it_3);
	advance(it_2, -2);
	practice_list.erase(it_2);



	// ��� ���� ���� ����������, ����� ������ ������ erase ��������� � ��� ��������,
	// ��� �� ������� �� �� �������� � ������� � ��� �� ��������, ������ ������
	// ������, ������� ����� ����� ���������� ���� �������� � ������ ��� �������� 
	// ������ ���� ��������, ����� �� �������� ��������




	// ������ ���������� ���������:
	cout << endl << "������ ����� �������� ���� ���������: " << endl;
	cout << endl;
	print_list(practice_list);

	cout << endl << "���������� ��������� ������(������ ������): "
		<< practice_list.size() << endl;

	return 0;
}


template<typename T>
void print_list(const list<T>& lst)
{
	cout << "����� ����� ������ �� �����: " << endl;
	for (auto ii = lst.cbegin(); ii != lst.cend(); ++ii)
	{
		cout << *ii << ' ';
	}
	cout << endl;
}