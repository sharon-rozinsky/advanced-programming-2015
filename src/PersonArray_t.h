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
		PersonArray_t(int initialValue);

		// Accessors
		int getCapacity();
		int getNumberOfElements();

		// Class Methods
		void insertNewElement(Person_t person);
		Person_t* getFirstElement();
		Person_t* getLastElement();
		Person_t* findElement(Person_t person);
		Person_t* removeElement(Person_t person);
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

		Person_t* m_array;

		void rightShiftArray(int index);
		void leftShiftArray(int index);
};


#endif /* PERSONARRAY_T_H_ */
