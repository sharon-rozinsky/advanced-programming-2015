/*
 * Person_t.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Rozinsky
 */
#include "Person_t.h"
#include <stdio.h>
#include <stdlib.h>

Person_t::Person_t(string name, int age)
{
	m_name = name;
	m_age = age;
}

string Person_t::toString()
{
	return "name: " + m_name + ", age: " + to_string(m_age);
}



