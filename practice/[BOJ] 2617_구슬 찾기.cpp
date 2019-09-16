#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void dfs(int x, vector<int> bead[], bool check[], int result[], int origin) {
	check[x] = true;
	for (int i=0; i<bead[x].size(); i++) {
		if (!check[bead[x][i]]) {
			result[origin] += 1;
			dfs(bead[x][i], bead, check, result, origin);
		}
	}
}
int main() {
	vector<int> bead_h[100], bead_l[100];
	bool check[100], done[100] = {false};
	int heavier[100] = {0};
	int lighter[100] = {0};
	int ans = 0, n, m;	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int heavy, light;	cin >> heavy >> light;
		bead_h[heavy].push_back(light);
		bead_l[light].push_back(heavy);
	}
	for (int i=1; i<=n; i++) {
		if (done[i]) continue;
		memset(check, false, sizeof(check));
		dfs(i, bead_h, check, heavier, i);
		if (heavier[i] > n/2) done[i] = true;
	}
	for (int i=1; i<=n; i++) {
		if (done[i]) continue;
		memset(check, false, sizeof(check));
		dfs(i, bead_l, check, lighter, i);
		if (lighter[i] > n/2) done[i] = true;
	}
	for (int i=1; i<=n; i++) cout << heavier[i] << " "; cout << '\n';
	for (int i=1; i<=n; i++) cout << lighter[i] << " "; cout << '\n';
	for (int i=1; i<=n; i++) if (heavier[i] > n/2 || lighter[i] > n/2) ans += 1;
	cout << ans << '\n';
	return 0;
}
