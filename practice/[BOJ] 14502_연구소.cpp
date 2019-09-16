#include <cstdio>
#include <cstring>
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};
bool check[8][8];
int map[8][8];
int order[64];
int n, m;
void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}
bool permutation() {
	int i = n*m-1, j = n*m-1;
	while (order[i-1] >= order[i]) i--;
	if (i <= 0) return false;
	while (order[i-1] >= order[j]) j--;
	swap(order[i-1], order[j]);
	j = n*m-1;
	while (i < j) swap(order[i++], order[j--]);
	return true;
}
void dfs(int r, int c) {
	check[r][c] = true;
	for (int i=0; i<4; i++) {
		int nr = r + row[i];
		int nc = c + col[i];
		if (0 <= nr && nr < n && 0 <= nc && nc < m) {
			if (!check[nr][nc] && map[nr][nc] == 0) dfs(nr, nc);
		}
	}
}
int count() {
	int sum = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!check[i][j] && map[i][j] == 0) sum += 1;
		}
	}
	return sum;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	order[n*m-1] = order[n*m-2] = order[n*m-3] = 1;
	int ans = 0;
	do {
		bool flag = false;
		for (int i=0; i<n*m; i++) if (order[i] == 1) if (map[i/m][i%m] != 0) flag = true;
		if (flag) continue;
		for (int i=0; i<n*m; i++) if (order[i] == 1) map[i/m][i%m] = 1;
		memset(check, false, sizeof(check));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (map[i][j] == 2 && !check[i][j]) dfs(i, j);
			}
		}
		int result = count();
		if (result > ans) ans = result;
		for (int i=0; i<n*m; i++) if (order[i] == 1) map[i/m][i%m] = 0;
	} while (permutation());
	printf("%d\n", ans);
	return 0;
}
