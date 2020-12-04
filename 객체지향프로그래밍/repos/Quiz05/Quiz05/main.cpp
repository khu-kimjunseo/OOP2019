#include<iostream>
#include<list>
#include<iomanip>
using namespace std;

list<int> get_elements(int n) {
	list<int> temp(n);
	for (auto& elem : temp)
		elem = rand() % 101;
	return temp;
}

void get_command(string& cmd) {
	do{
		cout << endl;
		cout << "1. Print" << endl;
		cout << "2. Find Number" << endl;
		cout << "3. Sort" << endl;
		cout << "0. Exit" << endl;
		cout << "Input>> ";
		cin >> cmd;
	} while (!(cmd == "1" || cmd == "2" || cmd == "3" || cmd == "0"));
}

template<class T>
void print(T begin_iter, T end_iter) {
	int count = 0;
	for (auto iter = begin_iter; iter != end_iter; iter++) {
		cout << setw(4) << *iter;
		count++;
		if (count % 10 == 0)
			cout << endl;
	}
}

template<class T>
void count_val(T begin_iter, T end_iter) {
	auto key_value = *begin_iter;
	cout << "Enter the key: ";
	cin >> key_value;
	int count = 0;
	for (auto iter = begin_iter; iter != end_iter; iter++) 
		if (*iter == key_value)
			count++;
	
	cout << "Number of matching elements: " << count << endl;
}

template<class T>
void sort(T begin_iter, T end_iter) {
	for (auto iter1 = begin_iter; iter1 != end_iter; iter1++) {
		for (auto iter2 = iter1; iter2 != end_iter; iter2++) {
			if (*iter1 > * iter2) {
				auto temp = *iter1;
				*iter1 = *iter2;
				*iter2 = temp;
			}
		}
	}
}

int main() {
	list<int> myList = get_elements(100);
	string command;
	while (1) {
		get_command(command);
		if (command == "1")			print(begin(myList), end(myList));
		else if (command == "2")	count_val(begin(myList), end(myList));
		else if (command == "3")	sort(begin(myList), end(myList));
		else if (command == "0")	break;
	}
	cout << "Exit program.." << endl;
	return 0;
}