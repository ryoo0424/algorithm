#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[10];
bool c[10];
void go(int val, int cnt) {
	a[cnt] = val;
	if (cnt == m) {
		for (int i=1; i<cnt; i++) if (a[i] > a[i+1]) return;
		for (int i=1; i<=cnt; i++) cout << a[i] << " ";
		cout << '\n';
		return;
	}
	c[val] = true;
	for (int i=1; i<=n; i++) {
		if (!c[i]) {
			go(i, cnt+1);
		}
	}
	c[val] = false;
}
int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) go(i, 1);
	return 0;
}
