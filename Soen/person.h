#include "turboc.h"

using namespace std;

class Person{
	private:
		char *Name;
		int Age;
	
	public:
		Person(const char *_Name, int _Age){
			Name = new char[strlen(_Name) + 1];
			strcpy(Name, _Name);
			Age = _Age;
			cout << Name << " is created." << endl;
		}

		~Person(){
			cout << Name << " is deleted." << endl;
			delete [] Name;
		}
		
		void OutPerson(){
			cout << Name << ", " << Age << endl;
		}
};
