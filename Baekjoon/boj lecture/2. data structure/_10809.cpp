#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin >> s;
	for (int i='a'; i<='z'; i++) {
		auto target = find(s.begin(), s.end(), i);
		if (target == s.end()) cout << -1 << ' ';
		else cout << target - s.begin() << ' ';		
	}		
	return 0;
}
