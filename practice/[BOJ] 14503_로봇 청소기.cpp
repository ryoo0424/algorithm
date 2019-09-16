#include <iostream>

using namespace std;

int rotate(int d) {
	d = d - 1;
	if (d < 0) d = 3;
	return d;
}

int main() {
	int row[] = {-1, 0, 1, 0};
	int col[] = {0, 1, 0, -1};
	int map[50][50] = {0};
	bool check[50][50] = {false};
	int n, m, r, c, d;

	cin >> n >> m >> r >> c >> d;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}
	
	do {
//		cout << '\n';
//		for (int i=0; i<n; i++) {
//			for (int j=0; j<m; j++) {
//				if (i == r && j == c) cout << "@ ";
//				else if (check[i][j]) cout << "X ";
//				else cout << map[i][j] << " ";
//			}
//			cout << '\n';
//		}
//		
//		cout << "(" << r << ", " << c << ")\n";
//		
		bool flag = false;
		check[r][c] = true;
		int nd = d;
		
		for (int i=0; i<4; i++) {
			nd = rotate(nd);
			
			if (0 <= r+row[nd] && r+row[nd] < n && 0 <= c+col[nd] && c+col[nd] < m) {
				if (map[r+row[nd]][c+col[nd]] == 0 && !check[r+row[nd]][c+col[nd]]) {
					r += row[nd];
					c += col[nd];
					d = nd;
					flag = true;
					break;
				}
			}
		}
		
		if (!flag) {
			int nr = r + row[4-d-((d+1)%2)*2];
			int nc = c + col[4-d-((d+1)%2)*2];
			
			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				if (map[nr][nc] != 1) {
					r = nr;
					c = nc;
				} else {
					break;
				}
			} else {
				break;
			}
		}
	} while (true);
	
	int ans = 0;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (check[i][j]) ans += 1;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
