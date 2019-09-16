#include <iostream>
using namespace std;
const int MAX = 10000000;
int minFactor[MAX+1];
int solve(int x) {
	int cnt = 0;
	while (x > 1) {
		x /= minFactor[x];
		cnt += 2;
	}
	cout << cnt << '\n';
	return cnt;
}
int main() {
	minFactor[0] = minFactor[1] = -1;
	for (int i=2; i<=MAX; i++) minFactor[i] = i;
	for (int i=2; i*i<=MAX; i++) {
		if (minFactor[i] == i) {
			for (int j=i*i; j<=MAX; j+=i) {
				if (minFactor[j] == j) {
					minFactor[j] = i;
				}
			}
		}
	}
	int t;	cin >> t;
	while (t--) {
		int n, lo, hi;	cin >> n >> lo >> hi;
		int ans = 0;
		for (int i=lo; i<=hi; i++) if (solve(i) == n) ans++;
		cout << ans << '\n';
	}
	return 0;
}
