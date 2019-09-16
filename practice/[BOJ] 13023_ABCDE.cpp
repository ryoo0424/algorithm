#include <iostream>
#include <vector>
using namespace std;
bool ABCDE = false;
bool check[2000];
vector<int> v[2000];
void dfs(int st, int num) {
	check[st] = true;
	if (num == 5) {
		ABCDE = true;
		return;
	}
	for (int i=0; i<v[st].size(); i++) {
		int next = v[st][i];
		if (!check[next]) dfs(next, num+1);
	}
	check[st] = false;
}
int main() {
	int n, m;	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b;	cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=0; i<n; i++) {
		dfs(i, 1);
	}
	cout << ABCDE ? 1 : 0 << '\n';
	return 0;
}
