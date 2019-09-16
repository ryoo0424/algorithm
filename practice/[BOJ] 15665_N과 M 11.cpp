#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[10], ans[10];
bool check[10];
void go(int cnt) {
	if (cnt == m) {
		for (int i=1; i<=m; i++) cout << ans[i] << " ";
		cout << '\n';
		return;
	}
	bool used[10001] = {false, };
	for (int i=1; i<=n; i++) {
		if (!check[i] && !used[a[i]]) {
			ans[cnt+1] = a[i];
			//check[i] = true;
			used[a[i]] = true;
			go(cnt+1);
			//check[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	go(0);
	return 0;
}
