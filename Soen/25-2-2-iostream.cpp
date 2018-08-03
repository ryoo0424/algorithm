#include<iostream>
#include"Turboc.h"

using namespace std;

int main(){
	int i = 123;
	char ch = 'A';
	double d = 3.14;
	char str[] = "string";
	
	cout<<i<<"\t"<<ch<<"\n"<<d<<" "<<str<<endl;	
	
	int j;
	cout << "\ninput an integer" << endl;
	cin >> j;
	cout << "your integer is " << j <<"\n";
	
	return 0;
}
