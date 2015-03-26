/*
 * Test_t.cpp

 *
 *  Created on: Mar 26, 2015
 *      Author: Rozinsky
 */
#include "Test_t.h"

Test_t::Test_t(int initValue)
{
	arr = new PersonArray_t(initValue);
}

Test_t::Test_t(int initValue, int expandValue)
{
	arr = new PersonArray_t(initValue, expandValue);
}

void Test_t::insert(string name, int age)
{
	Person_t* person = new Person_t(name, age);
	arr->insertNewElement(person);
	cout << "Added person!" << endl;
}

void Test_t::remove(string name, int age)
{
	Person_t* person = new Person_t(name, age);
	arr->removeAndDelete(person);
	cout << "Removed person!" << endl;
}

void Test_t::find(string name, int age)
{
	Person_t* person = new Person_t(name, age);
	Person_t* result = arr->findElement(person);
	if(result != 0)
		cout << "Found person: " << result->toString() << endl;
	else
		cout << "Person not found" << endl;
}

void Test_t::print()
{
	arr->toString();
}

