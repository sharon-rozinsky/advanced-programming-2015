#include <string>

using namespace std;

#ifndef PERSON_T_H_
#define PERSON_T_H_

class Person_t {
	public:
		// Ctor's
		Person_t		();
		Person_t		(const string name, const int age);

		// Accessors
		void setName		(const string name);
		void setAge			(const int age);
		string getName		() const;
		int	 getAge			()const;

		// Class Methods
		string toString	();

		// Operators
		Person_t& operator=(const Person_t &other);
		bool operator==(const Person_t &other);

	private:
		const size_t 	m_id = m_globID;		// Unique for each Person_t object
		string			m_name;					// person name
		int				m_age;					// person age
		static int		m_globID;				// used to calculate m_id
};


#endif /* PERSON_T_H_ */
