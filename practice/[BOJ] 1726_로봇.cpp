#include <iostream>
#include <queue>

using namespace std;

struct info {
	int r, c, d;
	info() {}
	info(int r, int c, int d) : r(r), c(c), d(d) {}	
};

int n, m, sr, sc, sd, er, ec, ed, ans;
int map[101][101];
int factory[101][101][5];
int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};

void show() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			for (int k=0; k<5; k++) {
				if (map[i][j] == 1) cout << "==";
				else cout << factory[i][j][k] << "/";
			}
			cout << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void bfs() {
	queue<info> q;
	q.push(info(sr, sc, sd));
	factory[sr][sc][sd] = 1;
	while (!q.empty()) {
		show();
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();
		for (int i=1; i<=3; i++) {
			bool flag = true;
			int nr = r + dr[d] * i;
			int nc = c + dc[d] * i;
			if (1 > nr || nr > n || 1 > nc || nc > m) continue;
			for (int j=1; j<=i; j++) if (map[r + dr[d] * j][c + dc[d] * j] == 1) flag = false;
			if (!flag) continue;
			if (factory[nr][nc][d] == 0 || factory[nr][nc][d] > factory[r][c][d] + 1) {
				factory[nr][nc][d] = factory[r][c][d] + 1;
				q.push(info(nr, nc, d));
			}
		}
		for (int i=1; i<=2; i++) {
			int nd = (d + i + d % 2) % 4;
			if (nd == 0) nd = 4;
			if (factory[r][c][nd] == 0 || factory[r][c][nd] > factory[r][c][d] + 1) {
				factory[r][c][nd] = factory[r][c][d] + 1;
				q.push(info(r, c, nd));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> sr >> sc >> sd >> er >> ec >> ed;
	
	bfs();
	
	cout << factory[er][ec][ed] - 1 << '\n';
	
	return 0;
}
