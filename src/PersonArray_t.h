/*
 * PersonArray_t.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Rozinsky
 */

#include "Person_t.h"
#include <iostream>
using namespace std;

#ifndef PERSONARRAY_T_H_
#define PERSONARRAY_T_H_


class PersonArray_t {
	public:
		// Ctor's
		PersonArray_t();
		PersonArray_t(const unsigned int initialValue);
		PersonArray_t(const unsigned int initialValue, const int expandValue);
		~PersonArray_t();

		// Accessors
		int getCapacity();
		int getNumberOfElements();

		// Class Methods
		void insertNewElement		(Person_t* const person);
		Person_t* getFirstElement	();
		Person_t* getLastElement	();
		Person_t* findElement		(Person_t* const person);
		Person_t* removeElement		(Person_t* const person);
		void removeAll				();
		void removeAndDelete		(Person_t* const person);
		void removeAndDeleteAll		();
		int append					(const unsigned int index, Person_t* const person);
		int prepend					(const unsigned int index, Person_t* const person);
		void toString();

	private:
		int			m_expandValue;
		int			m_capacity;
		int			m_currentSize;
		int			m_initialValue;
		const int	DEFAULT_EXPAND_VALUE = 15;

		Person_t**	m_array;

		// Private copy constructor to prevent copy of PersonArray_t objects.
		PersonArray_t(const PersonArray_t& obj);
		PersonArray_t& operator=(const PersonArray_t &other);

		 // Private class methods
		void rightShiftArray			(const unsigned int index);
		void leftShiftArray				(const unsigned int index);
		void reAllocate					();
		void deAllocate					();
		void updateNewAllocatedArray	(Person_t** const newArray);
		bool isAllocationNeeded			();
		bool isDeAllocationNeeded		();
		int findIndex					(Person_t* const person);
};


#endif /* PERSONARRAY_T_H_ */
