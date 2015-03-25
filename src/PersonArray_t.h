/*
 * PersonArray_t.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Rozinsky
 */

#include "Person_t.h"

#ifndef PERSONARRAY_T_H_
#define PERSONARRAY_T_H_

class PersonArray_t {
	public:
		// Ctor's
		PersonArray_t();
		PersonArray_t(int initialValue);
		PersonArray_t(int initialValue, int expandValue, int capcity);
		~PersonArray_t();

		// Accessors
		int getCapacity();
		int getNumberOfElements();

		// Class Methods
		void insertNewElement(Person_t person);
		Person_t* getFirstElement();
		Person_t* getLastElement();
		Person_t* findElement(const Person_t person);
		Person_t* removeElement(const Person_t person);
		void removeAll();
		void removeAndDelete(Person_t person);
		void removeAndDeleteAll();
		int append(int index, Person_t person);
		int prepend(int index, Person_t person);

	private:
		int m_expandValue;
		int m_capacity;
		int m_currentSize;
		int m_initialValue;
		const int DEFAULT_EXPAND_VALUE = 15;

		Person_t** m_array;

		PersonArray_t(const PersonArray_t& obj);

		void expandArray();
		void rightShiftArray(int index);
		void leftShiftArray(int index);
		void reAllocate();
		void deAllocate();
		bool isAllocationNeeded();
		bool isDeAllocationNeeded();
		int findIndex(const Person_t person);
};


#endif /* PERSONARRAY_T_H_ */
