#include <iostream>
using namespace std;

#include "employee.h"			//defines class Employee
#include "ksiazka.h"
#include "map_template.h"		//defines template map_template<Key,Value>

int main(void)
{
	typedef unsigned int ID; 							//Identification number of Employee
	map_template<ID,Employee> Database;					//Database of employees

	Database.Add(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	Database.Add(510212881,Employee("Adam Nowak","storekeeper",54)); 	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	Database.Add(730505129,Employee("Anna Zaradna","secretary",32)); 	//Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << Database << endl;							//Print databese

	map_template<ID,Employee> NewDatabase = Database;	//Make a copy of database
	cout << NewDatabase << endl;

	Employee* pE;
	pE = NewDatabase.Find(510212881);					//Find employee using its ID
	pE->Position = "salesman";							//Modify the position of employee
	pE = NewDatabase.Find(761028073);					//Find employee using its ID
	pE->Age = 29;										//Modify the age of employee

	Database = NewDatabase;								//Update original database
	
	cout << Database << endl;							//Print original databese
	
	typedef const char* tytul; 							//Identification number of ksiazka
	map_template<tytul,ksiazka> Database2;					//Database of ksiazka

	Database2.Add("U pana Boga na polu",ksiazka("Jan Kowalski","dostepna",28)); 	
	Database2.Add("U dwoch takich co ukradli slonce",ksiazka("Adam Nowak","niedostepna",54)); 	
	Database2.Add("Co w trawie piszczy",ksiazka("Anna Zaradna","dostepna",32)); 	

	cout << Database2 << endl;							//Print databese

	map_template<tytul,ksiazka> NewDatabase2 = Database2;	//Make a copy of database
	cout << NewDatabase2 << endl;

	ksiazka* pE2;
	pE2 = NewDatabase2.Find("U pana Boga na polu");				
	pE2->status = "niedostepna";							
	pE2 = NewDatabase2.Find("U dwoch takich co ukradli slonce");					
	pE2->liczba_stron = 29;										

	Database2 = NewDatabase2;								//Update original database
	
	cout << Database2 << endl;							//Print original databese
}
