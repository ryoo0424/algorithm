#include <iostream>
#include <queue>
using namespace std;
int a[1000001];
int main() {
	int f, s, g, u, d;	cin >> f >> s >> g >> u >> d; 
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int now = q.front();
		if (now == g) return cout << a[now], 0;
		q.pop();
		int up = now + u;
		int down = now - d;
		if (1 <= up && up <= f) if (!a[up]) { a[up] = a[now] + 1; q.push(up); }
		if (1 <= down && down <= f) if (!a[down]) { a[down] = a[now] + 1; q.push(down); }
	}
	puts("use the stairs");
	return 0;
}
