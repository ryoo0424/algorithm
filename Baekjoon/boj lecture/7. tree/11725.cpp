#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 100001;
vector<int> t[MAX];
bool check[MAX];
int depth[MAX];
int parent[MAX];
int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		t[u].push_back(v);
		t[v].push_back(u);
	}
	depth[1] = 0;
	check[1] = true;
	parent[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : t[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i=2; i<=n; i++) printf("%d\n", parent[i]);
	return 0;
}
