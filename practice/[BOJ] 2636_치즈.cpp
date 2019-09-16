/*
	접근 방법
	1. 치즈를 기준으로 구멍을 찾으면 내부에서 잘못된 구멍을 선택함
	2. 따라서 치즈 바깥의 공백을 기준으로 구멍을 선택
	3. 문제에서 가장 바깥 테두리는 비어있다고 제시했으므로 (0, 0)은 항상 비어있음을 이용
	4. 매 반복마다 (0, 0)부터 공기중에 접촉된 모든 부분을 찾아 구멍으로 판단 및 지우기
*/
#include <iostream>
#include <cstring>

using namespace std;

int row[] = {0, 0, -1, 1}; 
int col[] = {-1, 1, 0, 0};
int cheese[102][102];
bool check[102][102];
bool tmp[102][102];
int r, c;

void fill(int sr, int sc) {
	tmp[sr][sc] = true;
	cheese[sr][sc] = 2;
	for (int i=0; i<4; i++) {
		int nr = sr + row[i];
		int nc = sc + col[i];
		if (0 <= nr && nr <= r+1 && 0 <= nc && nc <= c+1) {
			if (!tmp[nr][nc] && cheese[nr][nc] != 1) fill(nr, nc);
		}
	}
}

int find() {
	int cnt = 0;
	
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (cheese[i][j] == 2) {
				for (int k=0; k<4; k++) {
					int nr = i + row[k];
					int nc = j + col[k];
					if (1 <= nr && nr <= r && 1 <= nc && nc <= c) {
						if (!check[nr][nc] && cheese[nr][nc] == 1) {
							check[nr][nc] = true;
							cnt += 1;
						}
					}
				}
			}
		}
	}
	
	return cnt;
}

void meltdown() {
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (check[i][j]) {
				cheese[i][j] = 0;
				check[i][j] = false;
			}
		}
	}
}

bool done() {
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			if (cheese[i][j] == 1) return false;
		}
	}
	return true;
}

int main() {
	cin >> r >> c;
	
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			cin >> cheese[i][j];
		}
	}
	
	int num, time = 0;
	
	do {
		memset(tmp, false, sizeof(tmp));
		fill(0, 0);
		num = find();
		meltdown();
		time += 1;
	} while (!done());

	cout << time << '\n' << num << '\n';

	return 0;
}
