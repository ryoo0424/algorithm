#include <iostream>
#define P pair<int, int>
using namespace std;
int n, ans = 0;
P a[8];
int result() {
	int ret = 0;
	for (int i=0; i<n; i++) if (a[i].first <= 0) ret += 1;
	return ret;
}
void go(int x) {
	if (x == n) {
		ans = max(ans, result());
		return;
	}

	for (int i=0; i<n; i++) {
		if (i != x) {
			int currD = a[x].first;
			int currW = a[x].second;
			int nextD = a[i].first;
			int nextW = a[i].second;
			
			if (currD <= 0) {
				go(x+1);
				return;
			}
			
			if (nextD <= 0) {
				if (i == n-2) {
					ans = max(ans, result());
					return;
				}
				else continue;
			}
			
			a[x].first = currD - nextW;
			a[i].first = nextD - currW;
			go(x+1);
			a[x].first = currD;
			a[i].first = nextD;
		}
	}
}
int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
	go(0);
	cout << ans << '\n';
	return 0;
}
