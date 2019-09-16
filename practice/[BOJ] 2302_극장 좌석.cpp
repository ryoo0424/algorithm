/*
	접근 방법
	1. d[i] = d[i-1] + d[i-2]
*/
#include <iostream>
#include <queue>

using namespace std;

int n, m, cnt, ans = 1;
int d[41];
queue<int> q;

int main() {
	cin >> n >> m;
	
	d[1] = 1, d[2] = 2;
	
	for (int i=3; i<=n; i++) d[i] = d[i-1] + d[i-2];
	
	q.push(0);
	for (int i=0; i<m; i++) {
		int vip;	cin >> vip;
		q.push(vip);
	}
	q.push(n+1);
	
	int now = q.front(), next;
	q.pop();
	
	while (!q.empty()) {
		next = q.front();
		ans *= (next - now - 1 == 0 ? 1 : d[next - now - 1]);
		now = next;
		q.pop();
	}
	
	cout << ans << '\n';
	
	return 0;
}
