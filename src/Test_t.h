#include <string>
#include <ostream>
#include "PersonArray_t.h"
#include "Person_t.h"
using namespace std;

class Test_t {
public:
	Test_t();
	Test_t(int initValue);
	Test_t(int initValue, int expandValue);

	void	insert(string name, int age);
	void 	getFirstPerson();
	void 	getLastPerson();
	void	find(string name, int age);
	void	remove(string name, int age);
	void	print();
public:
	PersonArray_t* arr;
};
