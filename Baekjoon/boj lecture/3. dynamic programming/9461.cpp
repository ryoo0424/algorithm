#include<iostream>
using namespace std;
long long d[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
int main(){
	int t, n;
	cin >> t;
	for (int i=10; i<=101; i++) d[i] = d[i-1] + d[i-5];
	while (t--) {
		cin >> n;
		cout << d[n] << endl;
	}
	return 0;
}
