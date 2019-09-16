#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> a[1001];
bool check[1001];
queue<int> q;
void dfs(int s) {
	check[s] = true;
	cout << s << " ";
	for (int i=0; i<a[s].size(); i++) {
		int next = a[s][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}
void bfs(int s) {
	while (!q.empty())  {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i=0; i<a[now].size(); i++) {
			int next = a[now][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m, s;	cin >> n >> m >> s;
	for (int i=1; i<=m; i++) {
		int u, v;	cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
 }
	for (int i=1; i<=n; i++) sort(a[i].begin(), a[i].end());
	dfs(s);
	cout << '\n';
	memset(check, false, sizeof(check));
	q.push(s);
	check[s] = true;
	bfs(s);
	return 0;
}
