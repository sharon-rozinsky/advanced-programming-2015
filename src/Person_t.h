#include <string>

using namespace std;

#ifndef PERSON_T_H_
#define PERSON_T_H_

class Person_t {
	public:
		// Ctor's
		Person_t();
		Person_t(string name, int age);

		// Accessors
		void setName(string name);
		void setAge();
		string getName();
		string getAge();

		// Class Methods
		string toString();

		bool operator==(const Person_t &other);

	private:
		const size_t 	m_id = m_globID;		// Unique for each Person_t object
		string			m_name;		// person name
		int				m_age;		// person age
		static int		m_globID;	// used to calculate m_id
};


#endif /* PERSON_T_H_ */
