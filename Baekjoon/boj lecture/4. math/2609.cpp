#include<iostream>
using namespace std;
int gcd(int _a, int _b) {
	int g = 1;
	for (int i=2; i<=min(_a, _b); i++) if (_a % i == 0 && _b % i == 0) g = i;
	return g;
}
int main(){
	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	cout << g << endl << g*(a/g)*(b/g) << endl;
	return 0;
}
