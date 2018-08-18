#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	while(getline(cin, s)) {
		int lower = 0, upper = 0, num = 0, space = 0;
		for (int i=0; i<s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') lower += 1;
			else if (s[i] >= 'A' && s[i] <= 'Z') upper += 1;
			else if (s[i] >= '0' && s[i] <= '9') num += 1;
			else if (s[i] == ' ') space += 1;
		}
		printf("%d %d %d %d\n", lower, upper, num, space);
	}	
	return 0;
}
