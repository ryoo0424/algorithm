#include <iostream>
using namespace std;
int n, m, a[8];
void go(int val, int cnt) {
	a[cnt] = val;
	if (cnt == m) {
		for (int i=1; i<=cnt; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i=1; i<=n; i++) go(i, cnt+1);
}
int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) go(i, 1);
	return 0;
}
