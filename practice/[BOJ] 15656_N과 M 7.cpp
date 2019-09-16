#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[9], ans[9];
void go(int val, int cnt) {
	ans[cnt] = val;
	if (cnt == m) {
		for (int i=1; i<=m; i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	for (int i=1; i<=n; i++) go(a[i], cnt+1);
}
int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) go(a[i], 1);
	return 0;
}
