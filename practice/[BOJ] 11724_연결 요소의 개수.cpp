#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check[1001];
vector<int> v[1001];
queue<int> q;
void bfs() {
	while (!q.empty()) {
		int now = q.front();
		check[now] = true;
		q.pop();
		for (int i=0; i<v[now].size(); i++) {
			int next = v[now][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m;	cin >> n >> m;
	int ans = 0;
	for (int i=0; i<m; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1; i<=n; i++) {
		if (!check[i]) {
			q.push(i);
			bfs();
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
