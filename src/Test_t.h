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
	~Test_t();

	void	insert(Person_t* person);
	void 	getFirstPerson();
	void 	getLastPerson();
	void	find(Person_t* person);
	void	remove(Person_t* person);
	void	removeAndDelete(Person_t* person);
	void 	removeAll();
	void	removeAndDeleteAll();
	void	append(Person_t* person, int index);
	void	prepend(Person_t* person, int index);
	void	print();
public:
	PersonArray_t* arr;
};
