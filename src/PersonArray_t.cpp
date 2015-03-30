#include "PersonArray_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

PersonArray_t::PersonArray_t()
{
	m_array 		= new Person_t*[DEFAULT_EXPAND_VALUE];
	m_expandValue 	= DEFAULT_EXPAND_VALUE;
	m_capacity 		= DEFAULT_EXPAND_VALUE;
	m_currentSize 	= 0;
}

PersonArray_t::PersonArray_t(const unsigned int initialValue)
{
	m_capacity 		= initialValue;
	m_initialValue  = initialValue;
	m_array 		= new Person_t*[m_capacity];
	m_expandValue 	= DEFAULT_EXPAND_VALUE;
	m_currentSize 	= 0;
}

PersonArray_t::PersonArray_t(const unsigned int initialValue, const int expandValue)
{
	m_array 		= new Person_t*[initialValue];
	m_expandValue 	= expandValue;
	m_capacity 		= initialValue;
	m_initialValue  = initialValue;
	m_currentSize 	= 0;
}

PersonArray_t::~PersonArray_t()
{
	for(int i = 0; i < m_currentSize; i++)
	{
		delete m_array[i];
	}

	delete[] m_array;
}

int PersonArray_t::getNumberOfElements() const
{
	return m_currentSize;
}

int PersonArray_t::getCapacity() const
{
	return m_capacity;
}

void PersonArray_t::reAllocate()
{
	//allocate new memory
	Person_t** newArray = new Person_t*[m_capacity + m_expandValue];
	updateNewAllocatedArray(newArray);
	m_capacity += m_expandValue;
}

void PersonArray_t::deAllocate()
{
	int newSize = ((int)(m_currentSize / m_expandValue) + 1) * m_expandValue;
	Person_t** newArray = new Person_t*[newSize];
	updateNewAllocatedArray(newArray);
	m_capacity = newSize;
}

void PersonArray_t::updateNewAllocatedArray(Person_t** const newArray)
{
	//copy element to new memory
	for (int i = 0; i < m_currentSize; i++)
	{
		newArray[i] = m_array[i];
	}

	//delete old memory and update m_array.
	delete[] m_array;
	m_array = newArray;
}

void PersonArray_t::insertNewElement(Person_t* const person)
{
	// TODO: should we check if the person object is already in the array?
	if(isAllocationNeeded())
		reAllocate();

	m_array[m_currentSize] = person;
	m_currentSize++;
}

Person_t* PersonArray_t::getFirstElement() const
{
	if(m_currentSize > 0)
		return m_array[0];
	return NULL;
}

Person_t* PersonArray_t::getLastElement() const
{
	if(m_currentSize > 0)
		return m_array[m_currentSize - 1];
	return NULL;
}

Person_t* PersonArray_t::findElement(Person_t* const person)
{
	int indexInArray = findIndex(person);

	if(indexInArray >= 0)
		return m_array[indexInArray];
	return 0;
}

void PersonArray_t::rightShiftArray(const unsigned int index)
{
	if (isAllocationNeeded())
	{
		reAllocate();
	}

	for (int i = m_currentSize; i >= index; i--)
	{
		m_array[i] = m_array[i-1]; // i + 1 index is inside the array capacity due to the pre reallocation process.
	}
}

void PersonArray_t::leftShiftArray(const unsigned int index)
{
	// This function Assumes that index is null. (i.e not overuns any pointer)
	for (int i = index; i < (m_currentSize-1); i++)
	{
		m_array[i] = m_array[i + 1];
	}
}

Person_t* PersonArray_t::removeElement(Person_t* const person)
{
	int index = findIndex(person);

	if (index == -1) // preson not found.
	{
		return 0;
	}

	Person_t* removedPersonPtr = m_array[index];

	//Remove pointer to person and align the array (no delete!).
	m_array[index] = NULL;
	leftShiftArray(index);

	m_currentSize--;

	//de allocate if needed.
	if (isDeAllocationNeeded())
	{
		deAllocate();
	}

	return removedPersonPtr;
}

void PersonArray_t::removeAll()
{
	for (int i = 0; i < m_currentSize; i++)
	{
		m_array[i] = NULL;
	}

	m_currentSize = 0;

	//de allocate if needed.
	if (isDeAllocationNeeded())
	{
		deAllocate();
	}
	
	//Here we always got an empty array with init capacity. 
}

void PersonArray_t::removeAndDelete(Person_t* const person)
{
	Person_t* removedPersonPtr = removeElement(person);
	delete(removedPersonPtr);

	//de allocate if needed.
	if (isDeAllocationNeeded())
	{
		deAllocate();
	}
}


void PersonArray_t::removeAndDeleteAll()
{
	int size = m_currentSize;
	// Note: hence we use array of pointers, the use of delete[] will not work!.
	while (m_currentSize > 0)
	{
		removeAndDelete(m_array[0]);
	}

	m_currentSize = 0;

	//de allocate if needed.
	if (isDeAllocationNeeded())
	{
		deAllocate();
	}
}

int  PersonArray_t::append(const unsigned int index, Person_t* const person)
{
	if ((person == NULL) || (index >= m_currentSize))
	{
		return 0;
	}

	rightShiftArray(index + 2);
	m_array[index+1] = person;
	m_currentSize++;

	return 1;
}

int  PersonArray_t::prepend(const unsigned int index, Person_t* const person)
{
	if ((person == NULL)  || (index >= m_currentSize))
	{
		return 0;
	}

	rightShiftArray(index + 1);
	m_array[index] = person;
	m_currentSize++;

	return 1;
}

int PersonArray_t::findIndex(Person_t* const person)
{
	if (person == NULL) return -1;

	for(int i = 0; i < m_currentSize; i++)
	{
		if (m_array[i] == NULL) continue;
		if(*m_array[i] == *person)
			return i;
	}
	return -1;
}

bool PersonArray_t::isAllocationNeeded()
{
	if ((m_currentSize + 1) > m_capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PersonArray_t::isDeAllocationNeeded()
{
	if (m_currentSize < (m_capacity - m_expandValue))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PersonArray_t::toString() const
{
	std::cout << "Array capacity: " << m_capacity << endl;
	cout << "Array length: " << m_currentSize << endl;
	cout << "[";
	for(int i = 0; i < m_currentSize; i++)
	{
		if (i + 1 != m_currentSize)
			cout << m_array[i]->toString() << ", ";
		else
			cout << m_array[i]->toString();
	}
	cout << "]" << endl;
}