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

Test_t::~Test_t()
{
	delete arr;
}

void Test_t::insert(Person_t* person)
{
	arr->insertNewElement(person);
	cout << "Added person!" << endl;
}

void Test_t::getFirstPerson()
{
	Person_t* person = arr->getFirstElement();
	if (person != NULL)
		cout << "Got first person: " << person->toString();
	else
		cout << "Couldn't get first person";
}

void Test_t::getLastPerson()
{
	Person_t* person = arr->getLastElement();
	if (person != NULL)
		cout << "Got last person: " << person->toString();
	else
		cout << "Couldn't get last person";
}

void Test_t::remove(Person_t* person)
{
	arr->removeElement(person);
	cout << "Removed person!" << endl;
}

void Test_t::removeAll()
{
	arr->removeAll();
	cout << "Removed person!" << endl;
}

void Test_t::removeAndDelete(Person_t* person)
{
	arr->removeAndDelete(person);
	cout << "Removed and deleted person!" << endl;
}

void Test_t::removeAndDeleteAll()
{
	arr->removeAndDeleteAll();
	cout << "Removed person!" << endl;
}

void Test_t::find(Person_t* person)
{
	Person_t* result = arr->findElement(person);
	if(result != 0)
		cout << "Found person: " << result->toString() << endl;
	else
		cout << "Person not found" << endl;
}

void Test_t::append(Person_t* person, int index)
{
	if(arr->append(index, person) == 1)
		cout << "Person appended at index: " << index << endl;
	else
		cout << "Person not appended" << endl;
}

void Test_t::prepend(Person_t* person, int index)
{
	if (arr->prepend(index, person) == 1)
		cout << "Person prepended at index: " << index << endl;
	else
		cout << "Person not prepended" << endl;
}

void Test_t::print()
{
	arr->toString();
}

