#include "PersonArray_t.h"
#include <stdio.h>
#include <stdlib.h>

PersonArray_t::PersonArray_t(int initialValue)
{
	m_initialValue = initialValue;
	m_array = new Person_t[m_initialValue];
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