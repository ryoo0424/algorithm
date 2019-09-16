#include <iostream>
#include <queue>
#include <cstring>

#define P pair<int, int>

using namespace std;

int bfs(int a[][8], int n, int max) {
	int row[] = {0, 0, -1, 1};
	int col[] = {-1, 1, 0, 0};
	int ret = 0;
	
	queue<P> q;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (a[i][j] < max) continue;
			
			int tmp [8][8] = {0, };
			int length = 0;
			
			q.push(P(i, j));
			tmp[i][j] = 1;
			
			while (!q.empty()) {				
				int r = q.front().first;
				int c = q.front().second;
				
				q.pop();
				
				if (tmp[r][c] > length) length = tmp[r][c];
				
				for (int x=0; x<4; x++) {
					int nr = r + row[x];
					int nc = c + col[x];
					
					if (0 <= nr && nr < n && 0 <= nc && nc < n) {
						if (a[r][c] > a[nr][nc]) {
							q.push(P(nr, nc));
							tmp[nr][nc] = tmp[r][c] + 1;
						}
					}
				}
			}
			
			if (length > ret) ret = length;
		}
	}
	
	return ret;
}

int main() {
	int map[8][8];
	int tmp[8][8];
	int t;	cin >> t;
	
	for (int x=1; x<=t; x++) {
		int ans = 0, max = 0;;
		int n, k;	cin >> n >> k;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> map[i][j];
				tmp[i][j] = map[i][j];
				if (map[i][j] > max) max = map[i][j];
			}
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int sum = 0, before = tmp[i][j];
				
				for (int h=0; h<=k; h++) {
					sum = bfs(tmp, n, max);
					if (ans < sum) ans = sum;
					tmp[i][j] -= 1;
					if (tmp[i][j] < 0) break;
				}
				
				tmp[i][j] = before;
			}
		}
		
		cout << "#" << x << " " << ans << '\n';
	}
	
	return 0;
}
