#include "PersonArray_t.h"
#include <stdio.h>
#include <stdlib.h>

PersonArray_t::PersonArray_t()
{
	m_array 		= new Person_t[DEFAULT_EXPAND_VALUE];
	m_expandValue 	= DEFAULT_EXPAND_VALUE;
	m_capacity 		= DEFAULT_EXPAND_VALUE;
	m_currentSize 	= 0;
}

PersonArray_t::PersonArray_t(int initialValue)
{
	m_capacity 		= initialValue;
	m_array 		= new Person_t[m_capacity];
	m_expandValue 	= DEFAULT_EXPAND_VALUE;
	m_currentSize 	= 0;
}

PersonArray_t::PersonArray_t(int initialValue, int expandValue, int capacity)
{
	m_array 		= new Person_t[initialValue];
	m_expandValue 	= expandValue;
	m_capacity 		= capacity;
	m_currentSize 	= 0;
}

int PersonArray_t::getNumberOfElements()
{
	return m_currentSize;
}

int PersonArray_t::getCapacity()
{
	return m_capacity;
}

void PersonArray_t::insertNewElement(Person_t person)
{
	// TODO: should we check if the person object is already in the array?
	if(isAllocationNeeded())
		expandArray();

	m_array[m_currentSize] = person;
	m_currentSize++;
}

Person_t* PersonArray_t::getFirstElement()
{
	if(m_currentSize > 0)
		return m_array[0];
	return NULL;
}

Person_t* PersonArray_t::getLastElement()
{
	if(m_currentSize > 0)
		return m_array[m_currentSize - 1];
	return NULL;
}

Person_t* PersonArray_t::findElement(const Person_t person)
{
	int indexInArray = findIndex(person);

	if(indexInArray >= 0)
		return m_array[index];
	return 0;
}

void PersonArray_t::rightShiftArray(int index)
{
	if (isAllocationNeeded())
	{
		reAllocate();
	}

	for (int i = m_currentSize; i >= index; i--)
	{
		m_array[i + 1] = m_array[i]; // i + 1 index is inside the array capacity due to the pre reallocation process.
	}
}

void PersonArray_t::leftShiftArray(int index)
{
	// This function Assumes that index is null. (i.e not overuns any pointer)
	for (int i = index; i < m_currentSize; i++)
	{
		m_array[i] = m_array[i + 1];
	}
}

Person_t* PersonArray_t::removeElement(const Person_t person)
{
	int index = findIndex(person);

	if (index == -1) // preson not found.
	{
		return 0;
	}

	Person_t* removedPersonPtr = &(m_array[index]);

	//Remove pointer to person and align the array (no delete!).


}


int PersonArray_t::findIndex(const Person_t person)
{
	for(int i = 0; i < m_currentSize; i++)
	{
		if(m_array[i] == person)
			return i;
	}
	return -1;
}
