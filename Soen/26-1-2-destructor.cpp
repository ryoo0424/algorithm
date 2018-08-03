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
		// 동적할당 된 부분이 있으므로 반드시 파괴자를 통해 할당 해제해야 함 
		~Person(){
			cout << Name << " is deleted." << endl;
			delete [] Name;
		}
		
		void OutPerson(){
			cout << Name << ", " << Age << endl;
		}
		
		void printAge(){
			cout << Age << endl;
		}
		
		void printName(){
			cout << Name << endl;
		}
};

int main(){
	Person Boy("그램", 25);
	Boy.OutPerson();
	
	Person *pGirl;
	pGirl = new Person("맥북", 19);
	pGirl->OutPerson();
	delete pGirl;
	 
	return 0;
}
