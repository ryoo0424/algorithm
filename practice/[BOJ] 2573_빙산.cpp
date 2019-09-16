/*
	접근 방법
	1. 전체 입력을 순회하면서 각 빙산이 다음 차례에 깎이게 될 높이를 계산하여 tmp에 저장
	2. 녹이기
	3. bfs를 돌려 그룹이 2개 이상 나오면 그 때의 ans를 출력
	4. 3.을 통과했는데 모든 빙산이 녹았을 경우 ans = 0을 출력 
*/
#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;

int r, c, ans;
int iceberg[300][300];
int tmp[300][300];
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};

bool impossible() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (iceberg[i][j] > 0) return false;
		}
	}
	return true;
}

void find() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			int cnt = 0;
			if (iceberg[i][j] > 0) {
				for (int k=0; k<4; k++) {
					int nr = i + row[k];
					int nc = j + col[k];
					if (0 <= nr && nr < r && 0 <= nc && nc < c && iceberg[nr][nc] == 0) cnt += 1;
				}
			}
			tmp[i][j] = cnt;
		}
	}
}

void meltdown() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (tmp[i][j] > 0) {
				iceberg[i][j] -= tmp[i][j];
				if (iceberg[i][j] < 0) iceberg[i][j] = 0;
				tmp[i][j] = 0;
			}
		}
	}
}

int bfs() {
	int cnt = 0;
	queue<P> q;
	bool check[300][300] = {false};
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (iceberg[i][j] > 0 && !check[i][j]) {
				q.push(P(i, j));
				check[i][j] = true;
				while (!q.empty()) {
					int cr = q.front().first;
					int cc = q.front().second;
					q.pop();
					for (int k=0; k<4; k++) {
						int nr = cr + row[k];
						int nc = cc + col[k];
						if (0 <= nr && nr < r && 0 <= nc && nc < c) {
							if (!check[nr][nc] && iceberg[nr][nc] > 0) {
								q.push(P(nr, nc));
								check[nr][nc] = true;
							}
						}
					}
				}
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> r >> c;
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> iceberg[i][j];
		}
	}
	
	while (true) {
		find();
		meltdown();
		ans += 1;
		if (impossible()) {
			ans = 0;
			break;
		}
		if (bfs() >= 2) break;
	}
	
	cout << ans << '\n';
	
	return 0;
}
