#include<iostream>
#include<queue>
using namespace std;
int maze[101][101];
bool check[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	queue< pair<int,int> > q;
	int row[4] = {0, 1, 0, -1}, col[4] = {1, 0, -1, 0};
	int n, m;
	cin >> n >> m;
	/*
	for (int i=1; i<=n; i++) {
		char tmp[100];
		cin >> tmp;
		for (int j=0; j<m; j++) maze[i][j+1] = tmp[j] - '0';
	}
	아래처럼 받는 연습 해보기 
	*/
	for (int i=1; i<=n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%1d", &maze[i][j+1]);
		}
	}
	check[1][1] = true;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		if (x == n && y == m) break;
		q.pop();
		for (int i=0; i<4; i++) {
			int dx = x + row[i], dy = y + col[i];
			if (dx >= 1 && dx <= n && dy >= 1 && dy <= m) {
				if (maze[dx][dy] != 0 && check[dx][dy] == false) {
					q.push(make_pair(dx, dy));
					check[dx][dy] = true;
					maze[dx][dy] = maze[x][y] + 1;
				}
			}
		}
	}
	cout << maze[n][m];
	return 0;
}
