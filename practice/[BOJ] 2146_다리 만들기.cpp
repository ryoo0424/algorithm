/*
	틀렸던 부분
		- queue의 특성상 위에서부터 찾을 경우 정답보다 더 먼 거리를 출력할 수 있음!! 
*/
#include <iostream>
#include <queue>
#define P pair<int,int>

using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int map[100][100];
int check[100][100];
int n, ans = 987654321;
queue<P> q;

void show() {
	cout << '\n';
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << check[i][j] << " ";
		}
		cout << '\n';
	}
}

void coloring() {
	int cnt = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				queue<P> t;
				check[i][j] = cnt;
				t.push(P(i, j));
				while (!t.empty()) {
					int r = t.front().first;
					int c = t.front().second;
					t.pop();
					for (int k=0; k<4; k++) {
						int nr = r + dr[k];
						int nc = c + dc[k];
						if (0 <= nr && nr < n && 0 <= nc && nc < n) {
							if (map[nr][nc] == 1 && check[nr][nc] == 0) {
								check[nr][nc] = cnt;
								t.push(P(nr, nc));
							}
						}
					}
				}
				cnt += 1;
			}
		}
	}
}

void find() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (map[i][j] != 0) {
				bool shore = false;
				for (int k=0; k<4; k++) {
					int r = i + dr[k];
					int c = j + dc[k];
					if (0 <= r && r < n && 0 <= c && c < n && map[r][c] == 0) shore = true;
				}
				if (shore) q.push(P(i, j));
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < n) {
				if (map[nr][nc] == 0) {
					check[nr][nc] = check[r][c];
					map[nr][nc] = map[r][c] + 1;
					q.push(P(nr, nc));
//					show();
				} else {
					if (check[nr][nc] != check[r][c]) {
						if (ans > map[nr][nc] + map[r][c] - 2) ans = map[nr][nc] + map[r][c] - 2;
					} 
				}
			}
		}
	}
}

int main() {
	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> map[i][j];
		}
	}
	
	coloring();
	find();
	bfs();
	
	cout << ans << '\n';
	return 0;
}
