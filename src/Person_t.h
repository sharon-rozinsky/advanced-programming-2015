#include <string>

using namespace std;

class Person_t {
	public:
		// Ctor's
		Person_t(string name, int age);

		// Accessors
		void setName(string name);
		void setAge();
		string getName();
		string getAge();

		// Class Methods
		string toString();


	private:
		const size_t 	m_id=1;		// Unique for each Person_t object
		string			m_name;		// person name
		int				m_age;		// person age
		static int		m_globID;	// used to calculate m_id
	};
