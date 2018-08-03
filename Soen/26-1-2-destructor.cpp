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
		// �����Ҵ� �� �κ��� �����Ƿ� �ݵ�� �ı��ڸ� ���� �Ҵ� �����ؾ� �� 
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
	Person Boy("�׷�", 25);
	Boy.OutPerson();
	
	Person *pGirl;
	pGirl = new Person("�ƺ�", 19);
	pGirl->OutPerson();
	delete pGirl;
	 
	return 0;
}
