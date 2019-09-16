#include <iostream>
#include <queue>
#include <cstring>
#define P pair<int, int>
using namespace std;
int n, m, cnt;
P virus[10];
int a[10];
int map[50][50];
int tmp[50][50];
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};
void swap(int &x, int &y) { int tmp = x; x = y; y = tmp; }
bool permutation(int x) {
	int i = x - 1, j = x - 1;
	while (a[i-1] >= a[i]) i--;
	if (i <= 0) return false;
	while (a[i-1] >= a[j]) j--;
	swap(a[i-1], a[j]);
	j = x - 1;
	while (i < j) swap(a[i++], a[j--]);
	return true;
}
void bfs() {
	queue<P> q;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (tmp[i][j] == -1) {
				q.push(P(i, j));
				tmp[i][j] = 1;
			}
		}
	}
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int nr = r + row[i];
			int nc = c + col[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < n) {
				if (tmp[nr][nc] == 0) {
					q.push(P(nr, nc));
					tmp[nr][nc] = tmp[r][c] + 1;
				}
			}
		}
	}
}
void copy() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}
int check() {
	int ret = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (tmp[i][j] == 0) return -10;
			if (tmp[i][j] > ret) {
				bool flag = true;
				for (int k=0; k<cnt; k++) {
					if (i == virus[k].first && j == virus[k].second) flag = false;
				}
				if (flag) ret = tmp[i][j];
			}
		}
	}
	return ret - 1;
}
int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus[cnt++] = P(i, j);
				map[i][j] = 0;
			}
		}
	}
	for (int i=1; i<=m; i++) a[cnt-i] = 1;
	int ans = 987654321;
	do {
		for (int i=0; i<cnt; i++) {
			if (a[i] == 1) map[virus[i].first][virus[i].second] = -1;
		}
		copy();
		bfs();
		int result = check();
		if (result != -10 && result < ans) ans = result;
		for (int i=0; i<cnt; i++) {
			if (a[i] == 1) map[virus[i].first][virus[i].second] = 0;
		}
	} while (permutation(cnt));
	cout << (ans == 987654321 ? -1 : ans) << '\n';
	return 0;
}
