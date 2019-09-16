#include <iostream>
#include <queue>
#define P pair<int, int>
#define D pair<int, char>
using namespace std;
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};
int map[100][100];
queue<D> dir;
queue<P> snake;
void show(int n, int t, int r, int c) {
	cout << "############# [t = " << t << "]\n";
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == r && j == c) cout << "@ ";
			else cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}
int main() {
	map[0][0] = 2;
	int n, k;	cin >> n >> k;
	for (int i=0; i<k; i++) {
		int r, c;	cin >> r >> c;
		map[r-1][c-1] = 1;
	}
	int l;	cin >> l;
	for (int i=0; i<l; i++) {
		int t;
		char d;
		cin >> t >> d;
		dir.push(P(t, d));
	}
	snake.push(P(0, 0));
	int d = 0, t = 0, cr = 0, cc = 0;
	int next = dir.front().first;
	char turn = dir.front().second;
	dir.pop();
//	show(n, 0, 0, 0);
	while (true) {
		if (t == next) {
			if (turn == 'D') d = (d+1) % 4;
			else {
				d -= 1;
				if (d < 0) d = 3;
			}
			if (!dir.empty()) {
				next = dir.front().first;
				turn = dir.front().second;
				dir.pop();
			} else {
				next = 0;
			}
		}
		int nr = cr + row[d];
		int nc = cc + col[d];
		if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr][nc] == 2) {
			t += 1;
			break;
		}
		if (map[nr][nc] == 1) {
			map[nr][nc] = 2;
		} else if (map[nr][nc] == 0) {
			map[snake.front().first][snake.front().second] = 0;
			snake.pop();
			map[nr][nc] = 2;
		}
		snake.push(P(nr, nc));
		cr = nr, cc = nc;
//		show(n, t, cr, cc);
		t += 1;
	}
	cout << t << '\n';
	return 0;
}
