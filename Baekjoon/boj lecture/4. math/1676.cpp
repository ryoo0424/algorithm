#include<iostream>
using namespace std;
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		if (i % 5 == 0) ans += 1;
		if (i % 25 == 0) ans += 1;
		if (i % 125 == 0) ans += 1;
	}
	cout << ans;
	return 0;
}
