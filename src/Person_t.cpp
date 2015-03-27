/*
 * Person_t.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Rozinsky
 */
#include "Person_t.h"
#include <stdio.h>
#include <stdlib.h>

int Person_t::m_globID = 1;

Person_t::Person_t()
{
	m_globID++;
}

Person_t::Person_t(const string name, const int age)
{
	setName(name);
	setAge(age);
	m_globID++;
}

void Person_t::setName(const string name)
{
	m_name = name;
}

void Person_t::setAge(const int age)
{
	m_age = age;
}

string Person_t::toString()
{
	return "(" + m_name + " ; " + to_string(m_age) + ")";
}

Person_t& Person_t::operator=(const Person_t &other)
{
	if (this != &other)
	{
		Person_t* result = new Person_t(this->m_name, this->m_age);
		return *result;
	}
	return *this;
}

bool Person_t::operator==(const Person_t &other)
{
	if(this->m_age == other.m_age && strcmp(this->m_name.c_str(), other.m_name.c_str()) == 0)
	{
		return true;
	}
	return false;
}


