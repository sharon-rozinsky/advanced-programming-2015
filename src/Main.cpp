#include <iostream>
#include "PersonArray_t.h"
#include "Person_t.h"
#include "Test_t.h"
using namespace std;


//==============================================================
Person_t* getPerson()
{
	int age;
	string name;

	cout << "Enter person details" << endl;
	cout << "name: ";
	cin >> name;
	cout << "age: ";
	cin >> age;

	return new Person_t(name, age);
}

int main() {
	bool cont = true;			// trigger to stop loop
	Test_t* test;

	int initArraySize;
	int expandValue;
	cout << "Init array. Enter initial array size: ";
	cin >> initArraySize;
	cout << endl;
	cout << "Enter expand value ('0' = default value of 15): ";
	cin >> expandValue;
	if(expandValue == 0)
		test = new Test_t(initArraySize);
	else
		test = new Test_t(initArraySize, expandValue);
	cout << expandValue << endl;

	while (cont) {
		unsigned int c;
		string name;
		int age;
		Person_t* person;
		int index;

		cout << "Enter your choice:" << endl
			<< "1 - insert" << endl
			<< "2 - find" << endl
			<< "3 - remove" << endl
			<< "4 - get first" << endl
			<< "5 - get last" << endl
			<< "6 - remove and delete" << endl
			<< "7 - remove all" << endl
			<< "8 - remove and delete all" << endl
			<< "9 - append" << endl
			<< "10 - prepend" << endl
			<< "11 - print" << endl
			<< "0 - quit" << endl;
		cin >> c;

		switch (c) {
		case 1:
			test->insert(getPerson());
			break;
		case 2:
			person = getPerson();
			test->find(person);
			delete person;
			break;
		case 3:
			person = getPerson();
			test->remove(person);
			delete person;
			break;
		case 4:
			test->getFirstPerson();
			break;
		case 5:
			test->getLastPerson();
			break;
		case 6:
			person = getPerson();
			test->removeAndDelete(person);
			delete person;
			break;
		case 7:
			test->removeAll();
			break;
		case 8:
			test->removeAndDeleteAll();
			break;
		case 9:
			person = getPerson();
			cout << "index: ";
			cin >> index;
 			test->append(person, index);
			break;
		case 10:
			person = getPerson();
			cout << "index: ";
			cin >> index;
			test->prepend(person, index);
			break;
		case 11:
			test->print();
			break;
		case 0:
			cont = false;
			break;
		default:
			cont = false;
			break;
		}

		cout << "----------------------------------------------" << endl;
	}

	delete test;

	return 0;
}