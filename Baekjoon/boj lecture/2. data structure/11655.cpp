#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string ROT13(string _s);
int main(){
	string s;
	getline(cin, s);
	cout << ROT13(s);
	return 0;
}
string ROT13(string _s) {
	for (int i=0; _s[i]; i++) {
		if (_s[i] >= 'A' && _s[i] <= 'Z') 
			_s[i] = (_s[i] + 13 - 'A') % 26 + 'A';
		else if (_s[i] >= 'a' && _s[i] <= 'z') 
			_s[i] = (_s[i] + 13 - 'a') % 26 + 'a';
		}
		return _s;	
}
