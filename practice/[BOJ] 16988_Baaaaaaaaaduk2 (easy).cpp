#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

#define P pair<int, int>

using namespace std;

int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};
int order[400];
int board[20][20];
bool check[20][20];
int n, m;

int bfs(int i, int j) {
	bool flag = false;
	int ret = 0;
	queue<P> q;
	
	check[i][j] = true;
	q.push(P(i, j));
	// find enemy group
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		
		ret += 1;
		
		q.pop();
		
		for (int k=0; k<4; k++) {
			int nr = cr + row[k];
			int nc = cc + col[k];
			
			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				if (board[nr][nc] == 0) flag = true;
				if (board[nr][nc] == 2 && !check[nr][nc]) {
					check[nr][nc] = true;
					q.push(P(nr, nc));
				}
			}
		}
	}
	// judge the group is enclosed or not
	if (!flag) return ret;
	else return 0;
}

int main() {
	int ans = 0;
	
	scanf("%d %d", &n, &m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	order[n*m-2] = order[n*m-1] = 1;
	
	do {
		P coord[2];
		int idx = 0, cnt = 0;
		
		for (int i=0; i<n*m; i++) {
			if (order[i] == 1 && board[i/m][i%m] == 0) coord[idx++] = P(i/m, i%m);
		}
		
		if (idx < 2) continue;
		
		memset(check, false, sizeof(check));
		
		board[coord[0].first][coord[0].second] = 1;
		board[coord[1].first][coord[1].second] = 1;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (board[i][j] == 2 && !check[i][j]) {
					cnt += bfs(i, j);
				}
			}
		}
		
		if (cnt > ans) ans = cnt;
		
		board[coord[0].first][coord[0].second] = 0;
		board[coord[1].first][coord[1].second] = 0;
	} while (next_permutation(order, order+n*m));
	
	printf("%d\n", ans);
	
	return 0;
}
