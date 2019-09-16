#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;
int a[50][50];
int check[50][50];
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};
int r, c, gr, gc;
int w_count = 0, g_count = 0;
queue<P> gq, wq;
void bfs() {
	while (!gq.empty()) {
		// water
		int cnt = 0;
		for (int k=0; k<w_count; k++) {
			int cur_wr = wq.front().first;
			int cur_wc = wq.front().second;
			wq.pop();
			for (int i=0; i<4; i++) {
				int new_wr = cur_wr + row[i];
				int new_wc = cur_wc + col[i];
				if (0 <= new_wr && new_wr < r && 0 <= new_wc && new_wc < c) {
					if (!(new_wr == gr && new_wc == gc) && !check[new_wr][new_wc] && a[new_wr][new_wc] >= 0) {
						wq.push(P(new_wr, new_wc));
						check[new_wr][new_wc] = true;
						cnt += 1;
					}
				}
			}
		}
		w_count = cnt;
		// hedgedog
		cnt = 0;
		for (int k=0; k<g_count; k++) {
			int cur_gr = gq.front().first;
			int cur_gc = gq.front().second;
			gq.pop();
			if (cur_gr == gr && cur_gc == gc) {
				printf("%d\n", a[gr][gc] - 1);
				return;
			}
			for (int i=0; i<4; i++) {
				int new_gr = cur_gr + row[i];
				int new_gc = cur_gc + col[i];
				if (0 <= new_gr && new_gr < r && 0 <= new_gc && new_gc < c) {
					if (a[new_gr][new_gc] == 0 && !check[new_gr][new_gc]) {
						gq.push(P(new_gr, new_gc));
						a[new_gr][new_gc] = a[cur_gr][cur_gc] + 1;
						cnt += 1;
					}
				}
			}
		}
		g_count = cnt;
	}
	printf("KAKTUS\n");
	return;
}
int main() {
	cin >> r >> c;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			char tmp;	cin >> tmp;
			if (tmp == 'D') { gr = i; gc = j; a[i][j] = 0; }
			else if (tmp == 'X') a[i][j] = -2;
			else if (tmp == '*') a[i][j] = -1;
			else if (tmp == '.') a[i][j] = 0; 
			else a[i][j] = 1;
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (a[i][j] == -1) {
				wq.push(P(i, j));
				check[i][j] = true;
				w_count += 1;
			} else if (a[i][j] == 1) {
				gq.push(P(i, j));
				g_count += 1;
			}
		}
	}
	bfs();
	return 0;
}
