#include <cstdio>
#include <algorithm>
#include <queue>

#define P pair<int, int>

using namespace std;

char a[5][5];
int order[25];
bool check[5][5];
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};
int ans = 0;

bool go() {
	queue<P> q;
	int cnt = 0;
	bool visit[5][5] = {false, };
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			if (check[i][j]) {
				q.push(P(i, j));
				visit[i][j] = true;
				cnt += 1;
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					for (int k=0; k<4; k++) {
						int nr = r + row[k];
						int nc = c + col[k];
						if (0 <= nr && nr < 5 && 0 <= nc && nc < 5) {
							if (check[nr][nc] && !visit[nr][nc]) {
								q.push(P(nr, nc));
								visit[nr][nc] = true;
								cnt += 1;
							}
						}
					}
				}
				if (cnt == 7) return true;
				else return false;
			}
		}
	}
}

int main() {
	for (int i=0; i<5; i++) for (int j=0; j<5; j++) scanf(" %c", &a[i][j]);
	for (int i=18; i<25; i++) order[i] = 1;
		
	do {
		int cnt = 0;
		for (int i=0; i<25; i++) {
			if (order[i]) {
				check[i/5][i%5] = true;
				if (a[i/5][i%5] == 'S') cnt += 1;
			} else check[i/5][i%5] = false;
		}
		
		if (cnt < 4) continue;
		
		if (go()) {
			puts("");
			for (int i=0; i<5; i++) {
				for (int j=0; j<5; j++) {
					printf("%d ", check[i][j]);
				}
				puts("");
			}
				
			ans += 1;
		}
	} while (next_permutation(order, order+25));
	
	printf("%d\n", ans);
	
	return 0;
}
