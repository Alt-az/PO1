#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string.h>

class Employee {
	public:
	const char* Position;
	const char* Name;
	unsigned int Age;
	Employee(const char* N, const char* Pos, int A) {
		Name = N;
		Position = Pos;
		Age = A;
	}

	Employee(const Employee& s) {

		Name = s.Name;
		Position = s.Position;
		Age = s.Age;
	}
	
};
	ostream& operator<<(ostream& o, const Employee& t) {
		return o<< "  Name:" << t.Name<< "  Position:" << t.Position<< "  Age:" << t.Age;
	}
#endif /* __EMPLOYEE_H__ */
