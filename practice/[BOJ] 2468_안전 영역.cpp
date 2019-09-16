#include <iostream>
#include <cstring> 
#include <queue>
using namespace std;

#define P pair<int, int>
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};
int area[100][100];
bool check[100][100];
bool height[101];
int n, ans = 0;

void show() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << check[i][j] << " ";
		}
		cout << '\n';
	}
}

void bfs(int height, int r, int c) {
	queue<P> q;
	q.push(P(r, c));
	check[r][c] = true;
	
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int nr = cr + row[i];
			int nc = cc + col[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < n) {
				if (!check[nr][nc] && area[nr][nc] >= height) {
					q.push(P(nr, nc));
					check[nr][nc] = true;
				}
			}
		}
	}
}

int main() {
	int high = 0, low = 200;
	
	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> area[i][j];
			if (!height[area[i][j]]) {
				height[area[i][j]] = true;
				if (area[i][j] > high) high = area[i][j];
				if (area[i][j] < low) low = area[i][j];
			}
		}
	}
	
	for (int i=low; i<=high; i++) {
		if (height[i]) {
//			cout << "height = " << i << '\n';
			memset(check, false, sizeof(check));
			int cnt = 0;
			for (int x=0; x<n; x++) {
				for (int y=0; y<n; y++) {
					if (!check[x][y] && area[x][y] >= i) {
						bfs(i, x, y);
						cnt += 1;
					}
				}
			}
//			show();
//			cout << "cnt = " << cnt << "\n\n";
			if (ans < cnt) ans = cnt;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
