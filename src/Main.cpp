#include <iostream>
#include "PersonArray_t.h"
#include "Person_t.h"
#include "Test_t.h"
using namespace std;


//==============================================================

int main() {
	bool cont = true;			// trigger to stop loop

	/*PersonArray_t* arr = new PersonArray_t(2, 3);
	cout << "initial array" << endl;
	arr->toString();
	cout << "==============" << endl;

	Person_t* person1 = new Person_t("person 1", 21);
	Person_t* person2 = new Person_t("person 2", 22);
	Person_t* person3 = new Person_t("person 3", 23);
	Person_t* person4 = new Person_t("person 4", 24);
	Person_t* person5 = new Person_t("person 5", 25);
	Person_t* person6 = new Person_t("person 6", 26);

	arr->insertNewElement(person1);
	arr->insertNewElement(person2);
	cout << "inserting 2 elements" << endl;
	arr->toString();
	cout << "==============" << endl;

	arr->insertNewElement(person3);
	cout << "inserting 3rd element" << endl;
	arr->toString();
	cout << "==============" << endl;

	arr->insertNewElement(person4);
	arr->insertNewElement(person5);
	cout << "inserted 5 elements total" << endl;
	arr->toString();
	cout << "==============" << endl;

	arr->insertNewElement(person6);
	cout << "inserting 6th element" << endl;
	arr->toString();
	cout << "==============" << endl;

	cout << "first element: " << arr->getFirstElement()->toString() << endl;
	cout << "last element: " << arr->getLastElement()->toString() << endl;

	cout << "find person 3: " << arr->findElement(person3)->toString() << endl;

	cout << "==============" << endl;
	cout << "remove person 4: " << arr->removeElement(person4)->toString() << endl;
	arr->toString();

	cout << "append person 4 at index 3. Result = " << arr->append(3, person4) << endl;
	arr->toString();

	cout << "==============" << endl;
	cout << "remove person 2: " << arr->removeElement(person2)->toString() << endl;
	arr->toString();

	cout << "preappend person 2 at index 3. Result = " << arr->prepend(3, person2) << endl;
	arr->toString();*/

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


		cout << "Enter your choice:" << endl
			<< "1 - insert" << endl
			<< "2 - find" << endl
			<< "3 - remove" << endl
			<< "4 - print" << endl
			<< "Any other key - quit" << endl;
		cin >> c;

		switch (c) {
		case 1:
			cout << "Enter name and age: ";
			cin >> name;
			cin >> age;
			test->insert(name, age);
			break;
		case 2:
			cout << "Enter name and age: ";
			cin >> name;
			cin >> age;
			test->find(name, age);
			break;
		case 3:
			cout << "Enter name and age: ";
			cin >> name;
			cin >> age;
			test->remove(name, age);
			break;
		case 4:
			test->print();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}
