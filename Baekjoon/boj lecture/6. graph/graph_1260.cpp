#include<iostream>
using namespace std;
bool check[1001], check2[1001];
int graph[1001][1001];
void dfs (int _s, int _n) {
	check[_s] = true;
	cout << _s << ' ';
	for (int i=1; i<=_n; i++) {
		if (graph[_s][i] == true && check[i] == false) {
			dfs(i, _n);
		}
	}
}
// 모든 가중치가 1이라고 할 때 bfs는 최단거리를 찾는 알고리즘임 
void bfs (int _s, int _n) {
	check[_s] = true;
	cout << _s << ' ';
	for (int i=1; i<=_n; i++) {
		
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, v;
	cin >> n >> m >> v;
	for (int i=1; i<=m; i++) {
		int j, k;
		cin >> j >> k;
		graph[j][k] = graph[k][j] = true;
	}
	dfs(v, n);
	cout << endl;
	bfs(v, n);
	return 0;
}
