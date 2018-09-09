#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {
	string n;
	int b;
	cin >> n >> b;
	int ans = 0, digit = n.length() - 1;
	for (int i=digit; i>=0; i--) {
		int tmp;
		if (n[i] > '9' || n[i] < '0') tmp = n[i] - 'A' + 10;
		else tmp = n[i] - '0';
		ans += tmp * pow(b, digit - i);
	}
	cout << ans << endl;
	return 0;
}
