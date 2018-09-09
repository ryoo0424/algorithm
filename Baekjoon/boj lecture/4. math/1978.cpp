#include<iostream>
using namespace std;
int main() {
	int max = 1e6;
	bool prime[max];
	prime[1] = prime[0] = true;
	for (int i=2; i<=max; i++) {
		if (prime[i] == false) {
			for (int j=i*2; j<=max; j+=i) {
				prime[j] = true;
			}
		}
	}
	int n, tmp, ans = 0;
	cin >> n;
	while (n--) {
		cin >> tmp;
		if (prime[tmp] == false) ans += 1;
	}
	cout << ans;
	return 0;
}
