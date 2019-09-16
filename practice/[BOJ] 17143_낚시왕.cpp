#include <iostream>
#include <cstring>
using namespace std;

typedef struct shark {
	int s, d, z;
	shark() {}
	shark(int s, int d, int z) : s(s), d(d), z(z) {}
} shark;

int row[] = {0, -1, 1, 0, 0};
int col[] = {0, 0, 0, 1, -1};
shark board[101][101];
shark tmp[101][101];
int r, c, m, fisher = 0, ans = 0;

void catch_shark() {
	for (int i=1; i<=r; i++) {
		if (board[i][fisher].z > 0) {
			ans += board[i][fisher].z;
			board[i][fisher].z = 0;
			return;
		}
	}
}

void move_shark() {
	memset(tmp, 0, sizeof(tmp));
	
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (board[i][j].z > 0) {	// 움직일 상어를 찾음 
				int s = board[i][j].s;	// 속력 
				int d = board[i][j].d;	// 이동 방향 
				int z = board[i][j].z; 	// 크기 
				
				if (d <= 2) {			// 상, 하 
					s %= 2*(r-1);		// 왕복해서 현재 위치, 방향으로
					int curr = i;
					
					while (s--) {
						if ((curr == 1 && d == 1) || (curr == r && d == 2)) d = 3 - d;
						curr += row[d];
					}
					
					if (tmp[curr][j].z < board[i][j].z) {
						tmp[curr][j] = board[i][j];
						tmp[curr][j].d = d;
						board[i][j].z = 0;
					}
				} else {				// 좌, 우 
					s %= 2*(c-1);		// 왕복해서 현재 위치, 방향으로 
					int curr = j;
					
					while (s--) {
						if ((curr == 1 && d == 4) || (curr == c && d == 3)) d = 7 - d;
						curr += col[d];
					}
					
					if (tmp[i][curr].z < board[i][j].z) {
						tmp[i][curr] = board[i][j];
						tmp[i][curr].d = d;
						board[i][j].z = 0;
					}
				}
			}
		}
	}
	
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

int main() {
	cin >> r >> c >> m;
	
	for (int i=0; i<m; i++) {
		int x, y, s, d, z;	cin >> x >> y >> s >> d >> z;
		shark input(s, d, z);
		board[x][y] = input;
	}
	
	for (int i=1; i<c+1; i++) {
		fisher += 1;
		catch_shark();
		move_shark();
	}
	
	cout << ans << '\n';
	
	return 0;
}
