#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200001;
int a[MAX];
bool c[MAX];
int main() {
	int n, k;	cin >> n >> k;
	c[n] = true;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		// cout << "(" << q.front() << ", " << a[q.front()] << ")\n";
		int now = q.front();
		q.pop();
		if (now == k) break;
		int next = now*2;
		
		while (next <= MAX && !c[next]) {
			q.push(next);
			a[next] = a[next/2];
			c[next] = true;
			next *= 2;
		}
		if (now+1 <= MAX && !c[now+1]) {
			q.push(now+1);
			a[now+1] = a[now]+1;
			c[now+1] = true;
		}
		if (now-1 >= 0 && !c[now-1]) {
			q.push(now-1);
			a[now-1] = a[now]+1;
			c[now-1] = true;
		}
	}
	cout << a[k];
	return 0;
}
