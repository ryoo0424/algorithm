#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(void){
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		stack<char> s;
		string line;
		getline(cin, line);
		for (int i=0; line[i]; i++) {
			if (line[i] == '(') s.push(line[i]);
			else {
				if (s.size()) s.pop();
				else s.push(line[i]);
			}
		}
		if (!s.size()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
