#include"turboc.h"

using namespace std;

int main(){
	// new & delete
	int *pi = new int;
	*pi = 123;
	// int *pi = new int(123);
	cout << "*pi = " << *pi << endl;
	delete pi;	
	
	// new struct
	struct tag_friend{
		char Name[10];
		int Age;
		double Height;
	};
	
	tag_friend *pF = new tag_friend;
	strcpy(pF->Name, "someone");
	pF->Age = 22;
	pF->Height = 177.7;
	cout	<< "이름 = " << pF->Name << " 나이 = " << pF->Age
			<< " 키 = " << pF->Height << endl;
	delete pF;
	
	// new array
	int *ar = new int[5];
	int i;
	for(i=0;i<5;i++){
		ar[i] = i;
	}
	for(i=0;i<5;i++){
		cout << "number " << i << " = " << ar[i] << endl;
	}
	delete [] ar;
		
	return 0;
}
