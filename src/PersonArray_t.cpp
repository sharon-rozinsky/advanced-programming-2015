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

}

void PersonArray_t::leftShiftArray(int index)
{

}
