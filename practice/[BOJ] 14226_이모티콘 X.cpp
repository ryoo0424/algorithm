#include <iostream>
#include <queue>
using namespace std;
int check[10001];
int cnt = 0;
int ans;
int s;
void go(int num, int time) {
	if (num < 1 || num > 3000) return;
	if (check[num]) return;
	check[num] = time;
	cnt += 1;
	if (cnt == s) {
		ans = time;
		return;
	}
	go(num * 2, time + 2);
	go(num - 1, time + 1);
}
int main() {
	cin >> s;
	go(1, 0);
	// cout << ans << '\n';
	return 0;
}
