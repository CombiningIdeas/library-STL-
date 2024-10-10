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
	list<int> practice_list = {634, 11, 11, 297, 11, 120, 11};
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

	// Удаление определенных дубликатов из списка:
	cout << endl << "Удаление определенных дубликатов из списка: " << endl;
	practice_list.unique();

	print_list(practice_list);

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

	// разные методы списка(list):
	// unique(); - чуть выше описан для наглядности


	auto it_3 = practice_list.begin();

	// advance(a, b); - вставляем итератор а, в позицию b
	cout << endl << "Числа на месте которых мы вставим наши новые значения:"
		<< endl;
	advance(it_3, 1);
	cout << *it_3 << endl;
	// далее добавлеяем в эту позицию число тем самым сдвигая вправо лист
	practice_list.insert(it_3, 12345678);

	advance(it_3, 3);
	cout << *it_3 << endl;
	practice_list.insert(it_3, 1892);

	advance(it_3, 2);
	cout << *it_3 << endl;
	practice_list.insert(it_3, 101010);


	// теперь сравниваем реузльтат:
	cout << endl;
	print_list(practice_list);

	cout << endl << "Количество элементов списка(длинна списка): "
		<< practice_list.size() << endl;


	// есть так же еще много методов но есть еще один к примеру удаление элементов:
	it_2 = it_3;
	practice_list.erase(--it_3);
	advance(it_2, -2);
	practice_list.erase(it_2);



	// ТУТ ЕСТЬ ОДНО ОСОБЕНОСТЬ, ПОСЛЕ ВЫЗОВА МЕТОДА erase УДАЛЯЕТСЯ И САМ ИТЕРАТОР,
	// ИБО НА КОМАНДЫ ОН НЕ ОТВЕЧАЕТ И РАБОТАЬ С НИМ НЕ ВОЗМОЖНО, ВСЕГДА ВЫДАЕТ
	// ОШИБКУ, ПОЭТОМУ ЛЧШУЕ ВСЕГО КОПИРОВАТЬ ОДИН ИТЕРАТОР В ДРУГОЙ ПРИ УДАЛЕНИЕ 
	// КАКОГО ЛИБО ЭЛЕМЕНТА, ЧТОБЫ НЕ ПОТЕРЯТЬ ИТЕРАТОР




	// теперь сравниваем реузльтат:
	cout << endl << "Список после удаления пары элементов: " << endl;
	cout << endl;
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