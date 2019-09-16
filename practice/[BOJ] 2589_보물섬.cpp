#include <iostream>
#include <queue>
#include <cstring>
#define P pair<int, int>
using namespace std;
int R, C, ans;
char map[50][50];
int check[50][50];
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};
void bfs(int r, int c) {
	int sum = 0;
	queue<P> q;
	q.push(P(r, c));
	check[r][c] = 1;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		if (check[cr][cc] > sum) sum = check[cr][cc];
		for (int i=0; i<4; i++) {
			int nr = cr + row[i];
			int nc = cc + col[i];
			if (0 <= nr && nr < R && 0 <= nc && nc < C) {
				if (map[nr][nc] == 'L' && check[nr][nc] == 0) {
					check[nr][nc] = check[cr][cc] + 1;
					q.push(P(nr, nc));
				}
			}
		}
	}
	if (sum > ans) ans = sum;
}
int main() {
	cin >> R >> C;
	for (int i=0; i<R; i++) cin >> map[i];
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			memset(check, 0, sizeof(check));
			if (map[i][j] == 'L' && check[i][j] == 0) bfs(i, j);
		}
	}
	cout << ans-1 << '\n';
	return 0;
}
