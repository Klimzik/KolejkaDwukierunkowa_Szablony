#include <iostream>
#include <string>
using namespace std;

template <typename Object>
class Dataa {
public:
	Object a;
	Dataa* next{ nullptr }, * prev{ nullptr };
};

template <typename Object>
class Deque {
public:
	Dataa<Object>* first_{ nullptr }, * last_{ nullptr };
	int counter_{ 0 };
	
	int rozmiar() const;															//Zwraca ilość obiektów przechowywanych w deque.
	bool isEmpty() const;															//Zwraca true jeśli deque jest pusty
	void pierwszy(Dataa<Object>*& first); 											//Zwraca pierwszy obiekt w deque.
	void ostatni(Dataa<Object>*& last);												//Zwraca ostatni obiekt w deque.
	void wstawPierwszy(Dataa<Object>*& first, Dataa<Object>*& last, int& counter);	//Dodaje obiekt do pocza̧tku deque’a.
	void usunPierwszy(Dataa<Object>*& first, Dataa<Object>*& last, int& counter);	//Usuwa pierwszy obiekt z deque.
	void wstawOstatni(Dataa<Object>*& first, Dataa<Object>*& last, int& counter);	//Dodaje obiekt na końcu deque’a.
	void usunOstatni(Dataa<Object>*& first, Dataa<Object>*& last, int& counter);	//Usuwa ostatni obiekt z deque.
};

template<class Object> int Deque<Object>::rozmiar() const
{
	return counter_;
}

template<class Object> bool Deque<Object>::isEmpty() const
{
	if (rozmiar() == 0)
		return true;
	else
		return false;
}

template<class Object> void Deque<Object>::pierwszy(Dataa<Object>*& first)
{
	if (rozmiar() == 0)
		cout << endl << "DequeEmptyException";
	else
		cout << endl << "Twoj pierwszy element to " << first->a;
}

template<class Object> void Deque<Object>::ostatni(Dataa<Object>*& last)
{
	if (rozmiar() == 0)
		cout << endl << "DequeEmptyException";
	else
		cout << endl << "Twoj ostatni element to " << last->a;

}

template<class Object> void Deque<Object>::wstawPierwszy(Dataa<Object>*& first, Dataa<Object>*& last, int& counter)
{
	Dataa<Object>* newest = new Dataa<Object>;
	counter++;
	if (rozmiar() == 1)
	{
		last = newest;
		newest->next = nullptr;
	}
	else
	{
		newest->next = first;
		first->prev = newest;
	}
	first = newest;
	newest->prev = nullptr;
	cout << endl << "Podaj element: ";
	cin >> newest->a;
}

template<class Object> void Deque<Object>::usunPierwszy(Dataa<Object>*& first, Dataa<Object>*& last, int& counter)
{
	if (rozmiar() == 0)
	{
		cout << endl << "DequeEmptyException";
		return;
	}
	if (rozmiar() == 1)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = nullptr;
	}
	counter--;
}

template<class Object> void Deque<Object>::wstawOstatni(Dataa<Object>*& first, Dataa<Object>*& last, int& counter)
{
	Dataa<Object>* newest = new Dataa<Object>;
	counter++;
	if (rozmiar() == 1)
	{
		first = newest;
		newest->prev = nullptr;
	}
	else
	{
		last->next = newest;
		newest->prev = last;
	}
	last = newest;
	newest->next = nullptr;
	cout << endl << "Podaj element: ";
	cin >> newest->a;
}

template<class Object> void Deque<Object>::usunOstatni(Dataa<Object>*& first, Dataa<Object>*& last, int& counter)
{
	if (rozmiar() == 0)
	{
		cout << endl << "DequeEmptyException";
		return;
	}
	if (rozmiar() == 1)
	{
		delete last;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}
	counter--;
}

int main()
{
	Deque<string> my_deque;
	int choice{ 0 };
	while (1)
	{
		cout << "\n1 - dodanie elemntu na poczatek\n2 - usuniecie elementu z poczatku\n3 - wyswietlenie pierwszego elementu\n4 - dodanie elemntu na koniec\n5 - usuniecie elementu z konca\n6 - wyswietlenie ostatniego elementu\n7 - wyswietlenie liczby elementow\n8 - sprawdzenie czy struktura jest pusta\nwybor: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			my_deque.wstawPierwszy(my_deque.first_, my_deque.last_, my_deque.counter_);
			break;
		}
		case 2:
		{
			my_deque.usunPierwszy(my_deque.first_, my_deque.last_, my_deque.counter_);
			break;
		}
		case 3:
		{
			my_deque.pierwszy(my_deque.first_);
			break;
		}
		case 4:
		{
			my_deque.wstawOstatni(my_deque.first_, my_deque.last_, my_deque.counter_);
			break;
		}
		case 5:
		{
			my_deque.usunOstatni(my_deque.first_, my_deque.last_, my_deque.counter_);
			break;
		}
		case 6:
		{
			my_deque.ostatni(my_deque.last_);
			break;
		}
		case 7:
		{
			cout << endl << "liczba elementow: " << my_deque.rozmiar();
			break;
		}
		case 8:
		{
			if (my_deque.isEmpty() == true)
				cout << endl << "brak elementow";
			else
				cout << endl << "nie jest pusta";
			break;
		}
		}
	}
}