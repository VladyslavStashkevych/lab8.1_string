// lab8.1_string.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 8.1
// Опрацювання багатовимірних масивів ітераційними та рекурсивними способами
// Варіант 19

// abccabbcanbmcnacnb

#include <iostream>
#include <string>

using namespace std;

int Count(const string s, const string cs, int* indexArr);
string Change(string str, int* indexArr);

int main() {
	string str;
	int  count = 0;

	cout << "Enter string:" << endl;
	getline(cin, str);
	int* arr = new int[str.length() / 3];

	count = Count(str, "abc", arr);
	cout << "String contained " << count << " groups of 'a', 'b', 'c'" << endl;

	cout << "Modified string (param) : " << str << endl;
	string dest;
	dest = Change(str, arr);
	cout << "Modified string (result): " << dest << endl;

	return 0;
}

int Count(const string s, const string cs, int* indexArr) {
	size_t pos = 0;
	int counter = 0;
	bool b = false;
	int k = 0;

	for (size_t i = 0; i < s.length(); i++) {
		b = false;
		if (s.find_first_of(cs, i) == i) {
			counter++;
			b = true;
		}
		if (counter != 0) {
			if (!b) {
				counter -= counter % 3;
			}
			else if (counter % 3 == 0) {
				indexArr[k] = i - 2;
				k++;
			}
		}
	}

	return counter / 3;
}

string Change(string s, int* indexArr) {
	int counter = 0;
	for (size_t i = 0; i < sizeof(indexArr) - 1; i++) {
		indexArr[i] -= i;
		s = s.erase(indexArr[i], 3);
		s.insert(indexArr[i], "**");
	}
	return s;
}