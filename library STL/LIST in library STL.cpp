#include <iostream>
#include <list>

using namespace std;

/*
 Отличие list от vector в том, что в листе перемещаться по элементам
 можно только с помощью оператора и без индексов, как это обычно делается в 
 массивах: [] - с помощью квадратных скобок, указывая номер элемента массива(его 
 индекс).
*/


template<typename T>
void print_list(const list<T>& lst);


int main()
{
	setlocale(LC_ALL, "Russian");

	// Можно создать list сразу c элементами внутри:
	list<int> practice_list = {634, 297, 120};
	// А можно просто создать list:
	//list<int> practice_list;

	practice_list.push_back(5294);
	practice_list.push_back(602);
	practice_list.push_front(777);
	practice_list.push_front(313);

	// LIST - не поддерживает индексирование через перегруженный опертор
	// квадратных скобочек( [] ).

	// Создание итератора:
	list<int>::iterator it;
	it = practice_list.begin();
	// Строчками выше мы создаем перменную(it) типа(данных) итератор(iterator),
	// для листа(list), который хранит элементы типа int и присваеваем туда 
	// результат работы метода begin() - который возвращает итератор, который 
	// хранит указатель на самый первый элемент нашего листа(list).

	// Или так:
	// list<int>::iterator it = practice_list.begin();

	// Так же можно использовать ключевое слово auto:
	auto it_2 = practice_list.begin();
	// только все в одну строчку иначе ключевое слово
	//  не будет значть что подставлять вместо себя.

	// Вывод разыменовонного итератора в консоль:
	cout << *it << " - первый элемент списка." << endl;

	cout << "Вывод всего спсика на экран: " << endl;
	for (auto ii = practice_list.begin(); ii != practice_list.end(); ++ii)
	{
		cout << *ii << ' ';
	}
	cout << endl;

	// Метод для сортировки списка:
	practice_list.sort();

	cout << endl << "Отсортированный список: " << endl;
	print_list(practice_list);

	// Удаление первого элемента в списке:
	practice_list.pop_front();
	// Удаление послденего элемента в списке:
	practice_list.pop_back();

	cout << endl << "Удаление первого и последнего элементов списка: " << endl;
	print_list(practice_list);

	cout << endl << "Количество элементов списка(длинна списка): " 
		<< practice_list.size() << endl;

	return 0;
}


template<typename T>
void print_list(const list<T>& lst)
{
	cout << "Вывод всего спсика на экран: " << endl;
	for (auto ii = lst.cbegin(); ii != lst.cend(); ++ii)
	{
		cout << *ii << ' ';
	}
	cout << endl;
}