#include <cstdio>
#include <queue>

using namespace std;

typedef struct log {
	int r, c, s;
	log() {}
	log(int r, int c, int s) : r(r), c(c), s(s) {}
} log;

int n, br, bc, bs, er, ec, es;
char input[50][50];
int land[50][50][2];
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};

int main() {
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		scanf("%s", &input[i]);
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (input[i][j] == 'B') {
				if (input[i+1][j] == 'B' && br == 0 && bc == 0) br = i+1, bc = j, bs = 1;
				else if (input[i][j+1] == 'B' && br == 0 && bc == 0) br = i, bc = j+1, bs = 0;
			} else if (input[i][j] == 'E') {
				if (input[i+1][j] == 'E' && er == 0 && ec == 0) er = i+1, ec = j, es = 1;
				else if (input[i][j+1] == 'E' && er == 0 && ec == 0) er = i, ec = j+1, es = 0;
			}
		}
	}
		
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (input[i][j] == 'B' || input [i][j] == 'E') input[i][j] = '0';
		}
	}
	
	queue<log> q;
	
	q.push(log(br, bc, bs));
	
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int s = q.front().s;
		
		q.pop();
		// turn
		bool flag = false;
		
		for (int i=-1; i<=1; i++) {
			for (int j=-1; j<=1; j++) {
				if (0 > r+i || r+i >= n || 0 > c+j || c+j >= n || input[r+i][c+j] == '1') flag = true;
			}
		}
		
		if (!flag) {
			if (land[r][c][1-s] > land[r][c][s] + 1 || land[r][c][1-s] == 0) {
				q.push(log(r, c, 1-s));
				land[r][c][1-s] = land[r][c][s] + 1;
			}
		}
		// right, down, left, up
		for (int i=0; i<4; i++) {
			int nr = r + row[i];
			int nc = c + col[i];
			
			if (s <= nr && nr < n - s && 1 - s <= nc && nc < n - 1 + s) {
				if (s == 0) {
					if (i % 2 == 0) {	// right, left
						if (input[r][c+(1-i)*2] == '0') {
							if (land[nr][nc][s] == 0 || land[nr][nc][s] > land[r][c][s] + 1) {
								q.push(log(nr, nc, s));
								land[nr][nc][s] = land[r][c][s] + 1;
							}
						}
					} else {			// up, down
						if (input[r+2-i][c-1] == '0' && input[r+2-i][c] == '0' && input[r+2-i][c+1] == '0') {
							if (land[nr][nc][s] == 0 || land[nr][nc][s] > land[r][c][s] + 1) {
								q.push(log(nr, nc, s));
								land[nr][nc][s] = land[r][c][s] + 1;
							}
						}
					}
				} else if (s == 1) {
					if (i % 2 == 0) {	// right, left
						if (input[r-1][c+s-i] == '0' && input[r][c+s-i] == '0' && input[r+1][c+s-i] == '0') {
							if (land[nr][nc][s] == 0 || land[nr][nc][s] > land[r][c][s] + 1) {
								q.push(log(nr, nc, s));
								land[nr][nc][s] = land[r][c][s] + 1;
							}
						}
					} else {			// up, down
						if (input[r+(2-i)*2][c] == '0') {
							if (land[nr][nc][s] == 0 || land[nr][nc][s] > land[r][c][s] + 1) {
								q.push(log(nr, nc, s));
								land[nr][nc][s] = land[r][c][s] + 1;
							}
						}
					}
				}
			}
		}
	}
	
	printf("%d\n", land[er][ec][es]);
	
	return 0;
}
